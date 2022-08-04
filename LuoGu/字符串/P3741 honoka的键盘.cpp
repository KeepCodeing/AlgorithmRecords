#include <iostream>
using namespace std;

// 可以对字符串进行一次排序，然后统计V或者K的数量
// 如果数量相等，不改，否则改 
char *str;
int main() {
	int n;
	cin >> n;
	int vCnt = 0, kCnt = 0, minCnt = 0;
	str = new char[n];
	for (int i = 0; i < n; i++) {
		cin >> str[i];
		if (str[i] == 'K') kCnt++;
		else vCnt++;
	}
	if (kCnt && vCnt) minCnt = min(kCnt, vCnt);
	for (int i = 0; i < n; i++) {
		str[i] = str[i] == 'V' ? 'K' : 'V'; 
		for (int j = 0; j < n; j++) {
			
		}
		str[i] = str[i] == 'V' ? 'K' : 'V'; 
	}
	cout << minCnt;
	delete[] str;
	return 0;
}
