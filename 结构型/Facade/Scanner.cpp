#include "Scanner.h"
#include "Token.h"

Scanner::Scanner(std::istream &in)
    : _inputStream(in)
{
}

Scanner::~Scanner()
{
}

Token &Scanner::Scan()
{
    Token token;
    // ...

    return token;
}
