#include <iostream>
#include <vector>
using namespace std;

// 并查集，判断下起点和终点在不在一个连通块里就行，也就是判断下他们是否具有公共祖先

// 奇妙，坠毁了，不明... 
// 草，并查集其实只能判断无向图两点是否连通，而不能判断有向图两点是否连通.... 

class Solution {
public:
	struct unionFind {
		int *bin;
		unionFind (int n) {
			bin = new int[n + 10];
			for (int i = 0; i < n + 10; i++) bin[i] = i;
		}
		int anc(int x) {
			if (x != bin[x]) bin[x] = anc(bin[x]);
			return bin[x];
		}
		void uni(int x, int y) {
			bin[anc(x)] = anc(y);
		}
		bool ask(int x, int y) {
			return anc(x) == anc(y);
		}
		~ unionFind() {
			delete[] bin;
		}
	};
    bool findWhetherExistsPath(int n, vector<vector<int> >& graph, int start, int target) {
		if (!n) return false;
		unionFind u(n);
		for (int i = 0; i < n; i++) u.uni(graph[i][0], graph[i][1]);
		return u.ask(start, target);
    }
}; 

int main() {
	return 0;
}
