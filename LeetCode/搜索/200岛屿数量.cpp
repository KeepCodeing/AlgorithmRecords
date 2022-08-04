#include <iostream>
#include <vector>
using namespace std;
// ����������������������һ����ֻ��������ͳ�Ƶĵ������������о��ǰѵ㻻�����ַ���ʾ 
class Solution {
public:
	int line, column;
	vector<vector<char > > m;
	void dfs(int x, int y) {
		// �����ж� 
		if (x >= line || x < 0 || y >= column || y < 0) return;
		// ���ʹ��ж��Լ��Ƿ���ˮ�ж� 
		if (m[x][y] != '1') return; 
		// ���Ѿ����ʹ��ĵ���Ϊ0������Ҳ���Ա����ظ����ʣ�ͬʱ
		// �����˵���ʱ���ж� 
		m[x][y] = '0'; 
		// ���		
		dfs(x + 1, y);
		dfs(x - 1, y);
		dfs(x, y + 1);
		dfs(x, y - 1);
	}
    int numIslands(vector<vector<char> >& grid) {
    	if (grid.size() <= 0 || grid.empty()) return 0;
        this->line = grid.size();
        this->column = grid[0].size();
        this->m = grid;
        int cnt = 0;
        for (int i = 0; i < this->line; i++) {
        	for (int j = 0; j < this->column; j++) {
        		// ����ͼ��ʼ��� 
        		if (m[i][j] != '0') {
        			dfs(i, j);
        			cnt++;
				}
			}
		}
        return cnt;
    }
}; 
int main() {
	return 0;
}
