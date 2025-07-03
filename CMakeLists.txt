cmake_minimum_required(VERSION 3.5)

project(DesignPattern)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_subdirectory(创建型/单例模式)
add_subdirectory(创建型/原型模式)
add_subdirectory(创建型/生成器模式)
add_subdirectory(创建型/工厂模式家族/简单工厂模式)
add_subdirectory(创建型/工厂模式家族/工厂方法模式)
add_subdirectory(创建型/工厂模式家族/抽象工厂模式)


add_subdirectory(结构型/享元模式)
add_subdirectory(结构型/组合模式)
add_subdirectory(结构型/代理模式)
add_subdirectory(结构型/装饰器模式)
add_subdirectory(结构型/外观模式)
add_subdirectory(结构型/适配器模式)
add_subdirectory(结构型/桥接模式)


add_subdirectory(行为型/责任链模式)
add_subdirectory(行为型/观察者模式)
add_subdirectory(行为型/迭代器模式)
add_subdirectory(行为型/策略模式)
add_subdirectory(行为型/中介者模式)
add_subdirectory(行为型/状态模式)
add_subdirectory(行为型/命令模式)
add_subdirectory(行为型/模板方法模式)
add_subdirectory(行为型/备忘录模式)
add_subdirectory(行为型/访问者模式)
add_subdirectory(行为型/解释器模式)