#ifndef PROGRAMNODE_H_
#define PROGRAMNODE_H_

class CodeGenerator;

class ProgramNode
{
public:
    virtual void Traverse(CodeGenerator&);

protected:
    ProgramNode();

private:
};

#endif // PROGRAMNODE_H_