#include <iostream>
using namespace std;

// 一道基本搜索题，明明地图还蛮大的，居然不会超时 
// 为了防止漏点，应该可以在外层加一圈 

// 原来DFS只有走迷宫的时候需要回溯将标记的点取消标记，在染色的时候可以不用取消标记 

int height, weight;
// 转换成数字地图方便判断 
int m[550][550];
void dfs(int x, int y) {
	// <0和+1是作为假定的外层的厚度 
	if (x < 0 || x > height + 1 || y < 0 || y > weight + 1) return;
	if (m[x][y] != 0) return;
	// 标记访问过的0 
	m[x][y] = 1;
	dfs(x + 1, y);
	dfs(x - 1, y);
	dfs(x, y + 1);
	dfs(x, y - 1);
	// 还原似乎不是必须的，这个毕竟不存在回退的情况 
	// m[x][y] = 1;
	
}
int main() {
	char temp;
	cin >> height >> weight;
	for (int i = 1; i <= height; i++) {
		for (int j = 1; j <= weight; j++) {
			cin >> temp;
			if (temp == '*') m[i][j] = 1;
			else m[i][j] = 0;
		}
	}
	dfs(0, 0);
	int cnt = 0;
	for (int i = 1; i <= height; i++) {
		for (int j = 1; j <= weight; j++) {
			if (m[i][j] != 1) cnt++;
		}
	}
	cout << cnt;
	return 0;
}
