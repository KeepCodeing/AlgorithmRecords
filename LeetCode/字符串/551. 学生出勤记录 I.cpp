#include <iostream>
#include <algorithm>
using namespace std;

// 可以先统计下A的个数，如果大于1就说明不能获奖,评论里给出的解法是判断LLL是否出现过，
// 题目说LL不算，那么LLL，LLLL都算，这几种L连在一起一定超过或等于三个 

class Solution {
public:
    bool checkRecord(string s) {
        if (s.size() == 0 || s.empty()) return fasle;
        if (count(s.begin(), s.end(), 'A') > 1) return false;
        if (s.find("LLL") != s.npos) return false;
        return true;
    }
};

int main() {
	return 0;
}
