#include <iostream>
using namespace std;

// 啊啊啊，第18道水题了，刷了两天...总之题面没有一开始那么难以看懂了...刷完20题
// 应该可以挑战下更难的题了...接下来是高数，数电，离散考试，后两者没什么底的样子呢w... 

int main() {
	int n, a, b, cnt = 0;
	cin >> n;
	while (n--) {
		cin >> a >> b;
		if (b - a >= 2) cnt++;
	}
	cout << cnt << endl;
	return 0;
}
