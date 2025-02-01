set(SRC 
    main.cpp
    Compiler.cpp
    BytecodeStream.cpp
    Scanner.cpp
    ProgramNodeBuilder.cpp
    Parser.cpp
    CodeGenerator.cpp
    RISCCodeGenerator.cpp
    ProgramNode.cpp
    Token.cpp
)

add_executable(Facade ${SRC})