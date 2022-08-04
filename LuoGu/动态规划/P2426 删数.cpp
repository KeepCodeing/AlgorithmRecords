#include <iostream>
#include <cmath>
#include <cstring>
#define endl '\n'
using namespace std;
const int N = 110;
int f[N][N], nums[N];

// 之前的那种写法似乎不能针对区间dp使用，因为区间dp的关键在于区间变化，而不是选择变化..
// 下面给出一种可能是通用的写法 

// dfs的定义：删除[s, e]间的字符串 
int dfs(int s, int e) {
	if (f[s][e] != -1) return f[s][e];
	
	if (s > e) return 0;
	
	int ans = -214748364;
	
	for (int i = s; i <= e; i++) {
		// 起点和终点的价值单独算，注意这里if else顺序不能随便写 
		if (i == s) ans = max(dfs(i + 1, e) + nums[i], ans);
		// 算从i ~ e区间的值，这里起点是s，这里这样写的意思是删除[i + 1, e]这段数，那么终点就是i，起点就是s，下面同样...
		// 也就是从右往左删 
		else ans = max(dfs(i + 1, e) + abs(nums[i] - nums[s]) * (i - s + 1), ans);
		
		if (i == e) ans = max(dfs(s, i - 1) + nums[i], ans);
		// 算从s ~ i区间的值，这里起点是i 
		else ans = max(dfs(s, i - 1) + abs(nums[e] - nums[i]) * (e - i + 1), ans);
	}
	
	return f[s][e] = ans;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> nums[i];
	memset(f, -1, sizeof f);
	cout << dfs(1, n) << endl;
	return 0;
}

/*
79
14 422 61 439 154 228 296 153 346 67 329 276 331 565 79 142 131 137 49 58 78 37 287 288 326 428 322 258 308 233 180 204 552 208 85 138 352 273 343 292 9 214 200 272 413 77 364 28 323 353 448 217 94 106 423 502 126 194 518 46 183 151 127 270 357 489 68 129 412 498 473 84 117 427 160 563 10 91 559

*/

//#include <iostream>
//#include <cmath>
//#include <cstring>
//#define endl '\n'
//using namespace std;
//const int N = 110;
//int f[N][N], nums[N];
//int dfs(int i, int j, string path) {
//	
//	if (f[i][j] != -1) return f[i][j];
//	
//	if (i > j || j < i) {
//		
//		return 0;
//	}
//	
//	if (i == j) {
//		cout << path << endl;
//		cout << "=========" << endl;
//		return f[i][j] = nums[i];
//	}
//	
//	return f[i][j] = max(
//		dfs(i + 1, j, path + (char)(i + '0') + " " + (char)(j + '0') + '\n') + abs(nums[i] - nums[j]) * (j - i + 1), 
//		dfs(j, n, path + (char)(i + '0') + " " + (char)(j + '0') + '\n') + abs(nums[i] - nums[j]) * (j - i + 1)
//	);
//}
//int main() {
//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	int n;
//	cin >> n;
//	for (int i = 1; i <= n; i++) cin >> nums[i];
//	memset(f, -1, sizeof f);
//	cout << dfs(1, n, "");	
//	return 0;
//}
