#include <iostream>
#include <vector>
using namespace std;
// ��������Ҫ�������һ��Ԫ��Ϊ9��λ���������Ŀ������Ҫ����ÿ������Ԫ��ֻ�ܴ��
// һλ���֣����Ի�Ҫ������999�������Ľ�λ��� 
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
    	for (int i = digits.size() - 1; i >= 0; i--) {
            digits[i]++;
            digits[i] = digits[i] % 10;
            if (digits[i] != 0) return digits;
        }
        vector<int > t(digits.size() + 1, 0);
        t[0] = 1;
        return t;
    }
}; 
int main() {
	vector<int > v, t;
	Solution s = Solution();
	v.push_back(9);
	v.push_back(9);
//	v.push_back(8);
	t = s.plusOne(v);
	for (int i = 0; i < t.size(); i++) cout << t[i] << ' ';
	return 0;
}
