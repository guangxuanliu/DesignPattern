#ifndef TCPLISTEN_H_
#define TCPLISTEN_H_

#include "TCPState.h"

class TCPListen : public TCPState
{
public:
    static TCPState *Instance();

    virtual void Send(TCPConnection *);
    // ...
};

#endif // TCPLISTEN_H_