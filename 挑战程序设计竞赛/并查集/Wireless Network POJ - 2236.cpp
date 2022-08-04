#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// 开始选择性刷挑战的题了，动规不会，贪心也可以往后稍稍...这个题就是并查集裸题...（不是这样的吧）
// POJ的题似乎更难一些，这个题不是裸题，这个题给出了所有点的坐标，然后要求所有距离不超过D的电脑
// 才能连接。而所谓的维修操作就是将当前点能连接的所有点加入到并查集里，所以可以像最小生成树那样
// 先把所有点的距离给算出来，然后把距离合法的点筛选出来，维修就直接连边。这里可以采用类似vector
// 邻接表的思想，当前点作为顶点，然后把所有能和它相邻的点存起来... 

// 不知道为什么疯狂RE，可能是邻接表的问题... 

typedef pair<int, int > PII;
const int N = 1001 + 10;
bool fixedNode[N];
// 存边的邻接表 
vector<int > graph[N];
// 先把输入的点存起来
vector<PII > poi;
bool check(int x1, int y1, int x2, int y2, int d) {
	return sqrt((x1 - x2 + .0) * (x1 - x2) + (y1 - y2) * (y1 - y2)) <= d +.0; // d是最大通信范围，不是至少距离为d... 
}
struct unionFind {
	int bin[N];
	unionFind () {
		for (int i = 0; i < N; i++) bin[i] = i;
	}
	int anc(int x) {
		if (x != bin[x]) bin[x] = anc(bin[x]);
		return bin[x];
	}
	void uni(int x, int y) {
		bin[anc(x)] = y;
	}
	bool ask(int x, int y) {
		return anc(x) == anc(y);
	}
};
unionFind u;
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, d;
	cin >> n >> d;
	int x, y;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		poi.push_back(PII(x, y));
	}
	// 算当前点能到那些点
	int pLen = poi.size();
	for (int i = 0; i < pLen; i++) {
		for (int j = i + 1; j < pLen; j++) {
			if (check(poi[i].first, poi[i].second, poi[j].first, poi[j].second, d)) {
				// 计算机的编号从1开始 
				graph[i + 1].push_back(j + 1); 
			}
		}
	}
	char op;
	while (cin >> op) {
		if (op == 'O') {
			cin >> x;
			// 不能重复添加，否则会RE 
			if (fixedNode[x]) continue;
			fixedNode[x] = true;
			for (int i = 0; i < graph[x].size(); i++) u.uni(x, graph[x][i]);
		} else {
			cin >> x >> y;
			cout << (u.ask(x, y) ? "SUCCESS" : "FAIL") << endl;
		}
	} 
	return 0;
}
