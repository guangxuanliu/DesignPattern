#include "TCPEstablished.h"

#include "TCPListen.h"
#include "TCPConnection.h"
#include "TCPOctetStream.h"

TCPState *TCPEstablished::Instance()
{
    return nullptr;
}

void TCPEstablished::Transmit(TCPConnection *t, TCPOctetStream *o)
{
    t->ProcessOctet(o);
}

void TCPEstablished::Close(TCPConnection *t)
{
    // send FIN, receive ACK of FIN
    ChangeState(t, TCPListen::Instance());
}
