#include <iostream>
#include <vector>
using namespace std;
// ���������������һ�������⣬��Ҫ˼·���Ǳ����ĸ�����ͬʱ��Ӽ�֦�ж� 


// �ĸ�dfs:0.01
// for :0.01
// targetд�ɲ�����0.01 
// visitedд�ɲ���:0.01 
// boardд�ɲ��� 
// ������Ҫ��ȫ�ֱ����������ᵼ���ٶȱ��� 


// �����ڴ�����׹���� 
class Solution {
public:
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    int n, m;
    
    bool dfs(vector<vector<char> > &board, int x, int y, string &word, int pos) {
    	// ����ĶԱȺ��ɣ�ֻ�Ա���ͬ���ַ����������ֱͬ�Ӿͼ�֦�ˣ����ҿ��Ա�֤
		// pos����Խ�� 
        if (word[pos] != board[x][y]) {
            return false;
        }
        // ���ȫ����ͬ˵����ϳɹ� 
        if (pos == word.size() - 1) {
            return true;
        }
        // ����û��ʹ��visited��ֱ�Ӹ�����board 
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
        board[x][y] = word[pos];  // ����
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
		// �����ǰ�ַ�����ȣ����м�֦ 
		if (index > 0 && str[index - 1] != target[index - 1]) return false;
		// ��ֹ������� 
		if (index > target.size()) return false;
		// �����������и�[["a"]]...����������д����ͻ���Ϊ�����޷���ȷ�ж�.. 
		if (str != target) {
			// �����ж� 
			if (x < 0 || x >= line || y < 0 || y >= col) return false;
			// ���ʹ��ж�
			if (visited[x][y]) return false; 
			visited[x][y] = true;
			for (int i = 0; i < 4; i++) {
				dfs(x + r[i][0], y + r[i][1], str + board[x][y], str.size(), target, visited, board);
			}
			
//			dfs(x + 1, y, str + board[x][y], str.size());
//			dfs(x, y + 1, str + board[x][y], str.size());
//			dfs(x, y - 1, str + board[x][y], str.size());
			visited[x][y] = false;
			// leetcode�����з���ֵ 
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
