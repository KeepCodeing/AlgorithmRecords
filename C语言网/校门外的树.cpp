#include <iostream>
#include <cstdio>
using namespace std;
const int N = 10000 + 10;
int nums[N];
int main() {
	int sz, n, l, r, cnt = 0;
	scanf("%d%d", &sz, &n);
	while (n--) {
		scanf("%d%d", &l, &r);
		for (int i = l; i <= r; i++) nums[i] = 1;
	}
	// 记得好久之前做一直WA，而且想不明白为什么，然后才发现起点从0开始，而其却是从1开始的w.. 
	for (int i = 0; i <= sz; i++) {
		if (!nums[i]) cnt++;
	}
	printf("%d", cnt);
	return 0;
}
