#ifndef CODEGENERATOR_H_
#define CODEGENERATOR_H_

#include "BytecodeStream.h"

class CodeGenerator
{
public:
    CodeGenerator(BytecodeStream&);

protected:
    BytecodeStream& _output;
};

#endif // CODEGENERATOR_H_