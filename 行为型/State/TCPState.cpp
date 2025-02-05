#include "TCPState.h"
#include "TCPConnection.h"

void TCPState::Transmit(TCPConnection *, TCPOctetStream *)
{
}

void TCPState::ActiveOpen(TCPConnection *)
{
}

void TCPState::PassiveOpen(TCPConnection *)
{
}

void TCPState::Close(TCPConnection *)
{
}

void TCPState::Synchronize(TCPConnection *)
{
}

void TCPState::Acknowledge(TCPConnection *)
{
}

void TCPState::Send(TCPConnection *)
{
}

void TCPState::ProcessOctet(TCPConnection *, TCPOctetStream *o)
{
}

void TCPState::ChangeState(TCPConnection *t, TCPState *s)
{
    t->ChangeState(s);
}
