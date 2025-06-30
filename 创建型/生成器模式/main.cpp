#include <iostream>
#include <string>
#include <memory>

using namespace std;

// 产品类
class PC
{
public:
    string cpu;
    string gpu;
    string ram;
    string storage;

    void showConfig() const
    {
        cout << "PC Configuration:\n";
        cout << " CPU: " << cpu << "\n";
        cout << " GPU: " << gpu << "\n";
        cout << " RAM: " << ram << "\n";
        cout << " Storage: " << storage << "\n";
    }
};

// 抽象建造者
class PCBuilder
{
public:
    virtual ~PCBuilder() = default;
    virtual void buildCPU() = 0;
    virtual void buildGPU() = 0;
    virtual void buildRAM() = 0;
    virtual void buildStorage() = 0;
    virtual shared_ptr<PC> getPC() = 0;
};

// 具体建造者：游戏电脑
class GamingPCBuilder : public PCBuilder
{
private:
    shared_ptr<PC> pc = make_shared<PC>();

public:
    void buildCPU() override { pc->cpu = "Intel i9"; }
    void buildGPU() override { pc->gpu = "NVIDIA RTX 4090"; }
    void buildRAM() override { pc->ram = "32GB DDR5"; }
    void buildStorage() override { pc->storage = "2TB NVMe SSD"; }
    shared_ptr<PC> getPC() override { return pc; }
};

// 具体建造者：办公电脑
class OfficePCBuilder : public PCBuilder
{
private:
    shared_ptr<PC> pc = make_shared<PC>();

public:
    void buildCPU() override { pc->cpu = "Intel i5"; }
    void buildGPU() override { pc->gpu = "Integrated Graphics"; }
    void buildRAM() override { pc->ram = "16GB DDR4"; }
    void buildStorage() override { pc->storage = "512GB SSD"; }
    shared_ptr<PC> getPC() override { return pc; }
};

// 指挥者
class PCDirector
{
private:
    PCBuilder *builder;

public:
    void setBuilder(PCBuilder *b) { builder = b; }

    void constructPC()
    {
        builder->buildCPU();
        builder->buildGPU();
        builder->buildRAM();
        builder->buildStorage();
    }
};

// 客户端代码
int main()
{
    GamingPCBuilder gamingBuilder;
    OfficePCBuilder officeBuilder;
    PCDirector director;

    // 构建游戏电脑
    director.setBuilder(&gamingBuilder);
    director.constructPC();
    shared_ptr<PC> gamingPC = gamingBuilder.getPC();
    cout << "Gaming PC:\n";
    gamingPC->showConfig();

    cout << "\n";

    // 构建办公电脑
    director.setBuilder(&officeBuilder);
    director.constructPC();
    shared_ptr<PC> officePC = officeBuilder.getPC();
    cout << "Office PC:\n";
    officePC->showConfig();

    return 0;
}
