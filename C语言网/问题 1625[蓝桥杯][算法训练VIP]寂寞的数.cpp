#include <iostream>
using namespace std;

// 一个人刷题好寂寞啊↑
// 怕出界用map存了，但是好像又不用，判断每位还有数字和的时候判断下是否超过n就能免去
// 不必要的标记 

int getNum(int x) {
	int res = 0;
	int xt = x;
	while (x) {
		res += x % 10;
		x /= 10;
	}
	// 谔谔，之前池沼了，居然返回的是res+x，但x已经除完了... 
	return res + xt;
}
bool nums[10010];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	// 题目要求的是小于n的寂寞的数 
	for (int i = 1; i < n; i++) {
		int r = getNum(i);
		if (r >= n) continue;
		nums[r] = true;
	}
	for (int i = 1; i < n; i++) {
		if (!nums[i]) cout << i << endl;
	}
	return 0;
}
