#include <iostream>
using namespace std;

// �þ���ǰ׹�ٵ���w����֪��������û�г�����w.. 
// all right..����WA��һ������Ϊû�㶮��Ŀ����n����˼w�����nӦ��ֻ��������־���У�������˵������n*2��Ԫ��... 

int main() {
	int tt, ct = 0;
	bool flag = false;
	int n, t, cnt = 0;;
	cin >> n;
	// ����ֱ��д������t�������ˣ���һ����n*2������... 
	while (cin >> t) {
		while (t--) {
			// ��ǰ̫naive��֪��boolҲ�������������֪��boolw�� 
			cout << flag;
			// ���� 
			cnt++;
			if (cnt == n) {
				cout << endl;
				cnt = 0;
			}
		}
		// תΪ�෴�ַ�... 
		flag = !flag;
	}
	return 0;
}

