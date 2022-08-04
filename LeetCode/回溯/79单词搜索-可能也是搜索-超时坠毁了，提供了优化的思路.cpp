#include <iostream>
#include <vector>
using namespace std;
// 分析：这个题类似一个搜索题，主要思路还是遍历四个方向，同时添加剪枝判断 


// 四个dfs:0.01
// for :0.01
// target写成参数：0.01 
// visited写成参数:0.01 
// board写成参数 
// 尽量不要用全局变量，这样会导致速度变慢 


// 超出内存限制坠毁了 
class Solution {
public:
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    int n, m;
    
    bool dfs(vector<vector<char> > &board, int x, int y, string &word, int pos) {
    	// 这里的对比很巧，只对比相同的字符，如果不相同直接就剪枝了，而且可以保证
		// pos不会越界 
        if (word[pos] != board[x][y]) {
            return false;
        }
        // 如果全都相同说明组合成功 
        if (pos == word.size() - 1) {
            return true;
        }
        // 区别：没有使用visited，直接更改了board 
        board[x][y] = '.';
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                if (dfs(board, nx, ny, word, pos + 1)) {
                    return true;
                }
            }
        }
        board[x][y] = word[pos];  // 回溯
        return false;
    }
    bool exist(vector<vector<char> >& board, string word) {
        if (board.empty() || word.empty()) {
            return false;
        }
        n = board.size();
        m = board[0].size();
        if (n * m < word.length()) {
            return false;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (dfs(board, i, j, word, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
};
/*
class Solution {
public:
	int line, col;
	
	
	int r[4][2] = {{0, 1},{0, -1},{1, 0}, {-1, 0}};
	// string target;
	bool dfs(int x, int y, string str, int index, string target, bool visited[1000][1000], vector<vector<char> > board) {
		// 如果当前字符不相等，进行剪枝 
		if (index > 0 && str[index - 1] != target[index - 1]) return false;
		// 防止数组出界 
		if (index > target.size()) return false;
		// 测试数据里有个[["a"]]...，如果把这个写后面就会因为出界无法正确判定.. 
		if (str != target) {
			// 出界判断 
			if (x < 0 || x >= line || y < 0 || y >= col) return false;
			// 访问过判断
			if (visited[x][y]) return false; 
			visited[x][y] = true;
			for (int i = 0; i < 4; i++) {
				dfs(x + r[i][0], y + r[i][1], str + board[x][y], str.size(), target, visited, board);
			}
			
//			dfs(x + 1, y, str + board[x][y], str.size());
//			dfs(x, y + 1, str + board[x][y], str.size());
//			dfs(x, y - 1, str + board[x][y], str.size());
			visited[x][y] = false;
			// leetcode必须有返回值 
			return false;
		} else {
			return true;
		}
	}
    bool exist(vector<vector<char> >& board, string word) {
        if (board.size() == 0 || board.empty() || word.empty() || word.size() == 0) return false;
        this->line = board.size();
        this->col = board[0].size();
        bool visited[1000][1000];
        // this->target = word;
        // this->board = board;
        for (int i = 0; i < this->line; i++) {
        	for (int j = 0; j < this->col; j++) {
        		if(dfs(i, j, "", 0, word, visited, board)){ 
					return true;
				}
			}
		}
        return false;
    }
};
*/

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
	cout << s.exist(board, "ABCCED"); 
	return 0;
}
