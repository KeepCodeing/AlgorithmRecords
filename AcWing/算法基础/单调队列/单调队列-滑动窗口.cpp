#include <iostream>
#include <cstdio>
using namespace std;

// 滑动窗口是队列优化的经典形式，另外STL的队列速度较慢
// 使用数组模拟更好 

const int N = 1000010;
int n, k;
int q[N], num[N];
int main() {
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) scanf("%d", &num[i]);
	// hh表示当前元素下标，tt表示队里元素下标 
	int hh = 0, tt = -1;
	for (int i = 0; i < n; i++) {
		// 判断队头是否已经滑出窗口（这里之所以不用while是因为每次滑动只需要移动一个元素） 
		if (hh <= tt && i - k + 1 > q[hh]) hh++;
		// 当窗口还没有滑动出去并且当前元素大于新添加的元素，就将更大的元素出队 
		while (hh <= tt && num[q[tt]] >= num[i]) tt--;
		// 入队下一个元素，要注意这里在输出前入队是为了保证输出的是窗口滑动后的最小值 
		q[++tt] = i;
		// 窗口滑动完了，最后队头元素就是最小的元素 
		if (i >= k - 1) printf("%d ", num[q[hh]]);
	}
	puts("");
	return 0;
}
/*
输入样例
8 3
1 3 -1 -3 5 3 6 7

输出样例
-1 -3 -3 -3 3 3
3 3 5 5 6 7
*/
