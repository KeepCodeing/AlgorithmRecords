#include <iostream>
#include <cstdio>
using namespace std;

// 爆零ww，WA+TLE（绝望） 

const int N = 15;
char graph[N][N];
bool check(int x, int y, char c) {
	return x < 1 || x > 10 || y < 1 || y > 10 || c == '*';
}
void pos(int& x, int& y, int idx) {
	
}
// 四个移动方向，按照转向顺序来 
int move[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
int main() {
	int cx, cy, fx, fy;
	for (int i = 1; i <= 10; i++) {
		for (int j = 1; j <= 10; j++) {
			cin >> graph[i][j];
			if (graph[i][j] == 'F') fx = i, fy = j;
			if (graph[i][j] == 'C') cx = i, cy = j;
		}
	}
	bool flag = false;
	int cnt = 0;
	int tcnt = 0;
	// 表示牛和FJ当前走的方向，如果碰壁或者出界自增，如果自增到4归零 
	int fidx = 0, cidx = 0;
	int txf, tyf, tcx, tcy;
	for (int i = 1; i <= 1e8; i++) {
		txf = fx + move[fidx][0], tyf = fy + move[fidx][1];
		tcx = cx + move[cidx][0], tcy = cy + move[cidx][1];
		tcnt = 0;
		while (check(txf, tyf, graph[txf][tyf])) {
			fidx++, tcnt++;
			if (tcnt >= 5) {
				cout << 0;
				return 0;
			}
			if (fidx >= 4) fidx = 0;
			txf = fx + move[fidx][0], tyf = fy + move[fidx][1];
		}
		tcnt = 0;
		while (check(tcx, tcy, graph[tcx][tcy])) {
			cidx++, tcnt++;
			if (tcnt >= 5) {
				cout << 0;
				return 0;
			}
			if (cidx >= 4) cidx = 0;
			tcx = cx + move[cidx][0], tcy = cy + move[cidx][1];
		}
		fx = txf, fy = tyf;
		cx = tcx, cy = tcy;
		if (fx == cx && fy == cy) {
			flag = true;
			break;
		}
		cnt++;
	}
	if (flag) cout << cnt;
	return 0;
}
