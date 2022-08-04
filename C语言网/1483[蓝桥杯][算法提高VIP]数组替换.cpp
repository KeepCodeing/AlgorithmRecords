#include <iostream>
using namespace std;

// 坑点就是如何判断a里面有多少个元素，如果没有更好的办法
// 遍历遍然后标记下就行 

void  Add(int a[], int m, int b[], int n) {
	int s = 1;
	// 因为说是从a[m]开始用b[n]替换，所以将n个元素依次换就行了 
	while (s <= n) a[m++] = b[s++];
}
int *a, *b;
int main() {
	int m, n;
	cin >> m >> n;
	a = new int[m + n + 5]();
	b = new int[n + 5]();
	// 填充a，如果不是这个值就说明后面没元素了 
	fill(a, a + m + n + 5, 0x3FFFFFFF);
	for (int i = 1; i <= m; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> b[i];
	int start, end;
	cin >> start >> end;
	// 从样例看出来的start + 1 
	Add(a, start + 1, b, end);
	int t = 1;
	// 统计a里面有多少个元素 
	while(a[t] != 0x3FFFFFFF) t++;
	// 依次输出
	for (int i = 1; i <= t - 1; i++) {
		cout << a[i];
		if (i != t - 1) cout << ',';
	}
	delete[] a, b;
	return 0;
}
