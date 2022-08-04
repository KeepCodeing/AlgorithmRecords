#include <iostream>
#include <vector>
#include <set>
using namespace std;

// 这个题好像是其第一个独立解出来的题？或许还是看了题解罢 

// 啊这...半天没思路，不过算是看图看出来是个子集类型问题，但是还是没什么优化，
// 暴力枚举了所以可能， 一般来说这种问题都是选一个少一个，但是这个题似乎所有
// 元素都可以重复使用，如AAB，ABA，所以主要是个使用否的问题，就有点类似数组版
// 全排列 

class Solution {
public:
	set<string > result;
	void dfs(int level, int deepth, string str, bool visited[], string t) {
		if (result.count(t)) return;
		if (!t.empty()) result.insert(t);
		for (int i = 0; i < deepth; i++) {
			if (!visited[i]) {
				visited[i] = true;
				dfs(i + 1, deepth, str, visited, t + str[i]);
				visited[i] = false;
			}
		}
	}
    int numTilePossibilities(string tiles) {
        if (tiles.size() == 0 || tiles.empty()) return 0;
        vector<char > temp;
        bool *visited = new bool[tiles.size()]();
        dfs(0, tiles.size(), tiles, visited, "");
        delete[] visited;
        return result.size();
    }
};

int main() {
	Solution s = Solution();
	cout << s.numTilePossibilities("AAB"); 
	return 0;
}
