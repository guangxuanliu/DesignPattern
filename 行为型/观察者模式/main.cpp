#include <iostream>
#include <vector>
#include <string>
#include <memory>

// ========== 状态类型 ==========
enum class ConnectionState
{
    CONNECTING,
    CONNECTED,
    DISCONNECTED,
    ERROR
};

// ========== 观察者接口 ==========
class Observer
{
public:
    virtual ~Observer() = default;
    virtual void onStateChanged(ConnectionState state) = 0;
};

// ========== 被观察者（主题） ==========
class NetworkConnection
{
public:
    void attach(std::shared_ptr<Observer> observer)
    {
        observers.push_back(observer);
    }

    void setState(ConnectionState newState)
    {
        state = newState;
        notify();
    }

private:
    void notify()
    {
        for (const auto &obs : observers)
        {
            obs->onStateChanged(state);
        }
    }

    ConnectionState state = ConnectionState::DISCONNECTED;
    std::vector<std::shared_ptr<Observer>> observers;
};

// ========== 具体观察者 ==========
class Logger : public Observer
{
public:
    void onStateChanged(ConnectionState state) override
    {
        std::cout << "[Logger] State changed to: " << toString(state) << "\n";
    }

private:
    std::string toString(ConnectionState state)
    {
        switch (state)
        {
        case ConnectionState::CONNECTING:
            return "CONNECTING";
        case ConnectionState::CONNECTED:
            return "CONNECTED";
        case ConnectionState::DISCONNECTED:
            return "DISCONNECTED";
        case ConnectionState::ERROR:
            return "ERROR";
        }
        return "UNKNOWN";
    }
};

class UIStatusDisplay : public Observer
{
public:
    void onStateChanged(ConnectionState state) override
    {
        std::cout << "[UI] Display updated: " << toSymbol(state) << "\n";
    }

private:
    std::string toSymbol(ConnectionState state)
    {
        // 只是为了演示，实际应用中可能使用图形界面库来更新UI
        // 输出时，emoji可能会不正常
        switch (state)
        {
        case ConnectionState::CONNECTING:
            return "🔄 Connecting...";
        case ConnectionState::CONNECTED:
            return "✅ Connected";
        case ConnectionState::DISCONNECTED:
            return "⚠️ Disconnected";
        case ConnectionState::ERROR:
            return "❌ Error";
        }
        return "❓ Unknown";
    }
};

class ReconnectService : public Observer
{
public:
    void onStateChanged(ConnectionState state) override
    {
        if (state == ConnectionState::DISCONNECTED || state == ConnectionState::ERROR)
        {
            std::cout << "[ReconnectService] Scheduling reconnect...\n";
        }
    }
};

// ========== 主函数 ==========
int main()
{
    auto connection = std::make_shared<NetworkConnection>();

    auto logger = std::make_shared<Logger>();
    auto ui = std::make_shared<UIStatusDisplay>();
    auto reconnect = std::make_shared<ReconnectService>();

    connection->attach(logger);
    connection->attach(ui);
    connection->attach(reconnect);

    connection->setState(ConnectionState::CONNECTING);
    connection->setState(ConnectionState::CONNECTED);
    connection->setState(ConnectionState::DISCONNECTED);
    connection->setState(ConnectionState::ERROR);

    return 0;
}
