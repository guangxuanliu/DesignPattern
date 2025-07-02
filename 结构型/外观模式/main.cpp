#include <iostream>
#include <memory>

// ========== 子系统组件 ==========

class CPU
{
public:
    void freeze()
    {
        std::cout << "CPU: Freezing processor\n";
    }

    void jump(long position)
    {
        std::cout << "CPU: Jumping to position " << position << "\n";
    }

    void execute()
    {
        std::cout << "CPU: Executing instructions\n";
    }
};

class Memory
{
public:
    void load(long position, const std::string &data)
    {
        std::cout << "Memory: Loading '" << data << "' into position " << position << "\n";
    }
};

class HardDrive
{
public:
    std::string read(long lba, int size)
    {
        std::cout << "HardDrive: Reading " << size << " bytes from LBA " << lba << "\n";
        return "OS Bootloader";
    }
};

// ========== 外观类 ==========

class Computer
{
public:
    Computer()
    {
        cpu = std::make_unique<CPU>();
        memory = std::make_unique<Memory>();
        hardDrive = std::make_unique<HardDrive>();
    }

    void start()
    {
        cpu->freeze();
        std::string bootData = hardDrive->read(0, 512);
        memory->load(0x1000, bootData);
        cpu->jump(0x1000);
        cpu->execute();
    }

private:
    std::unique_ptr<CPU> cpu;
    std::unique_ptr<Memory> memory;
    std::unique_ptr<HardDrive> hardDrive;
};

// ========== 客户端代码 ==========

int main()
{
    Computer computer;
    std::cout << "Client: I just want to start my computer.\n";
    computer.start();
    return 0;
}
