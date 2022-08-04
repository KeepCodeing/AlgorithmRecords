#include <iostream>
using namespace std;

// �е㵹���ĸо�w
// �������֮ǰ��Ϊ�Լ���ǰ�����ˣ�Ȼ��ʼ���㷨�������˸�O(n^3)��Ȼ��û����֤
// �������˸�O(n^2)���㷨����ȫ�ı�����Ȼ������һ���㷨�Ǹ��ٵ�w����������trie
// ����ûʲô����... 

// д�˰��췢��O(n^2)��ʱ�ˣ������� 

class Solution {
public:
	bool checker(string str) {
		bool bucket[256];
		int sLen = str.size();
		fill(bucket, bucket + 256, false);
		for (int i = 0; i < sLen; i++) {
			if (bucket[str[i]]) return false;
			bucket[str[i]] = true;
		}
		return true;
	}
    int lengthOfLongestSubstring(string s) {
        string temp;
		int sLen = s.size(), res = -1, tLen;
		for (int i = 0; i < sLen; i++) {
			// �����ȡ�ܷ��ˣ�Ӧ���Ǵ�i��sLen����ȡһ�飬�������ֱ��дj = 1; j < slen����ȡ�ܶ�Σ����������
			// д��sLen - i + 1����ֹ��ν�ȡ 
			for (int j = 1; j < sLen - i + 1; j++) {
				// ����������substr�����ԣ���ָ����β�Զ���ȡ���ַ���β���������Ժܷ���ĴӺ���ǰ��ȡ�Ӵ�
				// ��i���λ�ã����ָ��Ϊi��j�����㣬����������˻�û������w 
				temp = s.substr(i, j), tLen = temp.size();
				// ����������̱�ˣ�Ҫ�е������ַ�������ַ���û���ظ��������ж����ַ�����û���ظ�w 
				if (checker(temp)) res = max(res, tLen); 
			}
		}
		return res;
    }
};

bool checker(string str) {
	bool bucket[256];
	int sLen = str.size();
	fill(bucket, bucket + 256, false);
	for (int i = 0; i < sLen; i++) {
		if (bucket[str[i]]) return false;
		bucket[str[i]] = true;
	}
	return true;
}
// �ȸ��������̵� 
int main() {
	
	return 0;
}
