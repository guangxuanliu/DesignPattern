#ifndef SINGLETON_H_
#define SINGLETON_H_

#include <mutex>

class Singleton{
public:
    static Singleton* Instance();
    
protected:
    Singleton();

private:
    static Singleton* _instance;
    static std::mutex _mutex;
};

#endif // SINGLETON_H_