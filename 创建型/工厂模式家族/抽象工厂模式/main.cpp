#include <iostream>
#include <memory>

// 抽象产品A：按钮
class Button
{
public:
    virtual void paint() = 0;
    virtual ~Button() = default;
};

// 抽象产品B：文本框
class TextBox
{
public:
    virtual void display() = 0;
    virtual ~TextBox() = default;
};

// 具体产品A1：Windows按钮
class WindowsButton : public Button
{
public:
    void paint() override
    {
        std::cout << "Rendering a Windows-style button.\n";
    }
};

// 具体产品B1：Windows文本框
class WindowsTextBox : public TextBox
{
public:
    void display() override
    {
        std::cout << "Displaying a Windows-style textbox.\n";
    }
};

// 具体产品A2：Mac按钮
class MacButton : public Button
{
public:
    void paint() override
    {
        std::cout << "Rendering a Mac-style button.\n";
    }
};

// 具体产品B2：Mac文本框
class MacTextBox : public TextBox
{
public:
    void display() override
    {
        std::cout << "Displaying a Mac-style textbox.\n";
    }
};

// 抽象工厂
class GUIFactory
{
public:
    virtual std::unique_ptr<Button> createButton() = 0;
    virtual std::unique_ptr<TextBox> createTextBox() = 0;
    virtual ~GUIFactory() = default;
};

// 具体工厂：Windows 风格
class WindowsFactory : public GUIFactory
{
public:
    std::unique_ptr<Button> createButton() override
    {
        return std::make_unique<WindowsButton>();
    }

    std::unique_ptr<TextBox> createTextBox() override
    {
        return std::make_unique<WindowsTextBox>();
    }
};

// 具体工厂：Mac 风格
class MacFactory : public GUIFactory
{
public:
    std::unique_ptr<Button> createButton() override
    {
        return std::make_unique<MacButton>();
    }

    std::unique_ptr<TextBox> createTextBox() override
    {
        return std::make_unique<MacTextBox>();
    }
};

// 客户端代码
void buildUI(GUIFactory &factory)
{
    auto button = factory.createButton();
    auto textbox = factory.createTextBox();

    button->paint();
    textbox->display();
}

// main 函数
int main()
{
#ifdef _WIN32
    WindowsFactory factory;
#else
    MacFactory factory;
#endif

    buildUI(factory);

    return 0;
}
