#include <iostream>
#include <vector>
using namespace std;

// 或许可以用并查集来做，因为下标就代表关系 
// 草，这个题实际就是求连通块，所以确实可以用并查集，但是其太five
// 甚至没有看出来这个题的意思，啊啊，题量不足感放池沼，换了个说法
// 就没看出来是求连通块数量了...

// 那么暂且人物求连通块数量的题就是xx和xx有“关系”，问不同关系的人
// 有几种，或者数据看起来和图有关系，然后问有多少种方案等...
// 也就是说这种求连通块的题目不一定就是什么岛屿，水坑，障碍等，看起来还是不太熟练.. 

class Solution {
public:
	struct unionFind {
		int *bin;
		unionFind(int len) {
			bin = new int[len + 1];
			// 这里矩阵的i j都是从0开始的 
			for (int i = 0; i < len; i++) bin[i] = i;
		} 
		int anc(int x) {
			if (bin[x] == x) return x;
			bin[x] = anc(bin[x]);
			return bin[x];
		}
		void uni(int x, int y) {
			bin[anc(x)] = bin[anc(y)];
		}
		bool ask(int x, int y) {
			// 这里是比较祖先是否相同，而不是比较bin[x] == bin[y] 
			return anc(x) == anc(y);
		}
		~ unionFind() {
			delete[] bin;
		}
	};
    int findCircleNum(vector<vector<int> >& M) {
		// n * n大小，因此没必要再取一遍大小 
		int mSize = M.size();
		unionFind u(mSize);
		int ans = mSize;
		for (int i = 0; i < mSize; i++) {
			for (int j = 0; j < mSize; j++) {
				// 自己和自己就是朋友，所以无需判断 
				if (i != j && M[i][j]) {
					// 并查集求连通图数量的核心，不是一个颜色的元素
					// 就建立连通关系，并且定点数自减 
					if (!u.ask(i, j)) u.uni(i, j), ans--;  
				}
			}
		}
		return ans;
    }
};

int main() {
	return 0;
} 
