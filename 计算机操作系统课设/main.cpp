#include <iostream>
#include "LRU_lib.h"
#include "FIFO.h"
#define endl '\n'
using namespace std;
int main() {
	string name;
	cout << "������Ҫ���Ե��㷨����(LRU/FIFO):";
	while (cin >> name && name != "LRU" && name != "FIFO") cout << "������������������:";
	cout << "ϵͳ�����㷨:" << name << " �������" << endl;
	name == "LRU" ? LRU() : FIFO();
	return 0;
}
