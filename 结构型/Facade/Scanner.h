#ifndef SCANNER_H_
#define SCANNER_H_

#include <iostream>

class Token;

class Scanner
{
public:
    Scanner(std::istream &);
    virtual ~Scanner();

    virtual Token &Scan();

private:
    std::istream &_inputStream;
};

#endif // SCANNER_H_