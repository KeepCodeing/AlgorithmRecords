#include <iostream>
using namespace std;

// �Ӻ���ǰ��ȡ�ַ���Ȼ����һ���ַ��в��ң������
// ���һ�γ��ֵ��ַ������������ 

int main() {
	string a, b;
	string aTemp1, aTemp2;
	int minLen = 0, index = 0;
	cin >> a >> b;
	for (int i = min(a.size(), b.size()); i > 0; i--) {
		// �Ӻ���ǰ��ȡ 
		aTemp1 = a.substr(0, i);
		// �ӵ�ǰ�±������ȡ������ˮ����������ûд���
		// ��Ȼ������90w 
		aTemp2 = a.substr(index);
		if (b.find(aTemp1) != b.npos) {
			minLen = aTemp1.size();
			break;
		} else if (b.find(aTemp2) != b.npos) {
			minLen = aTemp2.size();
			break;
		}
		index++;
	}
	cout << minLen;
	return 0;
}
