#ifndef RISCCODEGENERATOR_H_
#define RISCCODEGENERATOR_H_

#include "CodeGenerator.h"

class BytecodeStream;

class RISCCodeGenerator : public CodeGenerator
{
public:
    RISCCodeGenerator(BytecodeStream&);

private:
};

#endif // RISCCODEGENERATOR_H_