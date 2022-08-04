#include <iostream>
#include <cstring>
#include <sstream>
using namespace std;

// 这个题除了输入就是个floyd板子了...题意难懂w，输入也比较奇葩w，输入的是一个下三角矩阵，然后每一行表示的
// 其实是一半数据比如下面的例子，一开始没看懂w，事实上现在还是比较疑惑这种神触输入w 
/*
因为这个矩阵是个对称的，所以题目给的其实是0对角线下面的数据... 
0 1 1 1
1 0 1 1
1 1 0 1
1 1 1 0
*/ 

const int N = 110;
int graph[N][N];
int main() {
	int n, temp;
	string w;
	stringstream ss;
	cin >> n;
	// 比较文明的初始化邻接矩阵的方式
	memset(graph, 0x3f, sizeof graph);
	for (int i = 1; i <= n; i++) graph[i][i] = 0;
	// 开始输入，因为第一行没有数据，所以直接从第二行连边，是双向边
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= i -1; j++) {
			cin >> w;
			// 注意这里要进行类型转换，其一开始还以为能用char来搞，但是很明显数字不可能只有一位w，这里直接跳过
			// 是因为初始化的时候每个点都是不可连的，因此可以直接跳过 
			if (w == "x") continue;
			// 字符串转整形... 
			ss << w, ss >> temp, ss.clear();
			graph[i][j] = graph[j][i] = temp;
		}
	} 
	// 套板子 
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				graph[j][k] = min(graph[j][k], graph[j][i] + graph[i][k]);
			}
		}
	}
	int ans = 0;
	// 计算1到其它点的距离，题目要求最长等待时间，其实就是求1到其它点的最长边... 
	for (int i = 2; i <= n; i++) {
		if (graph[1][i] != 0x3f3f3f3f) {
			ans = max(ans, graph[1][i]);
		}
	}
	cout << ans;
	return 0;
}
