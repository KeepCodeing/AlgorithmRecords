#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;

// Êý×ÖàË¶´.. 

int cal(string minStr, string maxStr) {
	stringstream ss;
	int minInt, maxInt;
	ss << minStr, ss >> minInt;
	ss.clear();
	ss << maxStr, ss >> maxInt;
	return maxInt - minInt;  
} 
string getStr(int num) {
	stringstream ss;
	string str;
	ss << num, ss >> str;
	return str;
}
int main() {
	string str;
	string mStr;
	cin >> str;
	sort(str.begin(), str.end());
	for (int i = str.size() - 1; i >= 0; i--) mStr += str[i];
	int res;
	int cnt = 1;
	while ((res = cal(str, mStr)) != 6174) {
		string temp = getStr(res);
		sort(temp.begin(), temp.end());
		str = temp;
		mStr = "";
		for (int i = temp.size() - 1; i >= 0; i--) mStr += temp[i];
		cnt++;
	}
	cout << cnt;
	return 0;
}
