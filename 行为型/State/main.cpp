#include <iostream>
#include "TCPState.h"
#include "TCPConnection.h"

int main()
{
    TCPConnection t;
    t.ActiveOpen();
    t.Acknowledge();
    t.Close();
    t.PassiveOpen();
    t.Synchronize();
    t.Send();
    return 0;
}