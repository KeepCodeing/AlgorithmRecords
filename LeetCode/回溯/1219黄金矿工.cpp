#include <iostream>
#include <vector>
using namespace std;
// ���������Ҳ����ģ�壨���̣���Ŀû����д���˲ŷ���...������Ӧ���ǵ�������

class Solution {
public:
	int maxNum = -1;
	// �����vector<vector<int> >& grid�ƺ����Ա�֤gridʹ�õ���һ����ַ��Ҳ�����ܱ���
	// ���������ֲ��������Ӷ������ٶ� 
	void dfs(int level, int deepth, int width, vector<vector<int> >& grid, int sumNum) {
		
		
	}
    int getMaximumGold(vector<vector<int> >& grid) {
        if (grid.size() == 0 || grid.empty()) return 0;
        dfs(0, grid.size(), grid[0].size(), grid, 0);
        return maxNum;
    }
};


// ��ģ��д����������������ȡһ��ֵ��ȡ�����ֵ������ûʲô�ã� 
//class Solution {
//public:
//	int maxNum = -1;
//	void dfs(int level, int deepth, int width, vector<vector<int> > grid, int sumNum) {
//		if (level == deepth) {
//			if (sumNum > maxNum) {
//				maxNum = sumNum;
//			}
//			return;
//		}
//		for (int i = 0; i < width; i++) {
//			if (grid[level][i] != 0) {
//				sumNum += grid[level][i];
//				dfs(level + 1, deepth, width, grid, sumNum);
//				sumNum -= grid[level][i];
//			}
//		}
//	}
//    int getMaximumGold(vector<vector<int> >& grid) {
//        if (grid.size() == 0 || grid.empty()) return 0;
//        dfs(0, grid.size(), grid[0].size(), grid, 0);
//        return maxNum;
//    }
//};
int main() {
	Solution s = Solution();
	vector<int > temp;
	vector<vector<int > > v;
	temp.push_back(0); 
	temp.push_back(6);
	temp.push_back(0);
	v.push_back(temp);
	temp.clear();
	temp.push_back(5); 
	temp.push_back(8);
	temp.push_back(7);
	v.push_back(temp);
	temp.clear();
	temp.push_back(0); 
	temp.push_back(9);
	temp.push_back(0);
	v.push_back(temp);
	cout << s.getMaximumGold(v); 
	return 0;
}
