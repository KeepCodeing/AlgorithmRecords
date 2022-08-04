#include <iostream>
using namespace std;

// 分析：对于n个元素的集合来说，它的子集一定有2^n个，比如{1, 2, 3}，它有8个子集，而如果用二进制位来
// 表示某个元素是否存在于某个子集中，只需要检测某个位是否为1即可 

int main() {
	int n;
	int collection[] = {1, 2, 3};
	cin >> n;
	// 对应2^n个集合 
	for (int i = 0; i < (1<<n); i++) {
		// 打印一个子集，即打印i里有多少个1 
		for (int j = 0; j < n; j++) {
			// 从i的最低位开始检测，如果某位是1，打印集合
			if (i & (1<<j)) cout << collection[j] << ' '; 
		}
		cout << endl;
	}
	return 0;
}
