#include <iostream>
#include <vector>
#include <set>
using namespace std;
// 分析：主要是去重操作，画了递归树在再和题目给出的答案对比可以看出如果是单纯的
// 用一个少一个形式的话生成的答案就不正确，正确的答案应该是用了一个，加上剩下的
// 所以这题和全排列就有点类似，将用过的元素标记，回溯时判断是否是用过的元素，而
// 回溯的出口就是所有元素都用完了 

// 这个题的出口多多少少给了其一点启示，有时候答案不是叶子节点，而是树上的所有节点
// 答案是这种类型的题大多是求子集类型的，反之，其它类型的题的答案就很可能是叶子节点 
class Solution {
public:
	int *visited;
	vector<char > v;
	string str;
	set<string > strSet;
	void dfs(int left, int deepth) {
		// 这里的添加答案的出口就是还剩字符 
		if (left) {
			string s;
			for (int i = 0; i < v.size(); i++) s += v[i];
			// 排除空字符 
			if (!s.empty()) strSet.insert(s);
			// 不返回，如果直接返回就没有后续递归了 
			// return;
		}
		for (int i = 0; i < deepth; i++) {
			if (visited[i]) continue;
			visited[i] = 1;
			v.push_back(str[i]);
			dfs(left - 1, deepth);
			v.pop_back();
			visited[i] = 0;
		}
	}
    int numTilePossibilities(string tiles) {
        if (tiles.size() == 0 || tiles.empty()) return 0;
        int tLen = tiles.size();
        visited = new int[tLen]();
        this->str = tiles;
        dfs(tLen + 1, tLen);
        return strSet.size();
    }
};

int main() {
	Solution s = Solution();
	cout << s.numTilePossibilities("AAB"); 
	return 0;
}
