#include "MySocket.h"
#include "MyThread.h"

void MySocket::OnAccept(SOCKET* socket)
{
    SuperSocket* ss=new MySocket(socket);
    //MyThread* mt=new MyThread(&ms,MySocket::RollReceive);
//    MyThread mt;
//    mt.InitThread(ss,&SuperSocket::RollReceive);
//    mt.StartThread();
    SuperThread<SuperSocket> st(ss,&SuperSocket::RollReceive);
    st.StartThread();
}

MySocket::MySocket(SOCKET* socket)
{
    this->tempSocket=*socket;
}

void MySocket::OnReceive(SuperSocket::SockData* data)
{
    cout<<data->id<<endl;
}
