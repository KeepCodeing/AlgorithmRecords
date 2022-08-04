// 看起来是个水题，用哈希就行，其实也是有技巧性的
// 这里用到的就是用ASCII码做和差的方法，因为t有个多余的字符，所以用t的ASCII码的和减去s的ASCII码和
// 就能得到多余的那个字符的ASCII码... 
class Solution {
public:
    char findTheDifference(string s, string t) {
        int sum = 0;
        for (auto i : t) sum += i;
        for (auto i : s) sum -= i;
        return sum;
    }
};
