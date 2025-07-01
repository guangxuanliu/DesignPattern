#include <iostream>
#include <string>
#include <memory>
#include <ctime>
#include <algorithm>

// --- 抽象组件 ---
class TextWriter
{
public:
    virtual ~TextWriter() = default;
    virtual void write(const std::string &message) = 0;
};

// --- 具体组件 ---
class ConsoleWriter : public TextWriter
{
public:
    void write(const std::string &message) override
    {
        std::cout << message << std::endl;
    }
};

// --- 装饰器基类 ---
class WriterDecorator : public TextWriter
{
protected:
    std::unique_ptr<TextWriter> writer;

public:
    WriterDecorator(std::unique_ptr<TextWriter> w) : writer(std::move(w)) {}
};

// --- 添加时间戳 ---
class TimestampDecorator : public WriterDecorator
{
public:
    TimestampDecorator(std::unique_ptr<TextWriter> w) : WriterDecorator(std::move(w)) {}

    void write(const std::string &message) override
    {
        std::time_t now = std::time(nullptr);
        char buf[100];
        std::strftime(buf, sizeof(buf), "[%Y-%m-%d %H:%M:%S] ", std::localtime(&now));
        writer->write(std::string(buf) + message);
    }
};

// --- 添加日志等级 ---
class LevelDecorator : public WriterDecorator
{
private:
    std::string level;

public:
    LevelDecorator(std::unique_ptr<TextWriter> w, const std::string &lvl)
        : WriterDecorator(std::move(w)), level(lvl) {}

    void write(const std::string &message) override
    {
        writer->write("[" + level + "] " + message);
    }
};

// --- 简单加密（反转字符串） ---
class EncryptDecorator : public WriterDecorator
{
public:
    EncryptDecorator(std::unique_ptr<TextWriter> w) : WriterDecorator(std::move(w)) {}

    void write(const std::string &message) override
    {
        std::string encrypted = message;
        std::reverse(encrypted.begin(), encrypted.end());
        writer->write(encrypted);
    }
};

// --- 客户端 ---
int main()
{
    std::cout << "=== 1. 普通输出 ===" << std::endl;
    std::unique_ptr<TextWriter> writer1 = std::make_unique<ConsoleWriter>();
    writer1->write("Hello, world!");

    std::cout << "\n=== 2. 添加时间戳 ===" << std::endl;
    std::unique_ptr<TextWriter> writer2 =
        std::make_unique<TimestampDecorator>(std::make_unique<ConsoleWriter>());
    writer2->write("Hello, timestamped world!");

    std::cout << "\n=== 3. 添加等级 + 时间戳 ===" << std::endl;
    std::unique_ptr<TextWriter> writer3 =
        std::make_unique<TimestampDecorator>(
            std::make_unique<LevelDecorator>(
                std::make_unique<ConsoleWriter>(), "INFO"));
    writer3->write("System started");

    std::cout << "\n=== 4. 加密 + 时间戳 + 等级 ===" << std::endl;
    std::unique_ptr<TextWriter> writer4 =
        std::make_unique<EncryptDecorator>(
            std::make_unique<TimestampDecorator>(
                std::make_unique<LevelDecorator>(
                    std::make_unique<ConsoleWriter>(), "ERROR")));
    writer4->write("Critical failure occurred");

    return 0;
}
