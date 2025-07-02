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
add_subdirectory(结构型/Bridge)


add_subdirectory(行为型/责任链模式)
add_subdirectory(行为型/Observer)
add_subdirectory(行为型/Strategy)
add_subdirectory(行为型/State)
add_subdirectory(行为型/Iterator)
add_subdirectory(行为型/Mediator)