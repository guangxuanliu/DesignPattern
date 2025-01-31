#include <iostream>

#include "Singleton.h"

int main(int argc, char *argv[])
{
    Singleton* singleton1 = Singleton::Instance();
    Singleton* singleton2 = Singleton::Instance();

    std::cout << std::boolalpha << (singleton1 == singleton2) << std::endl;
}