#ifndef PROGRAMNODEBUILDER_H_
#define PROGRAMNODEBUILDER_H_

class ProgramNode;

class ProgramNodeBuilder
{
public:
    ProgramNodeBuilder();

    ProgramNode* GetRootNode();
private:
    ProgramNode* _node;
};

#endif // PROGRAMNODEBUILDER_H_