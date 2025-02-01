#include "Compiler.h"

#include "BytecodeStream.h"
#include "Scanner.h"
#include "ProgramNodeBuilder.h"
#include "Parser.h"
#include "RISCCodeGenerator.h"
#include "ProgramNode.h"

Compiler::Compiler()
{
}

void Compiler::Compile(std::istream &input, BytecodeStream &output)
{
    Scanner scanner(input);
    ProgramNodeBuilder builder;
    Parser parsre;

    parsre.Parse(scanner, builder);
    RISCCodeGenerator generator(output);
    ProgramNode* parseTree = builder.GetRootNode();
    parseTree->Traverse(generator);
}