// 水过...另外还有种做法就是拼接两个字符串，然后计数... 
class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {
        unordered_map<string, int > mp;
        vector<string > res;
        stringstream ss(A);
        string temp;
        // 这里的新操作，通过字符串流来方便的根据空格切割字符串... 
        while (ss >> temp) mp[temp]++;
        ss = stringstream(B);
        while (ss >> temp) mp[temp]++;
        for (unordered_map<string, int >::iterator it = mp.begin(); it != mp.end(); it++) {
            if (it->second == 1) res.push_back(it->first);
        }
        return res;
    }
};
