#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
#define x first
#define y second
typedef pair<int, int > PII;
const int N = 40, PI = 3.1415926;
int graph[N][N];
vector<PII > vec, res;
int maxSize = -1;
int getDist(int x1, int y1, int x2, int y2) {return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));}
void dfs(int level, int deepth) {
	if (level == deepth) {
		// cout << res[i].x << ' ' << res[i].y << endl;
		// cout << "_______" << endl;
		int rLen = res.size(), x1, y1, x2, y2;
		int sizetemp;
		for (int i = 0; i < rLen; i++) {
			x1 = res[i].x, y1 = res[i].y;
			sizetemp = 0;
			for (int j = 0; j < rLen; j++) {
				if (i == j) continue;
				x2 = res[j].x, y2 = res[j].y;
				if (getDist(x1, y1, x2, y2) >= graph[x1][y1] + graph[x2][y2]) {
					sizetemp += graph[x2][y2] * graph[x2][y2];
				}
			}
			//sizetemp += graph[x1][y1] * graph[x1][y1];
			maxSize = max(maxSize, sizetemp);
		}
		return;
	}
	for (int i = level; i < deepth; i++) {
		res.push_back(vec[i]); 
		dfs(i + 1, deepth);
		res.pop_back();
	}
}
int main() {
	int n, x, y, w;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> x >> y >> w, graph[x][y] = w, vec.push_back(PII(x, y));
	dfs(0, n);
	cout << maxSize;
	return 0;
}
