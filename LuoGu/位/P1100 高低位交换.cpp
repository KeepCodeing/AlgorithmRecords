#include <iostream>
#include <cstdio>
#include <bitset>
using namespace std;
using std::bitset;
typedef unsigned long long ULL;
int main() {
	ULL n;
	cin >> n;
	bitset<32 > t(0);
	bitset<32 > bt(n);
	for (int i = 0; i < 16; i++) {
		bool temp = bt[i];
		bt[i] = bt[i + 16];
		bt[i + 16] = temp;	
	}
	// �÷���C++11�ſ�ʹ��... 
	cout << bt.to_ullong();
	return 0;
}
// 1314520
