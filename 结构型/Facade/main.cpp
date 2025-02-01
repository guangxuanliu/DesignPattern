#include <iostream>
#include "Compiler.h"
#include "BytecodeStream.h"

int main(int argc, char *argv[])
{
    Compiler compiler;
    BytecodeStream bcs;
    compiler.Compile(std::cin, bcs);

    return 0;
}