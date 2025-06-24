#include <iostream>

#include "Singleton.h"

int main(int argc, char *argv[])
{
    Singleton* singleton1 = Singleton::GetInstance("FOO");
    Singleton* singleton2 = Singleton::GetInstance("BAR");

    std::cout << std::boolalpha << (singleton1 == singleton2) << std::endl;
}