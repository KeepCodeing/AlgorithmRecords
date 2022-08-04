#include <iostream>
#include <vector>
using namespace std;
// 分析：可以把数字看成字符串，每次递归都加一位，然后在递归的过程中剪枝（判断是否有字符重复）
// 并且统计这种字符串的个数，用n的区间减去这种字符串的个数即是不重复字符串的个数

class Solution {
public:
	// 回溯坠毁... 
//	vector<char > temp;
//	void dfs(int level, int deepth, string str) {
//		if (level == deepth) {
//			for (int i = 0; i < temp.size(); i++) {
//				cout << temp[i];
//			}
//			cout << endl;
//			return;
//		}
//		for (char i = '1'; i <= '9'; i++) {
//			// str.push_back(i); 
//			temp.push_back(i);
//			dfs(level + 1, deepth, str);
//			// str.erase(str.end()); 
//			// cout << str << endl;
//			temp.pop_back();
//		}
//	}
/*n=1: res=10

n=2: res=9*9+10=91 # 两位数第一位只能为1-9，第二位只能为非第一位的数，加上一位数的所有结果

n=3: res=9 * 9 * 8+91=739 # 三位数第一位只能为1-9，第二位只能为非第一位的数，第三位只能为非前两位的数，加上两位数的所有结果

n=4: res=9 * 9 * 8 * 7+739=5275 # 同上推法*/
    int countNumbersWithUniqueDigits(int n) {
    	if(n <= 1) return 1; 
    	int result = 10, Mysum = 9;
        for (int i = 1; i < min(n, 10); i++) {
        	Mysum *= 10 - i;
            result += Mysum;
        }
		return 0;
    }
}; 
int main() {
	Solution s = Solution();
	s.countNumbersWithUniqueDigits(2); 
	return 0;
}
