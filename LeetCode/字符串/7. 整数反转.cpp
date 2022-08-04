// 其实好久之前就打开过这个题，不过不会做...这里用字符串流转成字符串，然后翻转再转回来对比，不过用了long long
// 有点不符合题目要求... 
class Solution {
public:
    string renum(string& str, int l) {
        int left = l, right = str.size() - 1;
        while (left < right) swap(str[left++], str[right--]);
        return str;
    }
    int reverse(int x) {
        stringstream ss;
        long long res;
        string temp;
        ss << x, ss >> temp, ss.clear();
        if (x < 0) renum(temp, 1);
        else renum(temp, 0);
        ss << temp, ss >> res;
        if (res > 2147483647 || res < -2147483648) return 0;
        return res;
    }
};
