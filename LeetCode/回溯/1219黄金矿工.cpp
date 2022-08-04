#include <iostream>
#include <vector>
using namespace std;
// 分析：大概也是套模板（谔谔，题目没看懂写完了才发现...），这应该是到深搜题

class Solution {
public:
	int maxNum = -1;
	// 这里的vector<vector<int> >& grid似乎可以保证grid使用的是一个地址，也就是能避免
	// 产生其它局部变量，从而增加速度 
	void dfs(int level, int deepth, int width, vector<vector<int> >& grid, int sumNum) {
		
		
	}
    int getMaximumGold(vector<vector<int> >& grid) {
        if (grid.size() == 0 || grid.empty()) return 0;
        dfs(0, grid.size(), grid[0].size(), grid, 0);
        return maxNum;
    }
};


// 套模板写法可以求各个网格各取一个值获取的最大值（好像没什么用） 
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
