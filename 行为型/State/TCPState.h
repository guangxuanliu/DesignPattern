#ifndef TCPSTATE_H_
#define TCPSTATE_H_

class TCPConnection;
class TCPOctetStream;

class TCPState
{
public:
    virtual void Transmit(TCPConnection *, TCPOctetStream *);
    virtual void ActiveOpen(TCPConnection *);
    virtual void PassiveOpen(TCPConnection *);
    virtual void Close(TCPConnection *);
    virtual void Synchronize(TCPConnection *);
    virtual void Acknowledge(TCPConnection *);
    virtual void Send(TCPConnection *);
    virtual void ProcessOctet(TCPConnection *, TCPOctetStream *);

protected:
    void ChangeState(TCPConnection *, TCPState *);
};

#endif // TCPSTATE_H_