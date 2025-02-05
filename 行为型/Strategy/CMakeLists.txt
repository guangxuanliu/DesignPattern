set(SRC main.cpp 
        Composition.cpp
        Compositor.cpp SimpleCompositor.cpp TexCompositor.cpp ArrayCompositor.cpp)

add_executable(Strategy ${SRC})