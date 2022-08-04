#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

// 贪心，选择越早结束的会议越能接近最优解.. 

const int N = 1e6 + 10;
struct Node {
	int s, e;
	bool operator<(const Node& n) {
		if (e != n.e) return e < n.e;
		return s < n.s;
	}
} node[N];
int main() {
	int n, res = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d%d", &node[i].s, &node[i].e);
	for (int i = 0; i < n - 1; i++) {
		if (node[i].e >= node[i + 1].s) {
			res++;
		} else {
			
		}
	}
	printf("%d\n", res);
	return 0;
}
