#include <iostream>
#include <vector>
using namespace std;

// 其实就是个全排列，考虑当信封数为3时，条件为
// index1 != 1, index2 != 2, index3 != 3，这也就是说
// 我们生成了全排列后只需要对比是不是有某个排列的数字和该下标不相同即可
// 可以把信封的装法看成全排列，要求不同就是所有数字都不在原有位置上 

// 爆搜毫无疑问坠毁了，只能搜到10左右，这个题实际是个
// 递推题已经处理了f[0]~f[n-1],考虑f[n],新来了一个数n，
// 这个数要放错位，有n-1种情况。其他的数的放置每次都有f[n-1]
// 种情况，被n占用位置的数k，将k放在n位置，可以再多出f[n-2]种情况。 

vector<int > vec;
bool visited[25];
long long cnt = 0;
void dfs(int level, int deepth) {
	if (level == deepth + 1) {
		bool flag = true;
		for (int i = 0; i < vec.size(); i++) {
			if (vec[i] == i + 1) {
				flag = false;
				break;
			}
		}
		if (flag) cnt++;
		return;
	}
	for (int i = 1; i <= deepth; i++) {
		if (!visited[i]) {
			visited[i] = true;
			vec.push_back(i);
			dfs(level + 1, deepth);
			vec.pop_back();  
			visited[i] = false;
		}
	}
}
long long result[25];
int main() {
	int n;
	cin >> n;
	// dfs(1, n);
	result[0] = 1, result[1] = 0;
	for (int i = 2; i <= n; i++) result[i] = (i - 1) * (result[i - 2] + result[i - 1]);
	cout << result[n];
	return 0;
} 
