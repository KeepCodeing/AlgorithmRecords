#include <iostream>
using namespace std;

// ˮ���������������ˢˮ������ε����Ƿ�... 

const int N = 1000 + 10;
string strs[N];
int main() {
	int n, idx;
	cin >> n;
	bool flag = false;
	for (int i = 0; i < n; i++) {
		cin >> strs[i];
		if ((idx = strs[i].find("OO")) != strs[i].npos && !flag) {
			flag = true;
			strs[i][idx] = '+', strs[i][idx + 1] = '+';
		}
	}
	if (!flag) {
		cout << "NO";
		return 0;
	}
	cout << "YES" << endl;
	for (int i = 0; i < n; i++) {
		cout << strs[i] << endl;
	}
	return 0;
}
