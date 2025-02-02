set(SRC 
    Shape.cpp
    Manipulator.cpp
    TextView.cpp
)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_executable(AdapterClass ${SRC} ClassAdapter/TextShape.cpp ClassAdapter/main.cpp)

add_executable(AdapterObject ${SRC} ObjectAdapter/TextShape.cpp ClassAdapter/main.cpp)
