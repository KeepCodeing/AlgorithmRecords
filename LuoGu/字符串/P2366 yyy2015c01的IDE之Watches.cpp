#include <iostream>
#include <cstdio>
#include <map> 
#include <vector>
using namespace std;

// �뵽����һ��map��ά��������Ȼ��ģ�� 

typedef long long LL;
vector<string > vec;
map<string, LL > mp;
// �ַ���ת���֣��������ַ�����������û��Ҫ 
LL strToNum(string str) {
	LL res = 0;
	int sLen = str.size();
	for (int i = 0; i < sLen; i++) res = res * 10 + (int)(str[i] - '0');
	return res;
}
int main() {
	int n;
	scanf("%d", &n);
	string str;
	while (n--) {
		cin >> str;
		int sLen = str.size();
		bool flag = true, rflag = true;
		string varname;
		string left = "", right = "";
		for (int i = 0; i < sLen - 1; i++) {
			// ����=��ߵı����� 
			if (str[i] != '=' && flag) {
				varname += str[i];
			} else {
				flag = false;
				if (str[i] == '=') continue;
				// ����=�ұߵ���ʽ��������������� 
				if (str[i] != '+' && rflag) {
					left += str[i];
				} else {
					rflag = false;
					if (str[i] == '+') continue;
					right += str[i];
				}
				
			}
		} 
		// cout << varname << ' ' << left << ' ' << right << endl;
		if (!mp.count(varname)) vec.push_back(varname);
		// ���������ֻ��һ����ʽ���Ҹ���ʽ��һ������
		// ֻ��һ����ʽ�������ʽ��һ���Ѿ����ڵı���
		// ��������ʽ��һ�������֣�һ���Ѿ����ڵı���
		// ��������ʽ��������������/�Ѿ����ڵı��� 
		// ����ֻ��һ����ʽ�����
		if (rflag) {
			// �����һ���Ѵ��ڵı�������ô������ֵ��ֵ����ǰ���� 
			if (mp.count(left)) {
				mp[varname] = mp[left];
			} else {
				// �෴����һ�����֣�ֱ�Ӹ�ֵ
				mp[varname] = strToNum(left); 
			}
		} else {
			bool mflag = mp.count(left) && mp.count(right);
			 // ������Ǳ�����ֱ����� 
			 if (mflag) mp[varname] = mp[left] + mp[right];
			 // ��������Ǳ�����Ҳ��ֱ����� 
			 else if (!mflag) mp[varname] = strToNum(left) + strToNum(right);
			 // �����һ�����Ǳ��������������
			 else if (!mp.count(left)) mp[varname] = strToNum(left) + mp[right];
			 else mp[varname] = mp[left] + strToNum(right);
		}
		// cout << varname << ' ' << mp[varname] << endl;
	}
	int vLen = vec.size();
	for (int i = 0; i < vLen; i++) {
		cout << vec[i] << ' ' << mp[vec[i]];
		if (i != vLen - 1) cout << endl;
	}
	return 0;
}
