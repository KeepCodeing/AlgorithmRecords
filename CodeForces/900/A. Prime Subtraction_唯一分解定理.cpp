#include <iostream>
using namespace std;

// ���۵Ķ�������һ������1����Ҫô�������Ǹ�������Ҫô����Ա���ʾΪ���ɸ������ĳ˻�...�ʶ�������ж��²��Ƿ�С�ڵ���һ��������... 

typedef long long LL;
int main() {
	int T;
	LL x, y;
	cin >> T;
	while (T--) {
		cin >> x >> y;
		if (x - y <= 1) cout << "NO";
		else cout << "YES";
		cout << endl;
	}
	return 0;
}
