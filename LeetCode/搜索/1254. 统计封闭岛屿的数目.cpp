#include <iostream>
#include <vector>
using namespace std;

// ����������˼·�Ƕ��һȦ�������Ļ��Ϳ�����Ȼ��Ȼ�İ�����½�ض���ǵ���������������
// ����������磬���Ҷ�LeetCode��ֱ�Ӹ������ݵ�����������á�
// LeetCode������˼·������һ����������Ƿ���磬����Ŀ���ǿ����ƶϳ������Ƿ�յĵ������
// ���б�����������ֳ����������������ǿ��Զ�����½�ؽ��б�����������½�ر�ˮ��Χ�ˣ���ô
// ������ô�������������ˮ�⣬��������½��û�б�ˮ��Χ������Ի������ͼ֮�� 

// �����ӣ�
// 1. �ֲ��������ͳ�Ա��������ͬ��û�����ֿ���
// 2. flag��ֵû��ͨ��&�ı� 

class Solution {
public:
	int line, col;
	vector<vector<int> > g;
	// ע�������& 
	void dfs(int x, int y, bool& flag) {
		if (x >= line || x < 0 || y < 0 || y >= col) {
			// ���缴˵�����Ƿ�յ��� 
			flag = false;
			return;
		}
		if (g[x][y] != 0) return;
		// Ⱦɫ�Լ�����
		g[x][y] = 1;
		dfs(x + 1, y, flag);
		dfs(x - 1, y, flag);
		dfs(x, y + 1, flag);
		dfs(x, y - 1, flag);
	}
    int closedIsland(vector<vector<int> >& grid) {
    	bool flag;
    	int ans = 0;
    	// ����ͬ�ı��������ˣ���Ա�����;ֲ�������һ����... 
    	this->g = grid;
        this->line = grid.size(), this->col = grid[0].size();
        for (int i = 0; i < this->line; i++) {
        	for (int j = 0; j < this->col; j++) {
        		// ֻ��½�ؽ���DFS
        		if (g[i][j] != 1) {
        			flag = true;
        			// flag֮ǰֻ�Ǵ���ȥ�ˣ�û�м�&�ı���ֵ 
        			dfs(i, j, flag);
        			if (flag) ans++;
				}
			}
		}
		return ans;
    }
};

int main() {
	return 0;
}
