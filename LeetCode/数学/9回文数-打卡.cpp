// 复习周w，正在复习线代，其实更多是预习ww，看到LeetCode上的简单打卡题就做了w，前天和昨天其实都没写算法题，昨天甚至全天
// 都在搞电工报告之类的东西...也看到了自己五个月前的提交，很naive，但是反过来说自己可能已经学了半年算法吧，似乎还是很弱的
// 样子... 
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        long long temp = 0, t = x;
        while (x) {
            temp = temp * 10 + x % 10;
            x /= 10;
        }
        return temp == t;
        // stringstream ss;
        // string str;
        // ss << x, ss >> str, ss.clear();
        // int left = 0, right = str.size() - 1;
        // while (left < right) {
        //     if (str[left++] != str[right--]) return false;
        // }
        // return true;
    }
};
