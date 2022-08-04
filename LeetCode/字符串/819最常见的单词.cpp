#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;
// �������ȷָ��ַ�������ͳ���ַ������ִ����Լ��ж����Ƿ��ڽ��ô��б��У�����ֱ����
// �ָ�Ĺ������ж����ڲ��ڽ��ô��б���

class Solution {
public:
	string splitStr(string p, vector<string>& banned) {
		int maxCnt = 0;
		string strTemp, result;
		map<string, int > m;
		// ��ֹ�������һ���ַ��� 
		p += ' ';
		// �Ե��ʽ��м��� 
		for (int i = 0; i <= p.size(); i++) {
			if (p[i] >= 'A' && p[i] <= 'Z' || p[i] >= 'a' && p[i] <= 'z') {
				strTemp += tolower(p[i]);
			} else {
				
				// conut������ͳ�Ƹõ����Ƿ������banned�У�����������᷵��Ԫ�ظ��� 
				// ע��count�����෽�� 
				// ������ǽ��ô� ��ע������Ĳ�Ϊ���жϣ�����ǽ��ô�������ַ���֮��
				// �����˷���ĸ���ַ����ͻ�ֱ�ӽ���else����ͳ�� 
				if (count(banned.begin(), banned.end(), strTemp) == 0 && !strTemp.empty()) {
					m[strTemp]++;
					// ͳ�Ƴ��ָ��������س������ĵ��� 
					if (m[strTemp] > maxCnt) {
						// ���³��������ַ����������Լ��ַ��� 
						maxCnt = m[strTemp];
						result = strTemp;
					}
				}
				// �����ǲ��ǽ��ôʶ�����ַ��� 
				strTemp.clear();
			}
		}
		return result;
	}
    string mostCommonWord(string paragraph, vector<string>& banned) {
    	if (paragraph.size() <= 0) return paragraph;
        return splitStr(paragraph, banned);
    }
};
 
int main() { 
	Solution s = Solution();
	vector<string > v;
	v.push_back("hit");
	cout << s.mostCommonWord("Bob hit a ball, the hit BALL flew far after it was hit.", v); 
	return 0;
}
