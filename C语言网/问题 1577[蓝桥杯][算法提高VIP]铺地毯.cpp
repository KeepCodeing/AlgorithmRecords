#include <iostream>
using namespace std;
struct dt {
	int x, y, a, b, id;
	dt() {}
	dt(int x, int y, int id) : x(x), y(y), id(id) {};
};
// 本来就打算纯模拟的，结果IDE里二维数组开下了，OJ里却RE了
// 不过早在洛谷里就做过差不多的题，所以可以用个结构体模拟 
dt d[10010];
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> d[i].x >> d[i].y >> d[i].a >> d[i].b;
		d[i].id = i + 1;
	}
	int x, y;
	cin >> x >> y;
	// 倒着遍历，越后铺的地毯越靠上层 
	for (int i = n - 1; i >= 0; i--) {
		// 只需要判断这个点的坐标是不是在这个地毯的长宽高里就行 
		if (x >= d[i].x && x <= d[i].x + d[i].a && y >= d[i].y && y <= d[i].y + d[i].b) {
			cout << d[i].id;
			return 0;
		}
	}
	cout << -1;
	return 0;
}
