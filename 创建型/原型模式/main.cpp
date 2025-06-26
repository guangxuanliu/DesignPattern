#include <iostream>
#include <string>
#include <unordered_map>
#include <memory>

// 抽象原型接口
class IDocument
{
public:
    virtual ~IDocument() {}
    virtual std::unique_ptr<IDocument> clone() const = 0;
    virtual void setTitle(const std::string &newTitle) = 0;
    virtual void display() const = 0;
};

// 具体文档类：纯文本
class PlainTextDocument : public IDocument
{
    std::string title;
    std::string content;

public:
    PlainTextDocument(std::string t, std::string c)
        : title(std::move(t)), content(std::move(c)) {}

    std::unique_ptr<IDocument> clone() const override
    {
        return std::make_unique<PlainTextDocument>(*this);  // 调用拷贝构造函数
    }

    void setTitle(const std::string &newTitle) override
    {
        title = newTitle;
    }

    void display() const override
    {
        std::cout << "[PlainText] Title: " << title
                  << "\nContent: " << content << "\n\n";
    }
};

// 具体文档类：富文本
class RichTextDocument : public IDocument
{
    std::string title;
    std::string content;
    std::string font;

public:
    RichTextDocument(std::string t, std::string c, std::string f)
        : title(std::move(t)), content(std::move(c)), font(std::move(f)) {}

    std::unique_ptr<IDocument> clone() const override
    {
        return std::make_unique<RichTextDocument>(*this);
    }

    void setTitle(const std::string &newTitle) override
    {
        title = newTitle;
    }

    void display() const override
    {
        std::cout << "[RichText] Title: " << title
                  << "\nContent: " << content
                  << "\nFont: " << font << "\n\n";
    }
};

// 具体文档类：表格
class SpreadsheetDocument : public IDocument
{
    std::string title;
    int rows;
    int columns;

public:
    SpreadsheetDocument(std::string t, int r, int c)
        : title(std::move(t)), rows(r), columns(c) {}

    std::unique_ptr<IDocument> clone() const override
    {
        return std::make_unique<SpreadsheetDocument>(*this);
    }

    void setTitle(const std::string &newTitle) override
    {
        title = newTitle;
    }

    void display() const override
    {
        std::cout << "[Spreadsheet] Title: " << title
                  << "\nSize: " << rows << " rows x " << columns << " cols\n\n";
    }
};

// 原型管理器
class DocumentPrototypeManager
{
    std::unordered_map<std::string, std::unique_ptr<IDocument>> prototypes;

public:
    void registerPrototype(const std::string &type, std::unique_ptr<IDocument> proto)
    {
        prototypes[type] = std::move(proto);
    }

    std::unique_ptr<IDocument> createCopy(const std::string &type, const std::string &newTitle)
    {
        if (prototypes.count(type))
        {
            auto copy = prototypes[type]->clone();
            copy->setTitle(newTitle);
            return copy;
        }
        return nullptr;
    }
};

// 客户端代码
int main()
{
    DocumentPrototypeManager manager;

    manager.registerPrototype("plain", std::make_unique<PlainTextDocument>("Template Text", "This is a text document."));
    manager.registerPrototype("rich", std::make_unique<RichTextDocument>("Template Rich", "<b>Rich Content</b>", "Arial"));
    manager.registerPrototype("sheet", std::make_unique<SpreadsheetDocument>("Template Sheet", 20, 5));

    auto doc1 = manager.createCopy("plain", "User Notes");
    auto doc2 = manager.createCopy("rich", "Project Report");
    auto doc3 = manager.createCopy("sheet", "Monthly Budget");

    doc1->display();
    doc2->display();
    doc3->display();

    return 0;
}
