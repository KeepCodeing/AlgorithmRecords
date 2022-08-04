#include <iostream>
using namespace std;
// ˼·�������Լ�дһ�������Ƚ�hashֵ���㷨

// ���Լ�д��hashֵ�㷨׹������Σ������������Ĵζ�����Ϊ�Լ����ǲ�ȫ�����ܣ�
// hash�㷨���ڵ�����Ϊ������ͬ�ַ�������ĸ��ͬ������hashֵ��ͬ����ab��ba��
// ��ͻᵼ�´���ƥ�䣬����������õ�substr��ƥ��� 

class Solution {
public:
	// �Զ���Ļ�ȡ��ϣֵ�ĺ��� 
	int getHash(string s) {
		const int seed = 133;
		long hash = 0;
		// ׹�٣����Լ�д��hashֵ�㷨�޷���֤hashΨһ 
		for (int i = 0; i < s.size(); i++) {
			hash = s[i] * seed + hash;
		}
		return hash % 114514;
	}
    int strStr(string haystack, string needle) {
    	// �����Ϊ���ַ���ôҲ��ƥ�䵽�� 
    	if ((haystack.empty() || haystack.size() == 0) && (needle.size() == 0 || needle.empty())) return 0;
    	// ��Ҫƥ����ַ�������ʱ����0����ĿҪ�� 
        if (needle.size() == 0 || needle.empty()) return 0;
        int nSize = needle.size();
        int hSize = haystack.size();
        int result = 0;
        // ��ʼ�����Ա� 
        // ����Ҫ��������硱��ֹ©�����һ���ַ��� 
		for (int i = 0; i <= hSize - nSize; i++) {
			// ֱ�ӶԱ��ַ������򵥴ֱ� 
			if (haystack.substr(i, nSize) == needle) return i;
		} 
		return -1;
    }
}; 
int main() {
	Solution s = Solution();
	string a, b;
	cin >> a >> b;
	cout << s.strStr(a, b); 
	return 0;
}
