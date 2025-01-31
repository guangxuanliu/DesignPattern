#include "Singleton.h"

Singleton* Singleton::_instance = 0;
std::mutex Singleton::_mutex;

Singleton* Singleton::Instance(){
    std::lock_guard<std::mutex> guard(_mutex);
    if(_instance == 0){
        _instance = new Singleton();
    }
    return _instance;
}

Singleton::Singleton(){
}