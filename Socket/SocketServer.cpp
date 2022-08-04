#include <stdio.h>
#include <winsock2.h>
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#pragma comment(lib,"ws2_32.lib")

struct CarState {
	int carID;
	float angleSpeed, linerSpeed, x, y, angle;
	char navState, carState;
};

struct PosMsg {
	float x, y;
};

class SocketServer {
protected:
    SOCKET slisten;

    void initWSA();
    void initLister(int port);
    SOCKET waitConnect();

public:
    CarState getRecv();
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
}

SOCKET SocketServer::waitConnect() {
    SOCKET sClient;
    sockaddr_in remoteAddr;
    int nAddrlen = sizeof(remoteAddr);
    // printf("µÈ´ýÁ¬½Ó...\n");
    sClient = accept(slisten, (SOCKADDR*)&remoteAddr, &nAddrlen);

    if (sClient == INVALID_SOCKET) { printf("accept error !"); return NULL; }

    return sClient;
}

CarState SocketServer::getRecv() {
    SOCKET sClient = this->waitConnect();
    char revData[255];

    int ret = recv(sClient, revData, 255, 0);

    if (ret > 0)
    {
    	CarState userMsg;
    	memcpy(&userMsg, revData, sizeof(userMsg));
        revData[ret] = 0x00;
        return userMsg;
		// printf("%d %.2f %.2f %.2f %.2f %.2f %c %c\n", userMsg.carID, userMsg.angleSpeed, userMsg.linerSpeed, userMsg.x, userMsg.y, userMsg.angle, userMsg.navState, userMsg.carState);
    }
    return {};
}

int SocketServer::sendMsg(char msg[]) {
    SOCKET sClient = this->waitConnect();

    send(sClient, msg, strlen(msg), 0);

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
	SocketServer ss(1919);
	while (true) {
		CarState userMsg = ss.getRecv();
		printf("%d %.2f %.2f %.2f %.2f %.2f %c %c\n", userMsg.carID, userMsg.angleSpeed, userMsg.linerSpeed, userMsg.x, userMsg.y, userMsg.angle, userMsg.navState, userMsg.carState);
	}
	return 0;
}
