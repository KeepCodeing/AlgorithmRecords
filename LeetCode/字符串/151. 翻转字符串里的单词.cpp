#include <iostream>
#include <sstream>
#include <stack>
using namespace std;

// ���������ˢ�˺ö�...��Ȼûʲô��˼������Ҳ����������ˢ�ɣ���֮ǰ��������ֻ�ό��֮���...
// ��ô�������LeetCode�ϵ�ˮ�⣬��˼���Ǹ��ݿո��з��ַ���Ȼ�����������Ϊ�п��ܿո�ܶ࣬
// д��ѭ�����жϿ��ܱȽ��鷳���Ƚϼ򵥵ķ��������ַ��������ַ����������Զ�ȥ���ո�Ȼ�������
// ����Ļ���ջ����vector������...

class Solution {
public:
	stack<string > st;
    string reverseWords(string s) {
		string temp, res;
		stringstream ss;
		ss << s;
		while (ss >> temp) st.push(temp); 
    	while (st.size()) {
    		res += st.top();st.pop();
    		// ע�����ȳ�ջ�� 
    		if (st.size() != 0) res += ' ';
		}
        return res;
	}
}; 

int main() {
	string str = "hello world i  love   C++ it is    fun", temp;
	stringstream ss;
	ss << str;
	while (ss >> temp) {
		cout << temp << ' ';
	}
	return 0;
}
