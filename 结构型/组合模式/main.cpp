#include <iostream>
#include <string>
#include <vector>
#include <memory>

// 抽象基类：统一接口
class FileSystemComponent
{
public:
    FileSystemComponent(const std::string &name) : name_(name) {}
    virtual void display(int indent = 0) const = 0;
    virtual ~FileSystemComponent() = default;

protected:
    std::string name_;
};

// 叶子节点：文件
class File : public FileSystemComponent
{
public:
    File(const std::string &name) : FileSystemComponent(name) {}

    void display(int indent = 0) const override
    {
        std::cout << std::string(indent, ' ') << "- File: " << name_ << "\n";
    }
};

// 组合节点：文件夹
class Directory : public FileSystemComponent
{
public:
    Directory(const std::string &name) : FileSystemComponent(name) {}

    void add(std::shared_ptr<FileSystemComponent> component)
    {
        children_.push_back(component);
    }

    void display(int indent = 0) const override
    {
        std::cout << std::string(indent, ' ') << "+ Directory: " << name_ << "\n";
        for (const auto &child : children_)
        {
            child->display(indent + 2);
        }
    }

private:
    std::vector<std::shared_ptr<FileSystemComponent>> children_;
};

// ================== 示例使用 ==================
int main()
{
    auto file1 = std::make_shared<File>("readme.txt");
    auto file2 = std::make_shared<File>("notes.docx");
    auto file3 = std::make_shared<File>("photo.jpg");

    auto subDir = std::make_shared<Directory>("Documents");
    subDir->add(file1);
    subDir->add(file2);

    auto rootDir = std::make_shared<Directory>("Root");
    rootDir->add(subDir);
    rootDir->add(file3);

    rootDir->display();

    return 0;
}
