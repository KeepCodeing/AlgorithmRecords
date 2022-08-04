#include <iostream>
using namespace std;

// 数据量不大似乎都可以考虑无脑枚举.. 
// 坠毁，大概是因为其答案多了一倍 

char graph[105][105];
int main() {
	int r, c, k;
	cin >> r >> c >> k;
	// 下标果然还是尽量从1开始，因为k不是从0开始计的 
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			cin >> graph[i][j];
		}
	}
	int ans = 0;
	// 起始位置也算，所以这样做可以简单点 
	k--;
	// 对每个点都判断下能不能站
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			if (graph[i][j] != '#') {
				// 可能存在的特殊情况，因为其上面k自减了 
				if (k <= 0) {
					ans++;
					continue;
				} 
				// 出界判断
				// if (i + k >= r || i - k < 0 || j + k >= c || j - k < 0) continue; 
				// 上  
				int up = i - k, down = i + k, left = j - k, right = j + k;
				int t;
				if (up >= 1) {
					for (t = i; t >= up; t--) {
						if (graph[t][j] != '.') break;
					}
					if (t < up) ans++;
					// cout << i << ' ' << j << endl;
				}
				// 下
				if (down <= r) {
					for (t = i; t <= down; t++) {
						if (graph[t][j] != '.') break;
					}
					if (t > down) ans++;
				} 
				// 左
				if (left >= 1) {
					for (t = j; t >= left; t--) {
						if (graph[i][t] != '.') break;
					}
					if (t < left) ans++;
				} 
				// 右 
				if (right <= c) {
					for (t = j; t <= right; t++) {
						if (graph[i][t] != '.') break;
					}
					if (t > right) ans++;
				}
			}
		}
	} 
	cout << ans / 2;
	/*
		.###.
		##.#.
		..#..
		#..#.
		#.###
	*/
	return 0;
}
