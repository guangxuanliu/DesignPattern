#ifndef PARSER_H_
#define PARSER_H_

class Scanner;
class ProgramNodeBuilder;

class Parser
{
public:
    Parser();
    virtual ~Parser();

    virtual void Parse(Scanner &, ProgramNodeBuilder &);
};

#endif // PARSER_H_