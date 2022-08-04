#include <iostream>
#include <vector>
using namespace std;

// 这个题同样是个求独立岛屿数量的题，只不过要求的是元素个数，而不是岛屿个数
// 又回去看了下洛谷的题目，那些题也是类似的，但是如果是输入的话或许多加一圈
// 可遍历的数据会好做点，但是对于这个题来说，这个题不像那些题，有三种元素，
// 水，陆地，障碍，这个题只有两种元素，障碍和陆地，也就是说我们没办法通过加
// 一圈水来把除了被障碍包围的元素全部染色，所以这个题还是得用出界来判断

// 那么这样看来题目如果是要求输出染色后的图，还是用加一圈的方法
// 比较好，而只用输出连通图数量，用出界方法应该会更好

// 再进一步看就是LeetCode上的数据是给好的，对其进行加工比较难，而OI里的数据是要
// 输入的，所以可以方便的进行加工，那么OI用加一圈的方法，LeetCode用出界法应该会更好 

// 对每个1进行遍历，判断出界否，并统计1的数量，这个题也比较直白的说
// 明的能出界的1就不是答案 

class Solution {
public:
	int line, col;
	int oneCnt;
	vector<vector<int> > g;
	// 记得加&，不然flag的值不会改变 
	void dfs(int sx, int sy, bool& flag) {
		if (sx < 0 || sx >= line || sy < 0 || sy >= col) {
			flag = false;
			// oneCnt = 0;
			return;
		}
		// 只对陆地进行遍历 
		if (g[sx][sy]) {
			g[sx][sy] = 0;
			oneCnt++;
			dfs(sx + 1, sy, flag);
			dfs(sx - 1, sy, flag);
			dfs(sx, sy + 1, flag);
			dfs(sx, sy - 1, flag);
		}
	}
    int numEnclaves(vector<vector<int> >& A) {
    	this->g = A;
		this->line = A.size(), this->col = A[0].size();
		bool flag;
		int ans = 0;
		for (int i = 0; i < line; i++) {
			for (int j = 0; j < col; j++) {
				if (g[i][j]) {
					flag = true, oneCnt = 0;
					dfs(i, j, flag);
					if (flag) ans += oneCnt;
				}
			}
		}
		return ans;
    }
};

int main() {
	return 0;
}

/*
[0,0,0,0],
[1,0,1,0],
[0,1,1,0],
[0,0,0,0]

[0,1,1,0],
[0,0,1,0],
[0,0,1,0],
[0,0,0,0]
*/
