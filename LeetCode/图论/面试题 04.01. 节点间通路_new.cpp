#include <iostream>
#include <vector>
using namespace std;

// 之前太naive用并查集写了个，结果发现并查集并不能判断有向图的连通性...
// 然后发现这个题给的strat不知道怎么搞，看了评论才知道原来给的只是边
// 还得自己连上去，不过不太会vector的遍历，用数组搞可能会更好...

// 脑瘫了，首先是头节点没有初始化，然后TLE，初始化后又写在了建图之后w
// 然后发现答案还是不对，看了眼建图，e[idx] = vt写成e[vt] = idx...

// 然后发现LeetCode评测又有问题（绝望） 

const int N = 1e5 + 10;
int head[N], e[N], ex[N], idx = 0;
bool visited[N];
class Solution {
public:
	void add(int ut, int vt) {
		e[idx] = vt, ex[idx] = head[ut], head[ut] = idx++;
	}
    bool findWhetherExistsPath(int n, vector<vector<int> >& graph, int start, int target) {
		// 把点对转换为图
		int gLen = graph.size();
		if (!gLen) return false;
		fill(head, head + N, -1);
		for (int i = 0; i < gLen; i++) add(graph[i][0], graph[i][1]);
		bool flag = false;
		dfs(start, target, flag);
		return flag;
    }
    void dfs(int cur, int ed, bool& flag) {
    	if (cur == ed) {
    		flag = true;
    		return;
		}
		visited[cur] = true;
		for (int i = head[cur]; i != -1; i = ex[i]) {
			int vt = e[i];
			if (!visited[vt]) dfs(vt, ed, flag);
		}
	}
}; 

int main() {
	return 0;
}
