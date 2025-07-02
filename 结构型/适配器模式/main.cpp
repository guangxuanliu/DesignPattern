#include <iostream>
#include <string>
#include <memory>

// ====================== 被适配类 ======================
// 这是一个旧的HTTP客户端类，具有过时的接口
// 只接受C风格字符串，并返回C风格字符串
// 需要适配为新的接口，接受std::string并返回std::string
class LegacyHttpClient
{
public:
    void sendRequest(const char *url)
    {
        std::cout << "[LegacyHttpClient] Sending request to " << url << std::endl;
    }

    const char *getResponse()
    {
        return "Legacy Response";
    }
};

// ====================== 目标接口 ======================
// 这是新的HTTP客户端接口，使用std::string作为参数和返回值
// 需要适配LegacyHttpClient以实现这个接口
class HttpClient
{
public:
    virtual ~HttpClient() = default;
    virtual void get(const std::string &url) = 0;
    virtual std::string getResponseText() = 0;
};

// ====================== 类适配器 ======================
// 类适配器通过继承LegacyHttpClient来实现HttpClient接口
// 这种方式可以直接使用LegacyHttpClient的成员函数
// 缺点是：如果LegacyHttpClient有多个方法需要适配，类适配器会变得复杂
// 优点是：可以直接使用继承的方式，避免了额外的对象创建
class LegacyHttpClientAdapter_Class : public HttpClient, public LegacyHttpClient
{
public:
    void get(const std::string &url) override
    {
        sendRequest(url.c_str()); // 使用继承的旧方法
    }

    std::string getResponseText() override
    {
        return getResponse(); // 使用继承的旧方法
    }
};

// ====================== 对象适配器 ======================
// 对象适配器通过组合LegacyHttpClient来实现HttpClient接口
// 这种方式可以更灵活地适配LegacyHttpClient的多个实例
// 缺点是：需要额外的对象创建和管理
// 优点是：可以适配多个LegacyHttpClient实例，且不需要修改LegacyHttpClient类
class LegacyHttpClientAdapter_Object : public HttpClient
{
public:
    LegacyHttpClientAdapter_Object(std::shared_ptr<LegacyHttpClient> adaptee)
        : adaptee_(adaptee) {}

    void get(const std::string &url) override
    {
        adaptee_->sendRequest(url.c_str());
    }

    std::string getResponseText() override
    {
        return adaptee_->getResponse();
    }

private:
    std::shared_ptr<LegacyHttpClient> adaptee_;
};

// ====================== 客户端调用函数 ======================
void fetch(HttpClient &client)
{
    client.get("http://example.com/data");
    std::cout << "[Client] Got: " << client.getResponseText() << "\n\n";
}

// ====================== 主函数 ======================
// 主函数演示了如何使用类适配器和对象适配器
// 在实际应用中，尽量使用对象适配器，因为它更灵活且易于扩展
int main()
{
    // 使用类适配器
    LegacyHttpClientAdapter_Class classAdapter;
    std::cout << "--- Using Class Adapter ---\n";
    fetch(classAdapter);

    // 使用对象适配器
    auto legacy = std::make_shared<LegacyHttpClient>();
    LegacyHttpClientAdapter_Object objectAdapter(legacy);
    std::cout << "--- Using Object Adapter ---\n";
    fetch(objectAdapter);

    return 0;
}
