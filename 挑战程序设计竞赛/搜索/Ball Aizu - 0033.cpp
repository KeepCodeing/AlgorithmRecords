#include <iostream>
#include <cstdio>
using namespace std;

// ���������⣬��������Ϊֻ������״̬�գ���������ģ��͹��ˣ�Ҳ����Ϊֻ������״̬... 

int main() {
	int n, x, pre1, pre2;
	scanf("%d", &n);
	bool flag;
	while (n--) {
		flag = true;
		pre1 = -1, pre2 = -1;
		int i;
		for (i = 0; i < 10; i++) {
			scanf("%d", &x);
			if (i == 0) pre1 = x;
			else if (i == 1) pre2 = x;
			else {
				if (flag) {
					if (x < pre1) {cout << "NO";break;}
					pre1 = x;
				} else {
					if (x < pre2) {cout << "NO";break;}	
					pre2 = x;
				}
				flag = !flag;
			}
		}
		if (i == 10) cout << "YES";
		cout << endl;
	}
	return 0;
}
