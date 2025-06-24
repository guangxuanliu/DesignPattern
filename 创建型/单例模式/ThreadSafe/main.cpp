#include <iostream>
#include <thread>

#include "Singleton.h"

void ThreadFoo()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    Singleton* singleton = Singleton::GetInstance("Foo");
    std::cout << "Singleton value in ThreadFoo: " << singleton->GetValue() << std::endl;
}

void ThreadBar()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    Singleton* singleton = Singleton::GetInstance("Bar");
    std::cout << "Singleton value in ThreadBar: " << singleton->GetValue() << std::endl;
}

int main(int argc, char *argv[])
{
    // 因为构造函数只调用一次，所以在多线程环境下，只有第一个调用的线程会创建实例，
    // 其他线程会获取到同一个实例。所以两次都输出"Foo"。
    std::thread thread1(ThreadFoo);
    std::thread thread2(ThreadBar);

    thread1.join();
    thread2.join();

    return 0;
}