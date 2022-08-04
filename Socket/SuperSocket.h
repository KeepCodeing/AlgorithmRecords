#pragma once
#include<string>
#include<iostream>
#include <WINSOCK2.H>
#include "MyThread.h"
using namespace std;
class SuperSocket
{
public:
    typedef struct SockData{
        int id;
        int length;
        const char* content;
    }SockData;
public:
    void Listen(int port);
    bool Connect(string ipStr,int port);
    void Send(SockData* data);
protected:
    virtual void OnAccept(SOCKET* socket){};
    void RollReceive();
    void ListenThread();
    int port;
    virtual void OnReceive(SockData* data){};
    SOCKET tempSocket;
    SuperThread<SuperSocket>* mt;
};
