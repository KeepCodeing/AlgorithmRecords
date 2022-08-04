#include <iostream>
#include <vector>
using namespace std;
// 分析：很类似在洛谷上做过的填色题，应该可以用相同思路解

class Solution {
public:
	
    void solve(vector<vector<char> >& board) {
        // if (board.size() <= 0) return board;
        int line = board.size(), col = board[0].size();
        vector<char > temp(col, 'O');
        board.insert(board.begin(), temp);
        board.insert(board.end(), temp); 
        for (int i = 0; i < line; i++) {
        	board[i].insert(board[i].begin(), 'O');
        	board[i].insert(board[i].end(), 'O');
		}
		line = board.size(), col = board[0].size();
		for (int i = 0; i < line; i++) {
			for (int n = 0; n < col; n++) {
				cout << board[i][n] << ' ';
			}
			cout << endl;
		}
    }
};
 
int main() {
	vector<vector<char> > board;
	vector<char > t;
	t.push_back('X');
	board.push_back(t);
	Solution s = Solution();
	s.solve(board); 
	return 0;
}
