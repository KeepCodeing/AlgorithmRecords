#include <iostream>
using namespace std;

// ���������������ʱ��֪����ô���ģ���ֻ֮���������֣��ʶ�����
// ��Ͱ��˼������ִ�����Ȼ����� 

int bucket[5];
int main() {
	char c;
	bool flag = false;
	while (cin >> c) {
		if (c != '+') bucket[c - '0']++;
	}
	for (int i = 1; i <= 3; i++) {
		while (bucket[i]--) {
			
			if (flag) cout << '+';
			cout << i, flag = true;
		}
	}
	return 0;
}
