#include <iostream>
#include <cstdio>
#include <map> 
#include <vector>
using namespace std;

// 想到了用一个map来维护变量，然后模拟 

typedef long long LL;
vector<string > vec;
map<string, LL > mp;
// 字符串转数字，可以用字符串流，但是没必要 
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
			// 处理=左边的变量名 
			if (str[i] != '=' && flag) {
				varname += str[i];
			} else {
				flag = false;
				if (str[i] == '=') continue;
				// 处理=右边的算式，分两种情况讨论 
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
		// 几种情况，只有一个算式，且该算式是一个数字
		// 只有一个算式，或该算式是一个已经存在的变量
		// 有两个算式，一个是数字，一个已经存在的变量
		// 有两个算式，两个都是数字/已经存在的变量 
		// 处理只有一个算式的情况
		if (rflag) {
			// 如果是一个已存在的变量，那么把它的值赋值给当前变量 
			if (mp.count(left)) {
				mp[varname] = mp[left];
			} else {
				// 相反就是一个数字，直接赋值
				mp[varname] = strToNum(left); 
			}
		} else {
			bool mflag = mp.count(left) && mp.count(right);
			 // 如果都是变量，直接相加 
			 if (mflag) mp[varname] = mp[left] + mp[right];
			 // 如果都不是变量，也是直接相加 
			 else if (!mflag) mp[varname] = strToNum(left) + strToNum(right);
			 // 如果有一个不是变量，分情况处理
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
