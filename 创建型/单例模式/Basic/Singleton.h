#ifndef SINGLETON_H_
#define SINGLETON_H_

#include <string>

class Singleton
{
public:
    static Singleton* GetInstance(const std::string& value);
    Singleton(const Singleton&) = delete;                       // 禁止拷贝构造
    Singleton& operator=(const Singleton&) = delete;            // 禁止赋值操作
    
    std::string GetValue() const 
    {
        return value_;
    }

    void SomeBusinessLogic() 
    {
        // 业务逻辑代码
    }
    
protected:
    Singleton(const std::string& value) : value_(value) 
    {
    }

private:
    static Singleton* singleton_;

    std::string value_;
};

#endif // SINGLETON_H_