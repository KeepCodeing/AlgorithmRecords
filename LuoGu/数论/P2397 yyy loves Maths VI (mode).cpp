#include <iostream>
#include <cstdio>
using namespace std;

// 摩尔投票法，不多谈！ 

int main() {
	int n;
	scanf("%d", &n);
	int vote = 0, res = 0;
	int t;
	while (n--) {
		scanf("%d", &t);
		// 默认一个众数 
		if (!vote) res = t;
		// 出现别的数该总数权重减一 
		if (res != t) vote--;
		// 否则权重增加，最后留下来的一个数就是众数 
		else vote++;
	}
	printf("%d", res);
	return 0;
}
