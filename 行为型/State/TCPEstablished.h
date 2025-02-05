#ifndef TCPESTABLISHED_H_
#define TCPESTABLISHED_H_

#include "TCPState.h"

class TCPEstablished : public TCPState
{
public:
    static TCPState *Instance();

    virtual void Transmit(TCPConnection *, TCPOctetStream *);
    virtual void Close(TCPConnection *);
};

#endif // TCPESTABLISHED_H_