#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#define endl '\n'
using namespace std;

// 好不容易找到的一个水题...感觉自己除了刷水题也就没别的办法了..还有，不吃饭找题做是个不明智的选择，因为很可能一个题都找不到... 

const int N = 5e4 + 10;
struct Pos {
	int x, y, z;
	bool operator<(const Pos& p) const {
		return z < p.z;
	}
} pos[N]; 
double cpl(int x1, int y1, int z1, int x2, int y2, int z2) {
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) + (z1 - z2) * (z1 - z2));
}
int main() {
//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> pos[i].x >> pos[i].y >> pos[i].z;
	sort(pos, pos + n);
	double res = .0;
	for (int i = 0; i < n - 1; i++) res += cpl(pos[i].x, pos[i].y, pos[i].z, pos[i + 1].x, pos[i + 1].y, pos[i + 1].z);
	printf("%.3lf", res);
	return 0;
}
