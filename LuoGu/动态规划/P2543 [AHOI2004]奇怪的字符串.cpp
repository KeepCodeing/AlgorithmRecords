#include <iostream>
using namespace std;

// ����ģ����..��֪���᲻�ᱬ
// û�б�w����ô����Ͱ��ռ�������100����..���������ĸ��⣬ֻ������AC��... 

const int N = 5000 + 10;
int f[N][N]; 
int main() {
	string a, b;
	cin >> a >> b;
	int aLen = a.size(), bLen = b.size();
	for (int i = 1; i <= aLen; i++) {
		for (int j = 1; j <= bLen; j++) {
			if (a[i - 1] == b[j - 1]) f[i][j] = f[i - 1][j - 1] + 1;
			else f[i][j] = max(f[i - 1][j], f[i][j - 1]);
		}
	}
	cout << f[aLen][bLen];
	return 0;
}
