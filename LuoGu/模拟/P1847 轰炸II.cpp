#include <iostream>
#include <cstdio>
using namespace std;

// 第一次交写成n，m了（实际是m，n）居然只WA了一个点w，太奇妙了...
// 和那个铺地毯的题类似，把左上角右下角的坐标存起来，判断下当前点在不在里面就行... 

const int M = 2010;
struct Node {
	int x1, y1, x2, y2;
	Node (int x1, int y1, int x2, int y2) : x1(x1), y1(y1), x2(x2), y2(y2) {};
	Node () {};
};
Node pos[M];
int main() {
	int n, m;
	// n，m写反了，只看样例按自己习惯来果然不行，还是得按题目给的顺序来（样例m==n，从测试点来看只有一个点不是这样w） 
	scanf("%d%d", &m, &n);
	for (int i = 1; i <= m; i++) scanf("%d%d%d%d", &pos[i].x1, &pos[i].y1, &pos[i].x2, &pos[i].y2);
	int x, y, cnt, pre;
	while (n--) {
		scanf("%d%d", &x, &y), cnt = 0, pre = 0;
		for (int i = 1; i <= m; i++) {
			// 这个错了，砸到边界点上不算... 
			if (pos[i].x1 < x && pos[i].y1 < y && pos[i].x2 > x && pos[i].y2 > y) cnt++, pre = i;
		}
		if (cnt) printf("YES %d %d\n", cnt, pre);
		else printf("NO\n");
	}
	return 0;
}
