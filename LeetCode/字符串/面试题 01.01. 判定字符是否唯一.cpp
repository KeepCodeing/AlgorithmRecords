// 不让用数据结构，灵光一闪想到了排序...似乎是第一个这样做的？ 不是这样吧？（题解已经有神触这样做了..） 
class Solution {
public:
    bool isUnique(string astr) {
        if (astr.empty()) return true;
        sort(astr.begin(), astr.end());
        for (int i = 0; i < astr.size() - 1; i++) 
            if (astr[i] == astr[i + 1]) return false;
        return true;
    }
};
