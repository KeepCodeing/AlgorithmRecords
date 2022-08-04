#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

// 果不其然坠毁了w，这里考虑的是先过期的就先卖出去，根据价格决定当天卖那个商品，然而我们也可以提前卖出价值更高的
// 商品而放弃要过期的商品... 

const int N = 10000 + 10;
struct elements {
	int val, day;
	bool operator<(const elements& e) const {
		if (e.day != day) return day < e.day;
		return val > e.val;
	}
} ele[N];
int main() {
	int n, preday, res;
	while (~scanf("%d", &n)) {
		preday = -1, res = 0;
		for (int i = 0; i < n; i++) scanf("%d%d", &ele[i].val, &ele[i].day);
		sort(ele, ele + n);
		for (int i = 0; i < n; i++) {
			if (ele[i].day != preday) {
				res += ele[i].val;
				preday = ele[i].day;
			}
		}
		printf("%d\n", res);
	}
	return 0;
}
/*
7
20 1
2 1
100 2
80 2
10 3
50 10
5 20
245


7
10 1
2 1
100 2
8 2
10 3
50 10
5 20
175

7
10 1
2 1
100 2
80 2
10 3
50 10
5 20
245

8
20 1
100 6
100 6
100 6
100 6
100 6
100 6
100 6
600
*/
