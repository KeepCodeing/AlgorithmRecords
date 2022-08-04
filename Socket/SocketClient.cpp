#include <stdio.h>
#include <winsock2.h>
#include <iostream>
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#pragma comment(lib,"ws2_32.lib")
using namespace std;

struct CarState {
	int carID;
	float angleSpeed, linerSpeed, x, y, angle;
	char navState, carState;
};

class SocketClient {

protected:
    void initWSA();
    SOCKET initLister();

    char ip[20];
    int port;

public:
    CarState getRecv();
    void sendMsg(CarState msg);

    ~SocketClient();
    SocketClient(char ip[], int port);
};

void SocketClient::initWSA() {
    WORD sockVersion;
    WSADATA wsaData;

    sockVersion = MAKEWORD(2, 2);

    if (WSAStartup(sockVersion, &wsaData) != 0) { printf("WSA初始化失败\n");  return; }
}

SOCKET SocketClient::initLister() {
    SOCKET sclient = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sclient == INVALID_SOCKET) { printf("invalid socket !"); return 0; }

    sockaddr_in serAddr;
    serAddr.sin_family = AF_INET;
    serAddr.sin_port = htons(this->port);
    serAddr.sin_addr.S_un.S_addr = inet_addr(this->ip);
    // printf("%s\n", this->ip);

    if (connect(sclient, (sockaddr*)&serAddr, sizeof(serAddr)) == SOCKET_ERROR)
    {
        printf("connect error !");
        closesocket(sclient);
        return 0;
    }
    return sclient;
}

CarState SocketClient::getRecv() {
    SOCKET sclient = this->initLister();
    char recData[255];
    int ret = recv(sclient, recData, 255, 0);
    if (ret > 0)
    {
        recData[ret] = 0x00;
        CarState userMsg;
    	memcpy(&userMsg, recData, sizeof(userMsg));
        return userMsg;
		// printf(recData);
    }
    closesocket(sclient);
    return {};
}

void SocketClient::sendMsg(CarState msg) {
    SOCKET sclient = this->initLister();
    // 不知道为什么不加一个输出服务器端接受不到数据，怀疑是vs的问题
    // printf(msg);
    send(sclient, (char *)&msg, sizeof(msg), 0);
    closesocket(sclient);
}

SocketClient::SocketClient(char ip[], int port) {
    this->initWSA();
    strcpy(this->ip, ip);
    this->port = port;
}

SocketClient::~SocketClient() {
    // closesocket(this->sclient);
    WSACleanup();
}

int main() {
	char ip[] = "192.168.237.133";
	SocketClient sc(ip, 1919);
	char msg[255];
	while (true) {
		CarState userMsg = sc.getRecv();
		printf("%d %.2f %.2f %.2f %.2f %.2f %c %c\n", userMsg.carID, userMsg.angleSpeed, userMsg.linerSpeed, userMsg.x, userMsg.y, userMsg.angle, userMsg.navState, userMsg.carState);
//		cin >> cs.carID >> cs.angleSpeed >> cs.linerSpeed >> cs.x >> cs.y >> cs.angle >> cs.navState >> cs.carState;
		
//		scanf("%s", msg);
		// sc.sendMsg(cs); 
	}
	return 0;
}
// 1 2.0 2.0 2.0 2.0 2.0 0 1
