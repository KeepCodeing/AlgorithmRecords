#include "SuperSocket.h"


void SuperSocket::ListenThread()
{
    WORD wVersionRequested;// ����汾��Ϣ����
    WSADATA wsaData;//����������Ϣ����
    SOCKET sockfd;
    struct sockaddr_in server_addr;
    struct sockaddr_in client_addr;

    int err;//�������ű���
    wVersionRequested = MAKEWORD(1,1);//���汾��Ϣ��ֵ
    err = WSAStartup(wVersionRequested, &wsaData);//��������Ϣ��ֵ
    if(err!=0)
    {
        return;//�����û��Ҳ������ʵİ汾
    }
    //ȷ�� Windows Sockets DLL ֧�� 1.1 �汾
    //DLL �汾���Ը��� 1.1
    //ϵͳ���صİ汾��ʼ�������Ҫ��� 1.1����Ӧ�ó�����DLL �п�֧�ֵ���Ͱ汾��
    if(LOBYTE(wsaData.wVersion)!= 1||HIBYTE(wsaData.wVersion)!=1)
    {
        WSACleanup();//�����û��Ҳ������ʵİ汾
        return;
    }

    if((sockfd=socket(AF_INET,SOCK_STREAM, IPPROTO_TCP))==-1)
    {
        if (WSAGetLastError() == WSANOTINITIALISED)
        {
            printf("Error��WSANOTINITIALISED,please Call WSAStartup first\n");
            return;
        }
        else
        {
            int err =WSAGetLastError();
            printf("Bind error:%s,errorcode :%d\n",strerror(errno),err);
            return;
        }
    }

    /* ����������� sockaddr�ṹ */
    memset(&server_addr,0,sizeof(struct sockaddr_in));
    server_addr.sin_family=AF_INET;
    server_addr.sin_addr.s_addr=htonl(INADDR_ANY);
    server_addr.sin_port=htons(port);

    /* ����sockfd������ */
    if(bind(sockfd,(struct sockaddr *)(&server_addr),sizeof(struct sockaddr))==-1)
    {
        int err = WSAGetLastError();
        cout<<"Bind error:%s,errorcode :"<<strerror(errno)<<endl;;
        return;
    }

    /* ����sockfd������ */
    if(listen(sockfd,5)==-1)
    {
        cout<<"Listen error:"<<strerror(errno)<<endl;
        return;
    }
    while(1)
    {
        /* ����������,ֱ���ͻ����������� */
        int sin_size=sizeof(struct sockaddr_in);
        SOCKET socket;
        cout<<"I am Listen ....."<<endl;
        if((socket=accept(sockfd,(struct sockaddr *)(&client_addr),&sin_size))==INVALID_SOCKET )
        {
            cout<<"Accept error:"<<strerror(errno)<<endl;;
            continue;
        }
        cout<<"Server get connection from "<<inet_ntoa(client_addr.sin_addr)<<endl;;
        this->OnAccept(&socket);
    }
}
void SuperSocket::Listen(int port)
{
    this->port=port;
    //    MyThread mt;
    //    mt.InitThread(this,&SuperSocket::ListenThread);
    //    mt.StartThread();
    this->mt=new SuperThread<SuperSocket>(this,&SuperSocket::ListenThread);
    this->mt->StartThread();
}

bool SuperSocket::Connect(string ipStr,int port)
{
    WSADATA  Ws;
    SOCKET CientSocket;
    struct sockaddr_in ServerAddr;
    int AddrLen = 0;
    HANDLE hThread = NULL;

    //Init Windows Socket
    if ( WSAStartup(MAKEWORD(2,2), &Ws) != 0 )
    {
        cout<<"Init Windows Socket Failed::"<<GetLastError()<<endl;
        return false;
    }

    //Create Socket
    CientSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if ( CientSocket == INVALID_SOCKET )
    {
        cout<<"Create Socket Failed::"<<GetLastError()<<endl;
        return false;
    }

    ServerAddr.sin_family = AF_INET;
    ServerAddr.sin_addr.s_addr = inet_addr(ipStr.c_str());
    ServerAddr.sin_port = htons(port);
    memset(ServerAddr.sin_zero, 0x00, 8);

    int err = connect(CientSocket,(struct sockaddr*)&ServerAddr, sizeof(ServerAddr));
    if ( err == SOCKET_ERROR )
    {
        cout<<"Connect Error::"<<GetLastError()<<endl;
        return false;
    }
    else
    {
    //    MyThread mt;
    //    mt.InitThread(this,&SuperSocket::RollReceive);
    //    mt.StartThread();
        this->tempSocket=CientSocket;
        SuperThread<SuperSocket> st(this,&SuperSocket::RollReceive);
        st.StartThread();
        return true;
    }
}

void SuperSocket::RollReceive()
{
    int iResult;
    int recvbuflen=1024;
    bool isComplete=true;
    int ID;
    int length;
    int lenReaded;
    int lenLeaved;
    char content[100000];
    while(true)
    {
        if(!isComplete)
        {

            iResult=recv(tempSocket,content+lenReaded,lenLeaved,0);
            if(iResult<=0)
            {
                printf("recv failed with error: %d/n", WSAGetLastError());
                closesocket(this->tempSocket);
                break;
            }
            lenReaded+=iResult;
            lenLeaved=length-lenReaded;
            if(lenReaded<length)
            {
                isComplete=false;
            }
        }
        else
        {
            iResult=recv(tempSocket,(char*)&ID,sizeof(int),0);
            if(iResult<=0)
            {
                printf("recv failed with error 0: %d/n", WSAGetLastError());
                closesocket(this->tempSocket);
                break;
            }
            iResult=recv(tempSocket,(char*)&length,sizeof(int),0);
            if(iResult!=sizeof(int))
            {
                printf("recv failed with error 1: %d/n", WSAGetLastError());
                closesocket(this->tempSocket);
                break;
            }
            memset(content,0,length+1);
            iResult=recv(tempSocket,content,length,0);
            if(iResult<=0)
            {
                printf("recv failed with error 2: %d/n", WSAGetLastError());
                closesocket(this->tempSocket);
                break;
            }
            lenReaded=length;
            lenLeaved=length-lenReaded;
            if(iResult<length)
            {
                isComplete=false;
            }
        }
        if(lenLeaved<=0)
        {
            isComplete=true;
            SuperSocket::SockData sockData;
            sockData.id=ID;
            sockData.length=length;
            sockData.content=content;
            this->OnReceive(&sockData);
        }
    }
}

void SuperSocket::Send(SuperSocket::SockData* data)
{
    send(tempSocket,(char*)&data->id,sizeof(int),0);
    send(tempSocket,(char*)&data->length,sizeof(int),0);
    send(tempSocket,data->content,data->length,0);
}
