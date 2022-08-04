#include <iostream>
#include <cstdio>
using namespace std;

// 这个题其实设计到了离散数学的图论知识，传递闭包。简单来说传递闭包就是指将一个点所有直接和间接相连的点都连到自己身上
// 也就是类似并查集里的路径压缩，如果将当前节点看做根节点，那么传递闭包做的就是将其所有子节点连到它自己身上。那么这个
// 题要判断排名，可以用floyd跑一次传递闭包，然后如果这个点和其它点都有联系，就说明其排名是可以确定的... 

const int N = 100 + 10;
int graph[N][N];
int main() {
	int n, m, ut, vt;
	scanf("%d%d", &n, &m);
	while (m--) {
		scanf("%d%d", &ut, &vt);
		// 连边，注意是单向边 
		graph[ut][vt] = 1;
	}
	// floyd板子 
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				// 用graph[j][i]表示比当前点分数大的点，graph[i][k]表示比当前点分数小的点，然后统计这个点
				// 是否能够确定排名 
				// 注意这里是只判断又没有联系，有联系才改变图，没联系就不操作... 
				if (graph[j][i] && graph[i][k]) graph[j][k] = 1;
			}
		}
	}
	int cnt, res = 0;
	for (int i = 1; i <= n; i++) {
		cnt = 0;
		// 如果这个点和其它所有点都有直接或者间接的关系，就说明他的排名可以确定，否则就是不能确定.. 
		for (int j = 1; j <= n; j++) cnt += (graph[i][j] || graph[j][i]);
		if (cnt == n - 1) res++;
	}
	printf("%d", res);
	return 0;
}
