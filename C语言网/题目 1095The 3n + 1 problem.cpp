#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

// 该刷下C语言网的题了（使命感），之前总觉得简单，一天能做十几道，事实上做了蓝桥杯真题之后感觉这种程度的题才是其该刷的... 

int main() {
	int l, r;
	while (scanf("%d%d", &l, &r) != EOF) {
		printf("%d %d ", l, r);
		// 坑，题目没看出来，当l < j时，要对其进行互换... 
		if (l > r) swap(l, r);
		int mlen = 0, tlen = 0;
		for (int i = l, temp = l; i <= r; i++, temp = i) {
			tlen = 1;
			while (temp != 1) {
				
				if (temp % 2) temp = temp * 3 + 1;
				else temp /= 2;
				tlen++;
			}
			mlen = max(mlen, tlen);
		}
		printf("%d\n", mlen);
	}
	return 0;
}
