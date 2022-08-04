#include <stdio.h>
#include <winsock2.h>
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#pragma comment(lib,"ws2_32.lib")

class SocketServer {
protected:
    SOCKET slisten, sClient;

    void initWSA();
    void initLister(int port);
    SOCKET waitConnect();

public:
    int getRecv();
    int sendMsg(char msg[]);

    ~SocketServer();

    SocketServer(int port);
    // bool ConnectToServer(const char* serverip, const int port);
};

void SocketServer::initWSA() {
    WORD sockVersion;
    WSADATA wsaData;
    
    sockVersion = MAKEWORD(2, 2);

    if (WSAStartup(sockVersion, &wsaData) != 0) return;
}

void SocketServer::initLister(int port) {
    sockaddr_in sin;

    sin.sin_family = AF_INET;
    sin.sin_port = htons(port);
    sin.sin_addr.S_un.S_addr = INADDR_ANY;

    this->slisten = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (this->slisten == INVALID_SOCKET) { printf("socket error !"); return; }

    if (bind(this->slisten, (LPSOCKADDR)&sin, sizeof(sin)) == SOCKET_ERROR) { printf("bind error !"); return; }

    if (listen(this->slisten, 5) == SOCKET_ERROR) { printf("listen error !"); return; }

    this->sClient = this->waitConnect();
}

SOCKET SocketServer::waitConnect() {
    SOCKET sClient;
    sockaddr_in remoteAddr;
    int nAddrlen = sizeof(remoteAddr);
    printf("µÈ´ýÁ¬½Ó...\n");
    sClient = accept(slisten, (SOCKADDR*)&remoteAddr, &nAddrlen);

    if (sClient == INVALID_SOCKET) { printf("accept error !"); return NULL; }

    return sClient;
}

int SocketServer::getRecv() {
    // SOCKET sClient = this->waitConnect();
    char revData[255];

    int ret = recv(this->sClient, revData, 255, 0);

    if (ret > 0)
    {
        revData[ret] = 0x00;
        printf(revData);
    }
    return 0;
}

int SocketServer::sendMsg(char msg[]) {
    // SOCKET sClient = this->waitConnect();

    send(this->sClient, msg, strlen(msg), 0);

    return 0;
}

SocketServer::SocketServer(int port) {
    this->initWSA();
    this->initLister(port);
}

SocketServer::~SocketServer() {
    closesocket(this->slisten);
    WSACleanup();
}

int main() {
	
	return 0;	
}
