#include <iostream>
#include <vector>
using namespace std;

// 比较坑的题，对算法时间复杂度要求比较高，但是题解里的方法也比较有用

// 谔谔，放弃了，leetcode的要求必须要有一个return，改来改去坠毁了 
 
class Solution {
public:
	bool flag;
	bool dfs(int x, int y, int line, int col, vector<vector<char> >& board, string word, int pos, string res) {
		// 惯例的图论模板 
		// 防止重复访问，以及防止出界 
		if (x < 0 || x >= line || y < 0 || y >= col) return false;
		//  if (board[x][y] == '.') return false; 
		// 注意这里，比较聪明的做法是当当前字符等于我们要的字符时才继续遍历 
		if (word[pos] != board[x][y]) return false;
		// 拿到了合法解，两种方法，pos这种更为简洁快速，但不能一眼看出来意图 
		// if (pos == word.size() - 1) return true; 

		// 如果等于我们要的字符，即可进行接下来的遍历，不过这里为了做到
		// 防止重复访问的效果可以将board遍历过的地方改为其它字符，这样就
		// 可以少个visited，可以对整体速度起到很大的提升 
		// 更新解 
		res += board[x][y];
		// 标记使用过的点 
		board[x][y] = '.'; 
		dfs(x + 1, y, line, col, board, word, pos + 1, res);
		dfs(x - 1, y, line, col, board, word, pos + 1, res);
		dfs(x, y + 1, line, col, board, word, pos + 1, res);
		dfs(x, y - 1, line, col, board, word, pos + 1, res);
		// 还原使用过的点，因为前面写了只有当当前点是我们想要的点时才能访问，所以如果不能得到合法解
		// 可以将这个点还原 
		if (res == word) {
			flag = true;
			return true;
		}
		board[x][y] = word[pos];
		return false;
	}
    bool exist(vector<vector<char> >& board, string word) {
        if (board.size() == 0 || board.empty()) return false;
        // 对每个点进行判断
        int line = board.size(), col = board[0].size();
		for(int i = 0; i < line; i++) {
			for (int j = 0; j < col; j++) {
				dfs(i, j, line, col, board, word, 0, "");
				if (flag) {
					return true; 
				} 
			}
		} 
        return false;
    }
};

int main() {
	Solution s = Solution();
	vector<vector<char> > board;
	vector<char > temp;
	temp.push_back('A'); 
	temp.push_back('B'); 
	temp.push_back('C'); 
	temp.push_back('E'); 
	board.push_back(temp); 
	temp.clear();
	temp.push_back('S'); 
	temp.push_back('F'); 
	temp.push_back('C'); 
	temp.push_back('S'); 
	board.push_back(temp); 
	temp.clear();
	temp.push_back('A'); 
	temp.push_back('D'); 
	temp.push_back('E'); 
	temp.push_back('E'); 
	board.push_back(temp); 
	cout << s.exist(board, "ABCB"); 
	return 0;
}
