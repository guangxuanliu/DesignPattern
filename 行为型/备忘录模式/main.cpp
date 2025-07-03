#include <iostream>
#include <string>
#include <stack>

// ======= Memento（备忘录） =======
class Memento
{
public:
    Memento(const std::string &state) : state_(state) {}
    std::string getState() const { return state_; }

private:
    std::string state_; // 不提供修改接口
};

// ======= Originator（发起人） =======
class TextEditor
{
public:
    void type(const std::string &text)
    {
        content_ += text;
    }

    void show() const
    {
        std::cout << "Editor Content: " << content_ << "\n";
    }

    std::shared_ptr<Memento> save() const
    {
        return std::make_shared<Memento>(content_);
    }

    void restore(std::shared_ptr<Memento> memento)
    {
        if (memento)
            content_ = memento->getState();
    }

private:
    std::string content_;
};

// ======= Caretaker（负责人） =======
class History
{
public:
    void backup(std::shared_ptr<Memento> memento)
    {
        history_.push(memento);
    }

    std::shared_ptr<Memento> undo()
    {
        if (!history_.empty())
        {
            auto top = history_.top();
            history_.pop();
            return top;
        }
        return nullptr;
    }

private:
    std::stack<std::shared_ptr<Memento>> history_;
};

// ======= 测试代码 =======
int main()
{
    TextEditor editor;
    History history;

    editor.type("Hello");
    history.backup(editor.save());

    editor.type(", world!");
    history.backup(editor.save());

    editor.type(" Let's code!");
    editor.show(); // Hello, world! Let's code!

    std::cout << "Undo...\n";
    editor.restore(history.undo());
    editor.show(); // Hello, world!

    std::cout << "Undo again...\n";
    editor.restore(history.undo());
    editor.show(); // Hello

    return 0;
}
