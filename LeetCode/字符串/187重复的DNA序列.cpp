#include <iostream>
#include <vector>
#include <map>
using namespace std;
// ���������Խ�ȡ���ַ���Ȼ����HashTable����

class Solution {
public:
	vector<string > result;
    vector<string> findRepeatedDnaSequences(string s) {
    	// �������Ϊ10�Ͳ����������ַ�������1�������� 
        if (s.size() <= 10 || s.empty()) return result;
        int sLen = s.size();
        map<string, int > sMap;
        // �����ĵ��ڣ���ֹ©�������ַ��� 
        for (int i = 0; i <= sLen - 10; i++) {
        	// ������������Ż����жϵ�ǰ�ַ��Ƿ���ֹ��ˣ�������ֱ�Ӽ���vector 
        	sMap[s.substr(i, 10)]++;
		}
		for (map<string, int >::iterator it = sMap.begin(); it != sMap.end(); it++) {
			if (it->second > 1) result.push_back(it->first); 
		}
		return result;
    }
};
 
int main() {
	Solution s = Solution();
	string t;
	cin >> t;
	// AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT
	vector<string > v = s.findRepeatedDnaSequences(t); 
	for (int i = 0; i < v.size(); i++) cout << v[i] << endl;
	return 0;
}
