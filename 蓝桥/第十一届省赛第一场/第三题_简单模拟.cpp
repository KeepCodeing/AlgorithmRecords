#include <iostream>
using namespace std;
int main() {
	// �Ѽ�ʱ��λ�����룬����õ��� 
	int n = 10000;
	// �ܲ�һ����ʧ10��������Ϣһ��ָ�5����..
	int tot = 0;
	for (int i = 1;; i++) {
		for (int j = 1; j <= 60; j++) {
			n -= 10;
			// ���ð�breakд��������Ļ��������һ��û���ȥ... 
			tot++;
			if (n <= 0) break;
		}
		if (n <= 0) break;
		for (int j = 1; j <= 60; j++) n += 5, tot++;
	} 
	cout << tot << endl;
	return 0;
}
