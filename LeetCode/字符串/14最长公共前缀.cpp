#include <iostream>
#include <vector>
using namespace std;
// ������ÿ�α�����¼��һ���ַ����ĵ�ǰ��ͷԪ�ؼ��ɣ��ں��������жԱȿ�ͷ�Ƿ���ͬ
// ��ͬ�����Աȣ���ͬ����ѭ�� 

// ���ǲ�ȫ������û����⵽λ 
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
    	// û���жϴ�����ַ����������������ѭ������ 
    	if (strs.empty() || !strs.size()) return "";
    	int sLen = strs.size();
    	bool flag = true;
    	int start = 0;
    	char head;
    	// ���ȱ������� 
    	while (flag) {
	    		for (int i = 0; i < sLen; i++) {
	        	// ��ǿ�ͷ 
	        	if (i == 0) {
					head = strs[0][start];
				}
				// �Աȿ�ͷ����ֹԪ�س��磨�����ж�֮ǰΪС�ڣ����ǲ��ܵ��� 
				if (strs[i][start] != head || start >= strs[i].size()) {
        			flag = false;
        			break;
				}
			}
			if (!flag) break;
			start++;
		}
		string result;
        for (int i = 0; i < start; i++) {
            result += strs[0][i];
        }
        return result;
    }
}; 
int main() {
	Solution s = Solution();
	vector<string > v;
	string str;
	while (cin >> str) {
		v.push_back(str);
	}
	cout << s.longestCommonPrefix(v);
	return 0;
}
