#include <iostream>
#include <algorithm>
using namespace std;

// �������е�����֮ǰ��һ����תԪ���ַ����⣬�����ͬ����˫ָ�룬������ת������������ַ��� 

class Solution {
public:
	// �ж��Ƿ����ַ��ķ��� 
	bool isAlpha(char c) {
		return 'A' <= c && c <= 'Z' || 'a' <= c && c <= 'z';
	}
    string reverseOnlyLetters(string S) {
    	// LeetCode�Ĺ��� 
        if (S.size() == 0 || S.empty()) return S;
        int left = 0, right = S.size() - 1;
        while (left < right) {
        	// �Ҳ����ַ��������£�������߶��ҵ��˾ͽ���λ�� 
        	if (!isAlpha(S[left])) {
        		left++;
			} else if (!isAlpha(S[right])) {
				right--;
			} else {
				// ��ֹ�ظ����� 
				swap(S[left++], S[right--]);
			}
		}
		return S;
    }
};

int main() {
	Solution s = Solution();
	string t;
	cin >> t;
	cout << s.reverseOnlyLetters(t); 
	return 0;
}
