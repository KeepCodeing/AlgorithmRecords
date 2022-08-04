#include <iostream>
#include <vector>
using namespace std;
// 分析：主要考虑最后一个元素为9进位的情况，题目给出的要求是每个数组元素只能存放
// 一位数字，所以还要考虑如999这类数的进位情况 
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
