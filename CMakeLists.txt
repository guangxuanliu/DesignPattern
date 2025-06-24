cmake_minimum_required(VERSION 3.5)

project(DesignPattern)

add_subdirectory(01_AbstractFactory)
add_subdirectory(创建型/单例模式)

add_subdirectory(结构型/Facade)
add_subdirectory(结构型/Adapter)
add_subdirectory(结构型/Proxy)
add_subdirectory(结构型/Decorator)
add_subdirectory(结构型/Bridge)
add_subdirectory(结构型/Composite)


add_subdirectory(行为型/Observer)
add_subdirectory(行为型/Strategy)
add_subdirectory(行为型/State)
add_subdirectory(行为型/Iterator)
add_subdirectory(行为型/ChainOfResponsibility)
add_subdirectory(行为型/Mediator)