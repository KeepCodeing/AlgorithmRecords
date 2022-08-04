#include <iostream>
#include <cstdio>
using namespace std;

// 早上到现在以为洛谷网站爆了，没想到只是其自己爆了，差点就断了打卡了..也有两天没水题了， 这个题做过了，传递闭包w
// 最近大多数刷的是vjudge上的题，有些题是那上面刷了才知道洛谷的做法..相对来说没洛谷上那么浮躁w，不知道是不是没什么
// 好比的（指AC率之类的w）... 

const int N = 110;
int n, m, ut, vt;
int graph[N][N];
int main() {
	scanf("%d%d", &n, &m);
	while (m--) {
		scanf("%d%d", &ut, &vt);
		graph[ut][vt] = 1;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				// 似乎下午做的晚上就忘了w，这里就当套模板算了... 
				if (graph[j][i] && graph[i][k]) graph[j][k] = 1;
			}
		}
	}
	int res = 0, cnt = 0;
	for (int i = 1; i <= n; i++) {
		cnt = 0;
		for (int j = 1; j <= n; j++) {
			if (graph[i][j] || graph[j][i]) cnt++;
		}
		if (cnt == n - 1) res++;
	}
	printf("%d", res);
	return 0;
}
