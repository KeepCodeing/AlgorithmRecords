#include <iostream>
#define endl '\n'
using namespace std;
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, maxCnt = 0;
	string str;
	cin >> n >> str;
	for (int i = 0; i < n - 1; i++) {
		if (str[i] == 'V' && str[i + 1] == 'K') maxCnt++;
	}	
	for (int i = 0; i < n - 1; i++) {
		if (str[i] == str[i + 1]) {
			maxCnt++;
			break;
		}
	}
	cout << maxCnt << endl;
	return 0;
}
