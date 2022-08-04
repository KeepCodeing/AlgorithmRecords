#include <iostream>
#include "LRU_lib.h"
#include "FIFO.h"
#define endl '\n'
using namespace std;
int main() {
	string name;
	cout << "请输入要测试的算法名称(LRU/FIFO):";
	while (cin >> name && name != "LRU" && name != "FIFO") cout << "输入有误，请重新输入:";
	cout << "系统调用算法:" << name << " 结果如下" << endl;
	name == "LRU" ? LRU() : FIFO();
	return 0;
}
