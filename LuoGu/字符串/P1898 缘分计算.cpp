#include <iostream>
#include <algorithm>
using namespace std;
void sw(char& a, char &b) {
	char t;
	t = a, a = b, b = t; // 
}
void rev(string& str) {
	int l = 0, r = str.size() - 1;
	while (l < r) swap(str[l++], str[r--]); // ����˫ָ���㷨��ת�ַ��� 
}

int main() {
	int st;
	string str, res, temp;
	cin >> str >> st;
	int t, sLen = str.size();
	for (int i = 0; i < sLen; i++) {// ��λ����ת���ַ�����Ϊ�˷������ﻹ�����η�ת 
		t = st + str[i] - 'A', temp = "";
		while (t) temp += (char)(t % 10 + '0'), t /= 10;
		rev(temp), res += temp;// ��ת���ǵó���������
	}
	int rLen;
	while (true) { // ѭ������ֱ�������˺Ϸ���
		temp = "";
		rLen = res.size();
		if (rLen <= 3) {
			if (res == "100") break;
			else if (rLen <= 2) break;
		}
		for(int i = 0; i < rLen - 1; i++) temp += (char)((res[i] - '0' + res[i + 1] - '0') % 10 + '0'); // ����ĿҪ��ȡ�������������ĸ�λ�ٰ���ת���ַ� 
		res = temp; // ���½� 
	}
	if (res[0] == '0') cout << res[1]; // ���������ַ��ǲ���0 
	else cout << res;
	return 0;
}
