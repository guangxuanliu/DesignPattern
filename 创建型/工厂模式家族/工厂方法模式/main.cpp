#include <iostream>
#include <memory>
#include <string>

// 抽象产品：文档
class Document
{
public:
    virtual void open() = 0;
    virtual void save() = 0;
    virtual ~Document() = default;
};

// 具体产品：HTML 文档
class HtmlDocument : public Document
{
public:
    void open() override
    {
        std::cout << "Opening HTML document...\n";
    }

    void save() override
    {
        std::cout << "Saving HTML document...\n";
    }
};

// 具体产品：PDF 文档
class PdfDocument : public Document
{
public:
    void open() override
    {
        std::cout << "Opening PDF document...\n";
    }

    void save() override
    {
        std::cout << "Saving PDF document...\n";
    }
};

// 抽象工厂
class DocumentFactory
{
public:
    virtual std::unique_ptr<Document> createDocument() = 0;
    virtual ~DocumentFactory() = default;
};

// 具体工厂：HTML 文档工厂
class HtmlDocumentFactory : public DocumentFactory
{
public:
    std::unique_ptr<Document> createDocument() override
    {
        return std::make_unique<HtmlDocument>();
    }
};

// 具体工厂：PDF 文档工厂
class PdfDocumentFactory : public DocumentFactory
{
public:
    std::unique_ptr<Document> createDocument() override
    {
        return std::make_unique<PdfDocument>();
    }
};

// 客户端代码
void handleDocument(DocumentFactory &factory)
{
    auto doc = factory.createDocument();
    doc->open();
    doc->save();
}

// 测试
int main()
{
    std::cout << "--- Handling HTML Document ---\n";
    HtmlDocumentFactory htmlFactory;
    handleDocument(htmlFactory);

    std::cout << "\n--- Handling PDF Document ---\n";
    PdfDocumentFactory pdfFactory;
    handleDocument(pdfFactory);

    return 0;
}
