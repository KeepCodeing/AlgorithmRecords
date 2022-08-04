#include <iostream>
using namespace std;
const int N = 100;
int nums[N];
int numsz(int x) {
	int cnt = 0, res = 1;
	while (x) x /= 10, cnt++;
	while (cnt--) res *= 10;
	return res;
}
int main() {
	int cnt = 0;
	nums[cnt++] = 0;
	for (int i = 1; i <= 200000; i++) {
		// 平方，然后取模拿后几位...不过没想到这个题居然直接把答案给出来了... 
		if ((i * 1ll * i) % numsz(i) == i) nums[cnt++] = i;
	}
	for (int i = 0; i < cnt; i++) {
		cout << nums[i];
		// 输出两个空格w... 
		if (i != cnt - 1) cout << "  ";
	}
	return 0;
}
