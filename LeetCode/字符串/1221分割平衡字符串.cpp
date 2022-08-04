#include <iostream>
using namespace std;
// 思路：因为只存在L和R两种状态，所以可以用一个变量记录L和R出现的次数
// 其自己的思路是用两个变量分别记录，麻烦 
class Solution {
public:
    int balancedStringSplit(string s) {
    	int cnt = 0;
    	int res = 0;
        for (int i = 0; i < s.size(); i++) {
        	if (s[i] == 'L') cnt++;
        	else cnt--;
        	if (cnt == 0) res++;
		}
		return res;
    }
};
int main() {
	Solution s = Solution();
	cout << s.balancedStringSplit("RLRRLLRLRL");
	return 0;
}
