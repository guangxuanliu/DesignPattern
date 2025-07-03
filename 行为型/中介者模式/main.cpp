#include <iostream>
#include <string>
#include <map>
#include <memory>

// ========== 中介者接口 ==========
class ChatRoom;

class User
{
public:
    User(const std::string &name, std::shared_ptr<ChatRoom> room)
        : name_(name), room_(room) {}

    void send(const std::string &to, const std::string &message);
    void receive(const std::string &from, const std::string &message);

    std::string name() const { return name_; }

private:
    std::string name_;
    std::shared_ptr<ChatRoom> room_;
};

// ========== 中介者类 ==========
class ChatRoom : public std::enable_shared_from_this<ChatRoom>
{
public:
    void registerUser(std::shared_ptr<User> user)
    {
        users_[user->name()] = user;
    }

    void sendMessage(const std::string &from, const std::string &to, const std::string &message)
    {
        auto it = users_.find(to);
        if (it != users_.end())
        {
            it->second->receive(from, message);
        }
        else
        {
            std::cout << "[ChatRoom] User '" << to << "' not found.\n";
        }
    }

private:
    std::map<std::string, std::shared_ptr<User>> users_;
};

// ========== 用户实现 ==========
void User::send(const std::string &to, const std::string &message)
{
    room_->sendMessage(name_, to, message);
}

void User::receive(const std::string &from, const std::string &message)
{
    std::cout << "[" << name_ << "] Received from " << from << ": " << message << "\n";
}

// ========== 测试 ==========
int main()
{
    auto room = std::make_shared<ChatRoom>();

    auto alice = std::make_shared<User>("Alice", room);
    auto bob = std::make_shared<User>("Bob", room);
    auto john = std::make_shared<User>("John", room);

    room->registerUser(alice);
    room->registerUser(bob);
    room->registerUser(john);

    alice->send("Bob", "Hi Bob!");
    bob->send("Alice", "Hey Alice!");
    john->send("Bob", "Good morning Bob!");
    bob->send("Unknown", "Are you there?");

    return 0;
}
