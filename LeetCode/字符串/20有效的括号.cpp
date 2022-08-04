#include <iostream>
#include <stack>
#include <map>
using namespace std;
// �����������뷴���ŵ�ʱ��Ա���ǰ���ǲ��������ż��ɣ�����ջ��������������ͬʱ
// ������map����ַ��� 
class Solution {
public:
    bool isValid(string s) {
    	// ��Ŀ�涨 
    	if (s.size() == 0 || s.empty()) return true;
    	// ��ͷΪ�����ſ϶����Ϸ� 
    	if (s[0] == ')' || s[0] == ']' || s[0] == '}') return false; 
    	// ���Ȳ��Գƿ϶����Ϸ�
		if (s.size() % 2 != 0) return false; 
        map<char, char > m;
        m[')'] = '(', m[']'] = '[', m['}'] = '{';
        int sSize = s.size(); 
        stack<char > strStack;
        // ѹ��Ԫ�� 
        for (int i = 0; i < sSize; i++) {
        	// ����Ƿ����ţ���ջ�Ա��Ƿ�ƥ�������� 
        	if (s[i] == ')' || s[i] == ']' || s[i] == '}') {
        		// ��ջ�Ա� 
        		if (m[s[i]] != strStack.top()) return false;
        		// C++�����Զ�ɾ��Ԫ�أ�����Ҫ�ֶ����÷���ɾ�� 
        		strStack.pop();
        		continue;
			}
        	strStack.push(s[i]);
		}
		// ��������ȫ�������ţ���ջԪ�ز���ı䣬�����ȫ��ƥ������ջ�Ϳ��� 
		return strStack.empty();
    }
};
int main() {
	Solution s = Solution();
	string t;
	cin >> t;
	cout << s.isValid(t);
	return 0;
}
