#include "TCPListen.h"

#include "TCPEstablished.h"

TCPState *TCPListen::Instance()
{
    return nullptr;
}

void TCPListen::Send(TCPConnection *t)
{
    // send SYN, receive SYN, ACK, etc.
    ChangeState(t, TCPEstablished::Instance());
}
