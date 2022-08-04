#include<iostream>
#include<string>
#include "MySocket.h"
using namespace std;
int main()
{
    MySocket  ms;
    ms.Connect("10.10.24.148",8010);
    while(true)
    {
        string s;
        cin>>s;
        MySocket::SockData data;
        data.id=0;
        data.length=s.size();
        data.content=s.c_str();
        ms.Send(&data);
    }
    return 0;
}
