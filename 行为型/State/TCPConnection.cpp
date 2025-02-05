#include "TCPConnection.h"
#include "TCPState.h"
#include "TCPClose.h"

TCPConnection::TCPConnection()
{
    _state = TCPClose::Instance();
}

void TCPConnection::ActiveOpen()
{
    _state->ActiveOpen(this);
}

void TCPConnection::PassiveOpen()
{
    _state->PassiveOpen(this);
}

void TCPConnection::Close()
{
    _state->Close(this);
}

void TCPConnection::Send()
{
    _state->Send(this);
}

void TCPConnection::Acknowledge()
{
    _state->Acknowledge(this);
}

void TCPConnection::Synchronize()
{
    _state->Synchronize(this);
}

void TCPConnection::ProcessOctet(TCPOctetStream *o)
{
    _state->ProcessOctet(this, o);
}

void TCPConnection::ChangeState(TCPState *state)
{
    _state = state;
}
