// ˮ��...���⻹������������ƴ�������ַ�����Ȼ�����... 
class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {
        unordered_map<string, int > mp;
        vector<string > res;
        stringstream ss(A);
        string temp;
        // ������²�����ͨ���ַ�����������ĸ��ݿո��и��ַ���... 
        while (ss >> temp) mp[temp]++;
        ss = stringstream(B);
        while (ss >> temp) mp[temp]++;
        for (unordered_map<string, int >::iterator it = mp.begin(); it != mp.end(); it++) {
            if (it->second == 1) res.push_back(it->first);
        }
        return res;
    }
};
