/*

      抽象 Abstraction（消息种类）    <===>     实现 Implementor（传输方式）
             TextMessage                          TcpSender
             FileMessage                          UdpSender
             VoiceMessage                         WebSocketSender

// 抽象层和实现层就像是河两岸的两个世界，而“桥接模式”就像一座桥梁，把这两个世界连接起来，但又不把它们强耦合在一起。
// 这样，我们可以在不修改抽象层的情况下，轻松地添加新的实现方式，或者在不修改实现层的情况下，添加新的消息种类。

// “桥”指的是在抽象和实现之间添加的引用关系（通过指针/引用/组合）
// “连接”指的是抽象类 Message 中持有一个 MessageSender*，并通过它完成工作


*/

#include <iostream>
#include <string>
#include <memory>

// ======================= 实现接口层 =========================

class MessageSender
{
public:
    virtual ~MessageSender() = default;
    virtual void sendRaw(const std::string &content) = 0;
};

class TcpSender : public MessageSender
{
public:
    void sendRaw(const std::string &content) override
    {
        std::cout << "[TCP] Sending: " << content << std::endl;
    }
};

class UdpSender : public MessageSender
{
public:
    void sendRaw(const std::string &content) override
    {
        std::cout << "[UDP] Sending: " << content << std::endl;
    }
};

// ======================= 抽象接口层 =========================

class Message
{
public:
    Message(std::shared_ptr<MessageSender> sender)
        : sender_(sender) {}

    virtual ~Message() = default;

    virtual void send() = 0;

protected:
    std::shared_ptr<MessageSender> sender_;
};

class TextMessage : public Message
{
public:
    TextMessage(const std::string &text, std::shared_ptr<MessageSender> sender)
        : Message(sender), text_(text) {}

    void send() override
    {
        sender_->sendRaw("TextMessage: " + text_);
    }

private:
    std::string text_;
};

class FileMessage : public Message
{
public:
    FileMessage(const std::string &fileName, std::shared_ptr<MessageSender> sender)
        : Message(sender), fileName_(fileName) {}

    void send() override
    {
        sender_->sendRaw("FileMessage: [file://" + fileName_ + "]");
    }

private:
    std::string fileName_;
};

class VoiceMessage : public Message
{
public:
    VoiceMessage(const std::string &file, std::shared_ptr<MessageSender> sender)
        : Message(sender), file_(file) {}

    void send() override
    {
        sender_->sendRaw("VoiceMessage: [voice://" + file_ + "]");
    }

private:
    std::string file_;
};

// ======================= 客户端 =========================

int main()
{
    auto tcp = std::make_shared<TcpSender>();
    auto udp = std::make_shared<UdpSender>();

    TextMessage textViaTcp("Hello via TCP", tcp);
    FileMessage fileViaTcp("report.pdf", tcp);
    VoiceMessage voiceViaTcp("hello.wav", tcp);

    TextMessage textViaUdp("Hello via UDP", udp);
    FileMessage fileViaUdp("photo.png", udp);
    VoiceMessage voiceViaUdp("record.mp3", udp);

    textViaTcp.send();
    fileViaTcp.send();
    voiceViaTcp.send();

    textViaUdp.send();
    fileViaUdp.send();
    voiceViaUdp.send();

    return 0;
}
