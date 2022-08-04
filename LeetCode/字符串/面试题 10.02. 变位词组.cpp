#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

// �������ϵ��Ǹ���λ��һ����ֻ��������Ҫ�������飬���ǵ�Trie����LeetCode�ϱȽ�
// �������Ի���дmap����...
// ������֮ǰд�ģ��Ǹ���Ҫͳ�Ƶ����޷�����ɵĴʣ���ô���������Trie�����鷳��... 
// ��ô˼·���Ƕ�ÿ��Ԫ�ؽ�������Ȼ��ӳ�䵽map�����Ӧ�ÿ���ʡ�ܶ�vector������
// �ñ�֤����˳��֮��Ķ���... 

class Solution {
public:
	map<string, vector<string > > vmp;
	vector<vector<string > > res;
    vector<vector<string> > groupAnagrams(vector<string>& strs) {
		int sLen = strs.size();
		if (sLen == 0) return res;
		string temp;
		for (int i = 0; i < sLen; i++) {
			temp = strs[i];
			sort(temp.begin(), temp.end());
			vmp[temp].push_back(strs[i]);
		}
		for (map<string, vector<string > >::iterator it = vmp.begin(); it != vmp.end(); it++) 
			res.push_back(it->second); 
		return res;
    }
};

int main() {
	return 0;
}
