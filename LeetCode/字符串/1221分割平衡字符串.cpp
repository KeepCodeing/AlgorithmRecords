#include <iostream>
using namespace std;
// ˼·����Ϊֻ����L��R����״̬�����Կ�����һ��������¼L��R���ֵĴ���
// ���Լ���˼·�������������ֱ��¼���鷳 
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
