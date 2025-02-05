#include "TCPClose.h"
#include "TCPEstablished.h"
#include "TCPListen.h"

TCPState *TCPClose::Instance()
{
    return nullptr;
}

void TCPClose::ActiveOpen(TCPConnection *t)
{
    // send SYN, receive SYN, ACK, etc.
    ChangeState(t, TCPEstablished::Instance());
}

void TCPClose::PassiveOpen(TCPConnection *t)
{
    ChangeState(t, TCPListen::Instance());
}
