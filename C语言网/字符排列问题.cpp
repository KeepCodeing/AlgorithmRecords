#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, cnt = 0;
	// ��������n�����˷�����w 
	cin >> n;
	string str;
	cin >> str;
	// ��������.. 
	do {
		cnt++;
	} while(next_permutation(str.begin(), str.end()));
	cout << cnt;
	return 0;
}
