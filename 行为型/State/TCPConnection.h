#ifndef TCPCONNECTION_H_
#define TCPCONNECTION_H_

class TCPOctetStream;
class TCPState;

class TCPConnection
{
public:
    TCPConnection();
    void ActiveOpen();
    void PassiveOpen();
    void Close();
    void Send();
    void Acknowledge();
    void Synchronize();
    void ProcessOctet(TCPOctetStream*);

private:
    friend class TCPState;
    void ChangeState(TCPState *state);

private:
    TCPState *_state;
};

#endif // TCPCONNECTION_H_