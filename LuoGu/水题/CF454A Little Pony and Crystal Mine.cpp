#include <iostream>
#include <cstdio>
using namespace std;

// ˮ��ڶ�ʮ������һ˲���ֻص��˸�ѧC�Ƕ�ʱ��ĸо�����ʱ��ӡ����ľ������ֻ�ͼ���ˣ��������Զ�����������ܳ�ʱ��...
// ����з�����... 

int main() {
	int n, l, r, val = 1, line;
	scanf("%d", &n);
	l = r = line = (n / 2) + 1;
	cout << line << endl;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (j >= l && j <= r) cout << "D";
			else cout << "*";
		}
		// ע��ִ����δ���ǰȫ��D����һ���Ѿ��������� 
		if (i >= line) val = - 1;
		l -= val, r += val;
		puts("");
	}
	return 0;
}
//#include <iostream>
//#include <cstdio>
//using namespace std;
//int main() {
//	int n, l, r, val = 1, line;
//	scanf("%d", &n);
//	l = r = line = (n >> 1) + 1;
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= n; j++) {
//        	cout << (j >= l && j <= r ? 'D' : '*');
//		}
//		if (i >= line) val = - 1;
//		l -= val, r += val;
//		puts("");
//	}
//	return 0;
//}
