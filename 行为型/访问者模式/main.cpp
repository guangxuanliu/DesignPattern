#include <iostream>
#include <vector>
#include <memory>
#include <string>

// 前向声明
class File;
class Directory;

// ========== Visitor 接口 ==========
class FileSystemVisitor
{
public:
    virtual ~FileSystemVisitor() = default;
    virtual void visit(File &file) = 0;
    virtual void visit(Directory &dir) = 0;
};

// ========== Element 接口 ==========
class FileSystemElement
{
public:
    virtual ~FileSystemElement() = default;
    virtual void accept(FileSystemVisitor &visitor) = 0;
    virtual std::string name() const = 0;
};

// ========== 文件类 ==========
class File : public FileSystemElement
{
public:
    File(std::string name, int size) : name_(std::move(name)), size_(size) {}

    void accept(FileSystemVisitor &visitor) override
    {
        visitor.visit(*this);
    }

    std::string name() const override { return name_; }
    int size() const { return size_; }

private:
    std::string name_;
    int size_;
};

// ========== 目录类 ==========
class Directory : public FileSystemElement
{
public:
    Directory(std::string name) : name_(std::move(name)) {}

    void add(std::shared_ptr<FileSystemElement> element)
    {
        children_.push_back(element);
    }

    void accept(FileSystemVisitor &visitor) override
    {
        visitor.visit(*this);
    }

    std::string name() const override { return name_; }
    const std::vector<std::shared_ptr<FileSystemElement>> &children() const
    {
        return children_;
    }

private:
    std::string name_;
    std::vector<std::shared_ptr<FileSystemElement>> children_;
};

// ========== ConcreteVisitor：结构打印 ==========
class PrintVisitor : public FileSystemVisitor
{
public:
    void visit(File &file) override
    {
        printIndent();
        std::cout << "- File: " << file.name() << " (" << file.size() << "KB)\n";
    }

    void visit(Directory &dir) override
    {
        printIndent();
        std::cout << "+ Dir: " << dir.name() << "\n";
        ++indent_;
        for (const auto &child : dir.children())
        {
            child->accept(*this);
        }
        --indent_;
    }

private:
    int indent_ = 0;

    void printIndent()
    {
        for (int i = 0; i < indent_; ++i)
            std::cout << "  ";
    }
};

// ========== ConcreteVisitor：文件大小统计 ==========
class SizeVisitor : public FileSystemVisitor
{
public:
    void visit(File &file) override
    {
        totalSize_ += file.size();
    }

    void visit(Directory &dir) override
    {
        for (const auto &child : dir.children())
        {
            child->accept(*this);
        }
    }

    int getTotalSize() const { return totalSize_; }

private:
    int totalSize_ = 0;
};

// ========== 测试入口 ==========
int main()
{
    auto root = std::make_shared<Directory>("root");
    root->add(std::make_shared<File>("a.txt", 10));
    root->add(std::make_shared<File>("b.jpg", 200));

    auto subDir = std::make_shared<Directory>("sub");
    subDir->add(std::make_shared<File>("c.cpp", 50));
    root->add(subDir);

    std::cout << "[PrintVisitor]\n";
    PrintVisitor printer;
    root->accept(printer);

    std::cout << "\n[SizeVisitor]\n";
    SizeVisitor sizer;
    root->accept(sizer);
    std::cout << "Total size: " << sizer.getTotalSize() << "KB\n";

    return 0;
}
