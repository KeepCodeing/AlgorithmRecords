#include <iostream>
using namespace std;

// ���˰���˼·��ž����ø�Ͱͳ������ĸ���ִ�������������»����ǿ��е�
// �������������ܳ�Ҳ�Ǻ�������
// ���ǿ���д���������Ӷ̵�����ȡ�Ӵ���Ȼ��ͺ���Ĵ��Աȣ������ַ���ͬ
// ������������Ա����˶�û��������˵���𰸳����ˣ���ôһ��������ƺ�
// ���Ǹ���������+hash����... 
// �·��������֣���ʵ�ȿ��԰��ջ������ڵ�˼·����ȡ�Ӵ���Ȼ������
// count()����ȥԭ�����ң�������count()�ķ���ֵ�����Ӵ��ĳ��ȣ����
// ����������ԭ�����ȣ���˵�������˴𰸣��ݣ�count()�������ܲ����ַ���.. 

// ԭ�ַ���Ҫͳ�Ƹ������ַ������� 
int countStr(string s, string t, int r) {
	int cnt = 0;
	// �ַ������������жԱȵ���ȷ��ʽ... 
	for (int i = 0; i < s.size(); i += r) cnt += s.substr(i, r) == t ? 1 : 0;
	return cnt;
}

int main() {
	string str;
	cin >> str;
	int sLen = str.size();
	for (int i = 1; i <= sLen; i++) {
		// ��ȡa~a+i���ַ���
		int maxLen = countStr(str, str.substr(0, i), i);
		if (i * maxLen == sLen) {
			cout << maxLen;
			break;
		}
	}
	return 0;
} 
