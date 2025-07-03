#include <iostream>
#include <memory>
#include <string>

// 前向声明
class NetworkConnection;

// ========== 抽象状态类 ==========
class ConnectionState
{
public:
    virtual ~ConnectionState() = default;
    virtual void handle(NetworkConnection &context) = 0;
    virtual std::string name() const = 0;
};

// ========== Context 类 ==========
class NetworkConnection
{
public:
    NetworkConnection(std::shared_ptr<ConnectionState> state)
        : state_(state) {}

    void setState(std::shared_ptr<ConnectionState> newState)
    {
        state_ = newState;
    }

    void request()
    {
        std::cout << "[State] Current: " << state_->name() << "\n";
        state_->handle(*this);
    }

private:
    std::shared_ptr<ConnectionState> state_;
    friend class DisconnectedState;
    friend class ConnectingState;
    friend class ConnectedState;
};

// ========== 具体状态类 ==========
class DisconnectedState : public ConnectionState
{
public:
    void handle(NetworkConnection &context) override;
    std::string name() const override { return "Disconnected"; }
};

class ConnectingState : public ConnectionState
{
public:
    void handle(NetworkConnection &context) override;
    std::string name() const override { return "Connecting"; }
};

class ConnectedState : public ConnectionState
{
public:
    void handle(NetworkConnection &context) override;
    std::string name() const override { return "Connected"; }
};

// 实现行为并切换状态
void DisconnectedState::handle(NetworkConnection &context)
{
    std::cout << "Attempting to connect...\n";
    context.setState(std::make_shared<ConnectingState>());
}

void ConnectingState::handle(NetworkConnection &context)
{
    std::cout << "Connection established.\n";
    context.setState(std::make_shared<ConnectedState>());
}

void ConnectedState::handle(NetworkConnection &context)
{
    std::cout << "Disconnecting now.\n";
    context.setState(std::make_shared<DisconnectedState>());
}

// ========== 测试代码 ==========
int main()
{
    NetworkConnection conn(std::make_shared<DisconnectedState>());

    // 模拟状态切换
    conn.request(); // Disconnected -> Connecting
    conn.request(); // Connecting -> Connected
    conn.request(); // Connected -> Disconnected
    conn.request(); // Disconnected -> Connecting

    return 0;
}
