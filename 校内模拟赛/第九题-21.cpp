#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;
const int N = 10010;
#define x first
#define y second 
typedef pair<int, int > PII;
struct Node {
	int x, y, h;
	Node (int x, int y, int h) : x(x), y(y), h(h) {};
	Node () {};
};
PII que[N * N];
Node nums[N];
int dist[N][N];
int n;
int mv[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
void bfs(int sx, int sy) {
	int qtop = 0, qback = 0;
	que[qtop] = PII(sx, sy);
	dist[sx][sy] = 0;
	while (qtop <= qback) {
		PII now = que[qtop++];
		for (int i = 0; i < 4; i++) {
			int nx = now.x + mv[0][i], ny = now.y + mv[1][i];
			if (nx  < 1 || nx > n || ny < 1 || ny > n) continue;
			if (dist[nx][ny] != -1) continue;
			dist[nx][ny] = dist[now.x][now.y] + 1;
		}
	}
}
double getNum(int x1, int y1, int x2, int y2, int h1, int h2) {
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) + (h1 - h2) * (h1 - h2));
}
bool visited[N];
int main() {
	cin >> n;
	double res = 0;
	for (int i = 1; i <= n; i++) cin >> nums[i].x >> nums[i].y >> nums[i].h;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; j <= n; k++) dist[j][k] = -1;
		}
		bfs(nums[i].x, nums[i].y);
		visited[i] = true;
		int minDist = 0x3fffffff;
		int idx = 0;
		for (int j = 1; j <= n; j++) {
			if (!visited[j]) {
				if (minDist > dist[nums[j].x][nums[j].y]) minDist = dist[nums[j].x][nums[j].y], idx = j;
			}
		}
		res += getNum(nums[i].x, nums[i].y, nums[idx].y, nums[idx].y, nums[i].h, nums[idx].h);
	}
	printf("%.2lf", res);
	return 0;
}
