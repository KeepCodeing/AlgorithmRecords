#include <iostream>
using namespace std;

// 我们可以把树看成一个特殊的图，树就是没有环的有向图，因此
// 我们可以用存储图的方式存储树，也就是用邻接表来做，可以用
// vector，也可以手动模拟一个单链表

// N是顶点数，M是边数 
const int N = 100010, M = N * 2;

// 这里和普通单链表唯一不同的地方就是可以存在多个头，每个头
// 后面连接的是这个头能到达的点 
int h[N], e[M], ex[M], idx = 0;
bool visited[N];

// 在头节点k后插入val，基本和单链表一模一样，就是指定了从哪个
// 头插入 
void add(int k, int val) {
	e[idx] = val;
	ex[idx] = h[k];
	h[k] = idx;
	idx++;
} 

// DFS和单链表遍历差不多，只不过这里要把所有的头都遍历到
void dfs(int cur) {
	// 标记访问过的节点 
	visited[cur] = true;
//	while (h != -1) {
//		cout << e[h];
//		h = ex[h];
//	}
	for (int i = h[cur]; i != -1; i = ex[i]) {
		int j = e[i];
		if (!visited[j]) {
			dfs(j);
		}
	}
} 

int main() {
	// 初始化头指针 
	fill(h, h + N, -1);
	return 0;
}
