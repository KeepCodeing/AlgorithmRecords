// 水三个题... 
class Solution {
public:
    int lengthOfLastWord(string s) {
        stringstream ss;
        ss << s;
        string temp;
        int sz = 0;
        while (ss >> temp) sz = temp.size();
        return sz;
    }
};
