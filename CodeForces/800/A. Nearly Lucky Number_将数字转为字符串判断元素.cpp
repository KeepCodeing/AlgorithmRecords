#include <iostream>
using namespace std;

// ��������w����ĿҪ�����һ�����ְ���4��7�ĸ����ǲ���4����7����������һ�������ǲ���
// ֻ��4��7... 

int main() {
	int cnt = 0;
	string num;
	cin >> num;
	for (int i = 0; i < num.size(); i++) {
		if (num[i] == '4' || num[i] == '7') cnt++;
	}
	if (cnt == 4 || cnt == 7) cout << "YES";
	else cout << "NO";
	cout << endl; 
	return 0;
}
