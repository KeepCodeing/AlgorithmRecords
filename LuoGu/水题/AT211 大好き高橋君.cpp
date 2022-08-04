#include <iostream>
using namespace std;

// 今天做的题有点太少了，加上时间也不晚了，写点水题充数 

bool ans(string str) {
	return (str.find("TAKAHASHIKUN") != str.npos || str.find("Takahashikun") != str.npos || str.find("takahashikun") != str.npos);
}

int main() {
	int n, cnt = 0;
	string str;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> str;
		cnt += ans(str);
	}
	cout << cnt << endl;
	return 0;
}
