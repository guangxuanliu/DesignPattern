#include <iostream>
#include <string>
#include <memory>

enum class LogLevel
{
    INFO = 1,
    WARNING = 2,
    ERROR = 3
};

// 抽象处理器
class Logger
{
public:
    Logger(LogLevel level) : level_(level) {}
    virtual ~Logger() = default;

    void setNext(std::shared_ptr<Logger> next)
    {
        next_ = next;
    }

    void logMessage(LogLevel level, const std::string &message)
    {
        if (level >= level_)
        {
            write(message);
        }
        if (next_)
        {
            next_->logMessage(level, message);
        }
    }

protected:
    virtual void write(const std::string &message) = 0;

private:
    LogLevel level_;
    std::shared_ptr<Logger> next_;
};

// 具体处理器：控制台日志
class ConsoleLogger : public Logger
{
public:
    ConsoleLogger(LogLevel level) : Logger(level) {}

protected:
    void write(const std::string &message) override
    {
        std::cout << "[Console] " << message << std::endl;
    }
};

// 具体处理器：文件日志
class FileLogger : public Logger
{
public:
    FileLogger(LogLevel level) : Logger(level) {}

protected:
    void write(const std::string &message) override
    {
        std::cout << "[File] " << message << std::endl;
    }
};

// 具体处理器：邮件日志
class EmailLogger : public Logger
{
public:
    EmailLogger(LogLevel level) : Logger(level) {}

protected:
    void write(const std::string &message) override
    {
        std::cout << "[Email] " << message << std::endl;
    }
};

// ================== 示例使用 ==================
int main()
{
    // 创建处理器
    auto consoleLogger = std::make_shared<ConsoleLogger>(LogLevel::INFO);
    auto fileLogger = std::make_shared<FileLogger>(LogLevel::WARNING);
    auto emailLogger = std::make_shared<EmailLogger>(LogLevel::ERROR);

    // 构建链条：Console -> File -> Email
    consoleLogger->setNext(fileLogger);
    fileLogger->setNext(emailLogger);

    // 发送日志
    consoleLogger->logMessage(LogLevel::INFO, "This is an INFO message");
    consoleLogger->logMessage(LogLevel::WARNING, "This is a WARNING message");
    consoleLogger->logMessage(LogLevel::ERROR, "This is an ERROR message");

    return 0;
}
