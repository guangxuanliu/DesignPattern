#ifndef COMPILER_H_
#define COMPILER_H_

#include <iostream>

class BytecodeStream;

class Compiler{
public:
    Compiler();

    virtual void Compile(std::istream&, BytecodeStream&);
};

#endif // COMPILER_H_