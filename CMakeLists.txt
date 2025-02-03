cmake_minimum_required(VERSION 3.5)

project(DesignPattern)

add_subdirectory(test)
add_subdirectory(01_AbstractFactory)
add_subdirectory(创建型/Singleton)

add_subdirectory(结构型/Facade)
add_subdirectory(结构型/Adapter)
add_subdirectory(结构型/Proxy)
add_subdirectory(结构型/Decorator)


add_subdirectory(行为型/Observer)