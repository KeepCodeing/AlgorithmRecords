#include <iostream>
#include <algorithm>
using namespace std;

// 只想到了暴力做法w，n^2，假设当前学生的答案全对，然后枚举其它位置的所有
// 学生的答案，以当前位置的学生的答案为基准，判断他们加起来能拿多少分，这样
// 可以使每个学生都拿一次满分，但是还有5种情况要考虑，那就是全是一个答案的
// 情况，第二个测试样例应该就是提示了，虽然每个学生都能有一次拿满分的情况，
// 但这种情况并不能保证总分数最大，如果有学生选的全是分值最大的那个选项呢... 
// 写了下发现不能将全是一个答案的情况作为学生处理，这样就会“多出来 ”若干个
// 学生，因此将其单独提取出来处理... 

// TLE了ww，换一个思路，将答案看成一个二维数组，然后统计第一列有多少个A，B，C..第二列有多少个，并以此类推，然后枚举每一列以A，B，C..为答案时
// 能获取的分数... 

const int N = 1000 + 10;
string stu[N];
int scores[N];
int bucket[N][10];
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> stu[i];
	for (int i = 0; i < m; i++) cin >> scores[i];
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) bucket[i][stu[i][j] - 'A']++;
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < 5; j++) cout << bucket[i][j] << ' ';
		cout << endl;
	}
	return 0;
}
//const int N = 1000 + 10;
//string stu[N];
//int scores[N];
//int main() {
//	string tt = "ABCDE";
//	do {
//		cout << tt << endl;
//	} while(next_permutation(tt.begin(), tt.end()));
//	int n, m;
//	cin >> n >> m;
//	for (int i = 0; i < n; i++) cin >> stu[i];
//	for (int i = 0; i < m; i++) cin >> scores[i];
//	// 让答案以第i个位置的学生为基准 
//	int res = 0, t;
//	for (int i = 0; i < n; i++) {
//		t = 0;
//		for (int j = 0; j < n; j++) {
//			for (int k = 0; k < m; k++) {
//				// 对比各位上的答案，如果正确，加上分值 
//				if (stu[i][k] == stu[j][k]) t += scores[k];
//			}
//		}
//		res = max(res, t);
//	}
//	// 将全选一个答案的情况也加到答案里... 
//	for (int i = 0; i < 5; i++) {
//		t = 0;
//		for (int j = 0; j < n; j++) {
//			for (int k = 0; k < m; k++) {
//				if (stu[j][k] == (char)('A' + i)) t += scores[k];	
//			}
//		}
//		res = max(res, t);
//	} 
//	cout << res << endl;
//	return 0;
//}
