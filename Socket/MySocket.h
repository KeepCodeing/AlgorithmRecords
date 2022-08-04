#include "SuperSocket.h"

class MySocket:public SuperSocket
{
public:
    MySocket(SOCKET* socket);
    MySocket(){}
protected:
    virtual void OnAccept(SOCKET* socket);
    virtual void OnReceive(SuperSocket::SockData* data);
};
