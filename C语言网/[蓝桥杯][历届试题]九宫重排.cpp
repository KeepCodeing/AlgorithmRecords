#include <iostream>
#include <queue>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;

// 大体的思路：每次把字符串映射成二维数组，然后判断.的位置，其附近能交换的点就
// 进行交换，然后把这个二维数组转成字符串继续枚举.. 
// 太暴力都坠毁了... 

typedef pair<string, int > PII;
const int N = 9, M = 1e5 * 5 + 10;
//queue<PII> que;
PII que[M];
map<string, bool > vis;
char graph[N][N], temp[N][N];
int mv[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int bfs(string st, string target) {
	pair<int, int > poi;
//	que.push(PII(st, 0));
	int qtop = 0, qback = 0;
	que[qtop] = PII(st, 0);
	while (qtop <= qback) {
//		PII now = que.front();que.pop();
		PII now = que[qtop++];
		string str = now.first;
		if (str == target) return now.second;
		int cnt = 0;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				graph[i][j] = str[cnt++];
				if (graph[i][j] == '.') poi = pair<int, int >(i, j);
			}
		}
		for (int i = 0; i < 4; i++) {
			int nx = poi.first + mv[i][0], ny = poi.second + mv[i][1];
			if (nx >= 9 || nx < 0 || ny >= 9 || ny < 0) continue;
			memcpy(temp, graph, sizeof graph);
			string stemp;
			swap(temp[nx][ny], temp[poi.first][poi.second]);
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					stemp += temp[i][j];
				}
			}
			if (vis[stemp]) continue;
			vis[stemp] = true;
			que[++qback] = PII(stemp, now.second + 1);
//			que.push(PII(stemp, now.second + 1));
		}
	}
	return -1;
}
int main() {
	string st, target;
	cin >> st >> target;
	cout << bfs(st, target);
	return 0;
}
