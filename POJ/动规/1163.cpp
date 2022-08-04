#include <iostream>
using namespace std;
int nums[105][105];
int maxSum[105][105];
// 记忆化 
int visited[105][105];
int n;

// 思路就是判断选左下的大还是右下的大 

int rec(int i, int j) {
	if (visited[i][j] != -1) return visited[i][j];
	// 到了最低层就没数可选了，最大值即其自身 
	if (i == n - 1) {
		visited[i][j] = nums[i][j];
	} else {
		visited[i][j] = max(rec(i + 1, j), rec(i + 1, j + 1)) + nums[i][j];
	}
	return visited[i][j];
	// 选左下的数 
//	int x = rec(i + 1, j);
//	// 选右下的数 
//	int y = rec(i + 1, j + 1);
//	// 判断最优解 
//	return max(x, y) + nums[i][j];
} 

int main() {
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> nums[i][j];
			visited[i][j] = -1;
		}
	}
	// 相比递归写法更快了 
	// 动规写法:从下往上推，看起来起始下标为1能省去很多麻烦... 
	for (int i = 0; i < n; i++) maxSum[n - 1][i] = nums[n - 1][i];
	for (int i = n - 2; i >= 0; i--) {
		for (int j = 0; j <= i; j++) {
			maxSum[i][j] = max(maxSum[i + 1][j], maxSum[i + 1][j + 1]) + nums[i][j];
		}
	} 
	cout << maxSum[0][0];
	return 0;
}
