#include <iostream>
#include <vector>
using namespace std;

// �ȽϿӵ��⣬���㷨ʱ�临�Ӷ�Ҫ��Ƚϸߣ����������ķ���Ҳ�Ƚ�����

// ���̣������ˣ�leetcode��Ҫ�����Ҫ��һ��return��������ȥ׹���� 
 
class Solution {
public:
	bool flag;
	bool dfs(int x, int y, int line, int col, vector<vector<char> >& board, string word, int pos, string res) {
		// ������ͼ��ģ�� 
		// ��ֹ�ظ����ʣ��Լ���ֹ���� 
		if (x < 0 || x >= line || y < 0 || y >= col) return false;
		//  if (board[x][y] == '.') return false; 
		// ע������Ƚϴ����������ǵ���ǰ�ַ���������Ҫ���ַ�ʱ�ż������� 
		if (word[pos] != board[x][y]) return false;
		// �õ��˺Ϸ��⣬���ַ�����pos���ָ�Ϊ�����٣�������һ�ۿ�������ͼ 
		// if (pos == word.size() - 1) return true; 

		// �����������Ҫ���ַ������ɽ��н������ı�������������Ϊ������
		// ��ֹ�ظ����ʵ�Ч�����Խ�board�������ĵط���Ϊ�����ַ���������
		// �����ٸ�visited�����Զ������ٶ��𵽺ܴ������ 
		// ���½� 
		res += board[x][y];
		// ���ʹ�ù��ĵ� 
		board[x][y] = '.'; 
		dfs(x + 1, y, line, col, board, word, pos + 1, res);
		dfs(x - 1, y, line, col, board, word, pos + 1, res);
		dfs(x, y + 1, line, col, board, word, pos + 1, res);
		dfs(x, y - 1, line, col, board, word, pos + 1, res);
		// ��ԭʹ�ù��ĵ㣬��Ϊǰ��д��ֻ�е���ǰ����������Ҫ�ĵ�ʱ���ܷ��ʣ�����������ܵõ��Ϸ���
		// ���Խ�����㻹ԭ 
		if (res == word) {
			flag = true;
			return true;
		}
		board[x][y] = word[pos];
		return false;
	}
    bool exist(vector<vector<char> >& board, string word) {
        if (board.size() == 0 || board.empty()) return false;
        // ��ÿ��������ж�
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
