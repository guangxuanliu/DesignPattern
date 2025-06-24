#include "Singleton.h"

Singleton* Singleton::instance_ = nullptr;
std::mutex Singleton::mutex_;

Singleton* Singleton::GetInstance(const std::string& value)
{
    std::lock_guard<std::mutex> guard(mutex_);
    if(instance_ == nullptr)
    {
        instance_ = new Singleton(value);
    }
    return instance_;
}