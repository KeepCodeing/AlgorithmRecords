#include <iostream>
#include <sstream>
using namespace std;

// �������Ƿϵ�һ����...
// ������һ���ַ���ģ���⣬����Ȿfive��֭��0��w����������ʱ��Ĵ��뻹�ǱȽ�
// naive�ģ���Ȼ��ʱ��Ӧ���Ѿ���һ��������...������ҵ�ȵ�Ҳ���������ˣ��繤��
// ����������Ŷ����Ѱ�...��ô�����Ǹ���Զ���£����ڿ��ľͺðգ�Ȼ�������ڲ���̰�ģ� 
// ��0������getline��ԭ��...��֮��cin�������� 

// ׹��... 

bool checker(char c) {
	return c >= '0' && c <= '9';
}
long str2num(string str) {
	long t;
	stringstream ss;
	ss << str, ss >> t;
	return t;
}
int main() {
	string str, temp;
	while (cin >> temp) str += temp;
	// cout << str;
	int sLen = str.size();
	int idx = str.find("+"), idx2 = str.find("=");
	if (idx == str.npos) idx = str.substr(0, idx2).find_last_of("-");
	// cout << endl;
	string s1 = str.substr(0, idx), s2 = str.substr(idx, idx2 - 1), s3 = str.substr(idx2 + 1);   
	long t;
	if (s1.find("?") != s1.npos) {
		t = str2num(s3) - str2num(s2);
		if (s1.find("-") != s1.npos) t *= -1;
		cout << t;
	} else if (s2.find("?") != s2.npos) {
		t = str2num(s3) - str2num(s1);
		if (s2.find("-") != s2.npos) t *= -1;
		cout << t;
	} else {
		t = str2num(s1) + str2num(s2);
		if (s3.find("-") != s3.npos) t *= -1;
		cout << t;
	}
	// cout << s1 << ' ' << s2 << ' ' << s3 << endl;  
	return 0;
}
