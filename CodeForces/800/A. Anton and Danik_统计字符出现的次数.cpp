#include <iostream>
using namespace std;

// �����ø���������Ϊ�����ܾ����������о��鷳���ʴ���������������w 

int main() {
	int n, a, b;
	char c;
	// ���ǳ�ʼ��������ı���ֵ��ȷ��... 
	a = b = 0;
	cin >> n;
	while (n--) {
		cin >> c;
		if (c == 'A') a++;
		else b++;
	}
	if (a > b) cout << "Anton";
	else if (a < b) cout << "Danik";
	else if (a == b) cout << "Friendship";
	cout << endl;
	return 0; 
}
