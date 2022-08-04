#include <iostream>
#include <map> 
#include <vector>
#include <set>
using namespace std;
// �����������뵽��ͨ������ȡ���ַ����ķ�ʽ������������У�����˳��һ�������ŵģ�
// ����ͨ��ͳ��A��B�ַ����Ĳ�ͬ�ַ��������⣬�����ͬ�ַ�����Ϊ2˵�����У����򲻿��� 

// ���۵Ľ�� 
//ͳ���ַ���A��B���ַ���ƥ����±ꡣ
//��ƥ����±���������� 0 �� 2 ʱ��������A�õ�B��
//��ƥ����±��������0ʱ��A��B���ַ���ȫ��ͬ������ҪA�����ظ��ַ���
//��ƥ����±��������2ʱ���жϽ��������ַ����Ƿ�ƥ�䡣

class Solution {
public:
    bool buddyStrings(string A, string B) {
    	// ����Ǳ������ 

		// ���Ȳ���
		if (A.size() < 2 || B.size() < 2) return false; 
		
        // AΪ�ջ���BΪ�� 
        if (!A.size() || A.empty() || !B.size() || B.empty()) return false;
        // A�ĳ��Ȳ�����B�ĳ���
		if (A.size() != B.size()) return false;
		// �ӣ���������ַ������ȶ�Ϊ2����ȱ���ab�������ǲ�ͬ�ģ��������aa���Ǿ�����ͬ����
		if (A.size() == 2 && B.size() == 2 && A[0] == B[1] && A[1] == B[0]) return true;
		// A����B ��������������Ŀ˵ֻ�ܽ���A��Ԫ�أ�Ҳ����˵�����ַ����һ����ͬ 
    	// ��ôA��B��Ϊ��Ҳ���У���Ϊ���Ȳ�����д������������ֹ���У� 
    	// ���������У���abab... 
        // if (A == B) return false;
		int cnt = 0; 
		int aLen = A.size();
		// �Ա��ַ����� ������ط���Ȼ��valueд����char����...�� 
//		map<char, char > m;
//		for (int i = 0; i < aLen; i++) {
//			m[A[i]]++;
//		}
//		for (int i = 0; i < aLen; i++) {
//			if (m[B[i]] <= 0) return false;
//			m[B[i]]--;
//		}
		vector<int > temp;
		// �Ա�A��B�ַ� 
        for (int i = 0; i < aLen; i++) {
        	if (A[i] != B[i]) {
        		cnt++;
        		// ���������ͬ�ַ����±� 
        		temp.push_back(i);
			}
        	if (cnt > 2) return false;
		}
		if (temp.size() == 0) {
            return set<char>(A.begin(), A.end()).size() < A.size();
        } else if (temp.size() == 2) {
            return A[temp[0]] == B[temp[1]] &&
                   A[temp[1]] == B[temp[0]];
        }
		return false;
    }
}; 
int main() {
	Solution s = Solution();
	string a, b;
	cin >> a >> b;
	cout << s.buddyStrings(a, b); 
	return 0;
}
