#ifndef TCPCLOSE_H_
#define TCPCLOSE_H_

#include "TCPState.h"

class TCPClose : public TCPState
{
public:
    static TCPState *Instance();

    virtual void ActiveOpen(TCPConnection *);
    virtual void PassiveOpen(TCPConnection *);
    // ...
};

#endif // TCPCLOSE_H_