#include <iostream>
#include <memory>
#include <string>

// ========== 抽象基类 ==========
class NetworkClient
{
public:
    virtual ~NetworkClient() = default;

    // 模板方法：定义流程骨架
    void communicate(const std::string &data)
    {
        connect();
        authenticate();
        sendData(data);
        disconnect();
    }

protected:
    void connect()
    {
        std::cout << "[Base] Connecting to server...\n";
    }

    virtual void authenticate() = 0; // 延迟到子类实现

    void sendData(const std::string &data)
    {
        std::cout << "[Base] Sending data: " << data << "\n";
    }

    void disconnect()
    {
        std::cout << "[Base] Disconnecting...\n";
    }
};

// ========== 子类：HTTP 客户端 ==========
class HttpClient : public NetworkClient
{
protected:
    void authenticate() override
    {
        std::cout << "[HttpClient] Using Basic Auth\n";
    }
};

// ========== 子类：SSH 客户端 ==========
class SshClient : public NetworkClient
{
protected:
    void authenticate() override
    {
        std::cout << "[SshClient] Using Public-Key Auth\n";
    }
};

// ========== 客户端使用 ==========
int main()
{
    std::unique_ptr<NetworkClient> client;

    std::cout << "\n--- HTTP ---\n";
    client = std::make_unique<HttpClient>();
    client->communicate("GET /index.html");

    std::cout << "\n--- SSH ---\n";
    client = std::make_unique<SshClient>();
    client->communicate("run ls -al");

    return 0;
}
