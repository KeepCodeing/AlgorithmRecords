#include <iostream>
using namespace std;

// ���˰�����Ŀ����Ŀ��˼�����ж����Ƿ���ż��.. 
// Ȼ��׹���ˣ��ֿ��˱���Ŀ������Ҫ������жϵ�ǰ������ܲ��ܱ�ż����ɣ�������Ҫ�������������... 

int main() {
	bool flag = false;
	int num;
	cin >> num;
	if (num > 2 && !(num % 2)) flag = true;
	cout << (flag ? "YES" : "NO") << endl;  
	// �����ȷʵ��ż�����ܱ��ֳ����룬����Ҫע��2���ܱ��ֳ�����ż���ĺ�.. 
//	for (int i = 1; i <= 100; i++) {
//		flag = false;
//		for (int j = 2; j < i; j += 2) {
//			if (!((i - j) % 2)) flag = true;
//		}
//		// num >= 1���ʶ�û������... 
//		cout << i << ' ' << (flag ? "YES" : "NO") << endl;
//	}
	return 0;
}
