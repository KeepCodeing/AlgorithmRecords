#include <iostream>
#include <cstdio>
using namespace std;

// 以前看到这个题想的是完全二叉树一层有2^n (n >= 0)个元素，那么模拟这个步长然后求和就行，结果在模拟比赛里坠毁了w
// 现在想的是建一个二叉树，然后跑BFS..但看了题解才发现这两种思路都很naiveww，尤其是后者，真建树可能时间空间都会有很大
// 笋丝w...聪明的做法是直接求n，即在输入的时候就判断下当前元素是那一层的，然后用一个桶直接把它们加起来，最后通过数据
// 范围可以知道最大深度不超过18... 

const int N = 18;
typedef long long LL;
LL bucket[N];
int getdeep(int n) {
	int deep = 0;
	while (n > 0) deep += 1, n /= 2;
	return deep;
}
int main() {
	int n, num;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &num);
		bucket[getdeep(i)] += num;
	}
	int maxVal = -0x3fffffff, res = 0;
	for (int i = 1; i <= N; i++) {
		if (bucket[i] > maxVal) {
			maxVal = bucket[i];
			res = i;
		}
	}
	printf("%d", res);
	return 0;
}
