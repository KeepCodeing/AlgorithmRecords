#include <iostream>
using namespace std;

// 我谔谔，说是Dp题，但果然还是王道征途，回溯系吧
// 啊这...不能剪枝加上数据范围会超时吧 

// 果然超时坠毁了，看下剪枝能不能过 

class Solution {
public:
	int maxSum = -1;
	int dfs(int level, int deepth, int sumNum, int time, int temp, int m[100][2]) {
		if (level == deepth || time <= 0) {
			 if (time < 0) sumNum -= temp;
			 if (sumNum > maxSum) maxSum = sumNum;
			 return maxSum;
		}
		for (int i = level; i < deepth; i++) {
			dfs(i +1, deepth, sumNum + m[i][1], time - m[i][0], m[i][1], m);
		}
	}
	void resolve() {
		int time, cnt;
		int m[100][2];
		cin >> time >> cnt;
		for (int i = 0; i < cnt; i++) {
			cin >> m[i][0] >> m[i][1];
		}
		cout << dfs(0, cnt, 0, time, 0, m);
		// for (int i = 0; i < 10; i++) cout << result[i] << endl;
		//return maxSum; 
	}
}; 

//class Solution {
//public:
//	int result[100] = {0};
//	// int maxSum = -1;
//	int dfs(int level, int deepth, int sumNum, int time, int temp, int m[100][2]) {
//		if (level == deepth || time <= 0) {
//			// if (time < 0) sumNum -= temp;
//			// if (sumNum > maxSum) maxSum = sumNum;
//			// return;
//		}
//		for (int i = level; i < deepth; i++) {
////			sumNum += m[i][1];
////			time -= m[i][0];
//			result[level] = dfs(i +1, deepth, sumNum + m[i][1], time - m[i][0], m[i][1], m); 
//			return result[level];
////			sumNum -= m[i][1];
////			time += m[i][0];
//		}
//	}
//	void resolve() {
//		int time, cnt;
//		int m[100][2];
//		cin >> time >> cnt;
//		for (int i = 0; i < cnt; i++) {
//			cin >> m[i][0] >> m[i][1];
//		}
//		
//		cout << dfs(0, cnt, 0, time, 0, m) << endl;
//		for (int i = 0; i < 10; i++) cout << result[i] << endl;
//		//return maxSum; 
//	}
//}; 

int main() {
	Solution s = Solution();
	s.resolve();
	// cout << s.resolve();
	return 0;
}
