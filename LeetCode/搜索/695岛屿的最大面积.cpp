#include <iostream>
#include <vector>
using namespace std;
// ��������ˮ��䷨���ÿ����ͼ��Ȼ�������������ע������û����visited����Ѿ����ʹ���
// �㣬��Ϊ������ͼ��ֻ�÷���һ��ͳ����������Է����˿���ֱ�ӽ��õ��Ϊ0��������ֻ��1����
// ���ʣ������൱�ڱ���˱����ʵ㡣

// ��������ϵ���ˮ��䷨������ͬ������Ҫ������������ͼ�����Բ���Ҫ��ɫ�����������Ϊ0
// ������Ҳ��visited��ǲ�ͬ 
class Solution {
public:
	int line, column;
	vector<vector<int> > m;
	int dfs(int x, int y) {
		// �����ж� 
		if (x >= line || x < 0 || y >= column || y < 0) return 0;
		// ���ʹ��ж��Լ��Ƿ���ˮ�ж� 
		if (m[x][y] != 1) return 0; 
		// ���ۿ����ģ����Ѿ����ʹ��ĵ���Ϊ0������Ҳ���Ա����ظ����ʣ�ͬʱ
		// �����˵���ʱ���ж� 
		m[x][y] = 0; 
		// ������� 		
		int sum = 1;
		sum += dfs(x + 1, y);
		sum += dfs(x - 1, y);
		sum += dfs(x, y + 1);
		sum += dfs(x, y - 1);
		return sum;
	}
    int maxAreaOfIsland(vector<vector<int> >& grid) {
    	if (grid.size() <= 0 || grid.empty()) return 0;
        this->line = grid.size();
        this->column = grid[0].size();
        this->m = grid;
        int maxSize = 0;
        for (int i = 0; i < this->line; i++) {
        	for (int j = 0; j < this->column; j++) {
        		// ����ͼ��ʼ��� 
        		if (m[i][j] != 0) {
        			maxSize = max(dfs(i, j), maxSize);
				}
			}
		}
        return maxSize;
    }
}; 
int main() {
	return 0;
}
