#include <iostream>
using namespace std;
int main() {
	/*���˼·������1��һ�֣�����Ҳ��1�֣�3���������֣�����4������1��1�ּ�����1�ּ�3��+1��һ�֣�*/ 
	int f[100];
	f[0] = f[1] = f[2] = 1;
	f[3] = 2;
	for (int i = 4; i <= 30; i++) {
		f[i] = f[i - 1] + f[i - 3];
	}
	cout << f[30] << endl;
	return 0;
}
