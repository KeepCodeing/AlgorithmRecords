#include <iostream>
#include <sstream>
#include <stack>
using namespace std;

// ǰ��֪ʶ��
/*
- ǰ׺���ʽ��ѭ����������
- ��׺���ʽ��ѭ����������
- ��׺���ʽ��ѭ����������
ֻҪ��ס��ʲô���ʽ����ʲô��ʲô�����'��'���ĸ�λ�ã������б�ʾ��������λ��...
�����ֱ��ʽ�����Խ���ջ��ʵ�֣����巽�����£�
�Ժ�׺���ʽΪ�������Ĵ���ʽ�͹����������ƣ������������������֣�����ѹ��ջ�У������ȡ�����ǲ�������
��ջ������Ԫ�ص��������ҽ�����Ӧ������Ȼ�󽫽������ѹ��ջ���ظ���ֱ��ջ��ֻʣһ��Ԫ��... 
*/ 

int str2num (string num) {
	stringstream ss;
	int res = 0;
	ss << num, ss >> res;
	return res;
}
bool check(char c) {
	return c == '+' || c == '-' || c == '*' || c == '/';
}
stack<long long > st;
int main() {
	string str, num = "";
	cin >> str;
	int sLen = str.size();
	for (int i = 0; i < sLen; i++) {
		if ('0' <= str[i] && str[i] <= '9') {
			num += str[i];
		} else {
			// ����ǰ�ַ���.���߲�����ʱ����ͳ�Ƶ����ַ���ת��Ϊ���֣�Ȼ��ѹ��ջ���Ϊ���ܳ���+++֮��ķ�����
			// �ַ��������֣��ʶ���Ҫ�ж��µ�ǰ�ַ��Ƿ�Ϸ�... 
			if (num != "") st.push(str2num(num)); 
			num = "";
			if (check(str[i])) {
				// �Ƚ���� 
				int b = st.top();st.pop();
				int a = st.top();st.pop();
//				cout << a << str[i] << b << endl;
				int res;
				switch(str[i]) {
					case '+' : 
						res = a + b;
						break;
					case '-' : 
						res = a - b;
						break;
					case '*' : 
						res = a * b;
						break;
					case '/' :
						// �����Ŀ�и��ӵ㣬�Ǿ���û˵�����������ֲ���... 
						res = a / b;
						break;
				}
				st.push(res);
			}
			
		}
	}
	// ���һ��ֻʣһ������.. 
	cout << st.top();
	return 0;
}
