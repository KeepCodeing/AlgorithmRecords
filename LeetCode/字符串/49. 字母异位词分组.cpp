#include <iostream>
#include <vector> 
#include <algorithm>
#include <map>
using namespace std;

// ��������������+HashTable�����ǿ���ⷢ�ֺ���Ҳ�����Լ�ʵ��һ��hash�����������Ļ���λ���ַ���ͬ
// Ȼ������ǳ���һ�𣬻�õĽ��һ����ͬ 

class Solution {
public:
    vector<vector<string> > groupAnagrams(vector<string>& strs) {
        map<string, vector<string > > t;
        vector<vector<string> > result;
        if (strs.size() == 0 || strs.empty()) return result;
        int sLen = strs.size();
        // ͳ����λ�ʣ�����ŵ�һ��vector�� 
        for (int i = 0; i < sLen; i++) {
        	string temp = strs[i];
        	// ���򣬷���Ա� 
        	sort(strs[i].begin(), strs[i].end());
        	t[strs[i]].push_back(temp);
		}
		// ��valueȡ������װ 
		for (map<string, vector<string > >::iterator it = t.begin(); it != t.end(); it++) {
			result.push_back(it -> second); 
		}
		return result;
    }
};

int main() {
	return 0;
}
