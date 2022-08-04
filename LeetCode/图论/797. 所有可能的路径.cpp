#include <iostream>
#include <vector> 
using namespace std;

// 裸的DFS，题目要求节点顺序是字典序，实际上回溯就行了 
// 发现这里的回溯没带visited标记，可能是和选数之类的回溯一样，下一次就从另一个节点开始了，也可能
// 是因为这是个有向无环图，也就是任意一个节点绝对只会被访问一次，然后在走到n-1这个点之后开始回溯... 

class Solution {
public:
	vector<vector<int > > res;
	// 0这个点直接默认加进去就行 
	vector<int > path{0};
    vector<vector<int> > allPathsSourceTarget(vector<vector<int> >& graph) {
		dfs(graph, 0, graph.size());
		return res;
    }
    void dfs(vector<vector<int > >& graph, int cur, int n) {
    	if (cur == n - 1) {
    		res.push_back(path);
			return; 
		}
		// dfs回溯，可以加visited标记也可以不加，因为这个图是无环的有向图
		// 遍历这个点的所有边 
		for (int i = 0; i < graph[cur].size(); i++) {
			// 取出这个边能到的那个点 
			path.push_back(graph[cur][i]);
			// 下次从这个点继续遍历，下面pop_back()是回溯的基本操作 
			dfs(graph, graph[cur][i], n);
			path.pop_back(); 
		}
	}
};

int main() {
	return 0;
}
