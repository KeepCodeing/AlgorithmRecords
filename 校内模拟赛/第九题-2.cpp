#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
struct Node {
	int x, y, h;
	Node (int x, int y, int h) : x(x), y(y), h(h) {};
	Node () {};
};
const int N = 1010;
Node nums[N];
double minRes = -1;
vector<Node > snnn;
double getNum(int x1, int y1, int x2, int y2, int h1, int h2) {
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) + (h1 - h2) * (h1 - h2));
}
void dfs(int level, int deepth, vector<Node >& snnn) {
	if (level == deepth && snnn.size() == deepth) {
		double mn = 0;
		int sLen = snnn.size();
		for (int i = 0; i < sLen; i++) {
//			mn += getNum(snnn)
		 	cout << snnn[i].x << ' ' << snnn[i].y << endl;
		 	
		}
		cout << "_______" << endl;
		return;
	}
	if (!minRes) return;
	for (int i = level; i < deepth; i++) {
		snnn.push_back(nums[i]); 
		dfs(i + 1, deepth, snnn);
		snnn.pop_back();
	}
}
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> nums[i].x >> nums[i].y >> nums[i].h;
	dfs(0, n, snnn);
	return 0;
}
