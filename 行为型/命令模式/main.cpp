#include <iostream>
#include <memory>
#include <string>
#include <vector>

// ========== Receiver：执行者 ==========
class NetworkManager
{
public:
    void login(const std::string &user)
    {
        std::cout << "[Receiver] Logging in as: " << user << "\n";
    }

    void upload(const std::string &filename)
    {
        std::cout << "[Receiver] Uploading: " << filename << "\n";
    }

    void download(const std::string &filename)
    {
        std::cout << "[Receiver] Downloading: " << filename << "\n";
    }
};

// ========== Command 接口 ==========
class Command
{
public:
    virtual ~Command() = default;
    virtual void execute() = 0;
};

// ========== ConcreteCommand 实现 ==========
class LoginCommand : public Command
{
public:
    LoginCommand(NetworkManager &receiver, const std::string &user)
        : receiver_(receiver), username_(user) {}

    void execute() override
    {
        receiver_.login(username_);
    }

private:
    NetworkManager &receiver_;
    std::string username_;
};

class UploadCommand : public Command
{
public:
    UploadCommand(NetworkManager &receiver, const std::string &file)
        : receiver_(receiver), filename_(file) {}

    void execute() override
    {
        receiver_.upload(filename_);
    }

private:
    NetworkManager &receiver_;
    std::string filename_;
};

class DownloadCommand : public Command
{
public:
    DownloadCommand(NetworkManager &receiver, const std::string &file)
        : receiver_(receiver), filename_(file) {}

    void execute() override
    {
        receiver_.download(filename_);
    }

private:
    NetworkManager &receiver_;
    std::string filename_;
};

// ========== Invoker：命令调度器 ==========
class CommandInvoker
{
public:
    void addCommand(std::shared_ptr<Command> cmd)
    {
        queue_.push_back(cmd);
    }

    void executeAll()
    {
        for (auto &cmd : queue_)
        {
            cmd->execute();
        }
        queue_.clear();
    }

private:
    std::vector<std::shared_ptr<Command>> queue_;
};

// ========== 客户端 ==========
int main()
{
    NetworkManager manager;

    auto loginCmd = std::make_shared<LoginCommand>(manager, "Alice");
    auto uploadCmd = std::make_shared<UploadCommand>(manager, "data.txt");
    auto downloadCmd = std::make_shared<DownloadCommand>(manager, "report.pdf");

    CommandInvoker invoker;
    invoker.addCommand(loginCmd);
    invoker.addCommand(uploadCmd);
    invoker.addCommand(downloadCmd);

    invoker.executeAll();

    return 0;
}
