#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// �������ʵ�Ǹ���ˮ����⣨FloodFill��������ֻ��Ҫ������Ϊ0�ĵ����DFS�������������ĵ��Ǽ��ɡ�

class Solution {
public:
	vector<int > result;
	int line, col;
	vector<vector<int> > land;
	int dfs(int x, int y) {
		if (x < 0 || x >= this->line || y < 0 || y >= this->col) return 0;
		if (land[x][y] != 0) return 0;
		land[x][y] = 1;
		// ���ذ˸�����Ϊ0�ĵ�ĸ���
		int sumNum = 1;
		sumNum += dfs(x + 1, y);	
		sumNum += dfs(x - 1, y);
		sumNum += dfs(x, y + 1);
		sumNum += dfs(x, y - 1);
		sumNum += dfs(x + 1, y + 1);
		sumNum += dfs(x - 1, y - 1);
		sumNum += dfs(x + 1, y - 1);
		sumNum += dfs(x - 1, y + 1);
		return sumNum;
	}
    vector<int> pondSizes(vector<vector<int> >& land) {
    	this->land = land;
		this->line = land.size();
		this->col = land[0].size();
		int ans;
		for (int i = 0; i < this->line; i++) {
			for (int j = 0; j < this->col; j++) {
				if (land[i][j] != 0) continue;
				ans = dfs(i, j);
				// ��Ϊ�и��ֲ��Ϸ����������ص�0����������Ҫ�����жϴ��Ƿ�Ϸ�
				if (ans != 0) result.push_back(ans);
			}
		}
		sort(result.begin(), result.end());
		return result;
    }
};

int main() {
	return 0;
}
