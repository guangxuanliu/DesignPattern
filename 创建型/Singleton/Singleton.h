#ifndef SINGLETON_H_
#define SINGLETON_H_

class Singleton{
public:
    static Singleton* Instance();
    
protected:
    Singleton();

private:
    static Singleton* _instance;
};

#endif // SINGLETON_H_