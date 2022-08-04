#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, cnt = 0;
	// 忘了输入n贡献了发爆零w 
	cin >> n;
	string str;
	cin >> str;
	// 不用排序.. 
	do {
		cnt++;
	} while(next_permutation(str.begin(), str.end()));
	cout << cnt;
	return 0;
}
