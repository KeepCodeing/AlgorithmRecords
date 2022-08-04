#include <iostream>
using namespace std;
string *strs, *words;

// findAC不能，主要思路就是找到第一个相同字符，然后自增对比字符 

bool Checker(string a,string b) {
    for(int i = 0, j = 0;i < a.size(); ++i){
        if(a[i] == b[j]) ++j;
        if(j == b.size())
		return true;
    }
    return false;
}
int main() {
	int n, m;
	cin >> n >> m;
	strs = new string[n];
	words = new string[m];
	for (int i = 0; i < n; i++) {
		cin >> strs[i];
		for (int j = 0; j < strs[i].size(); j++) strs[i][j] = tolower(strs[i][j]);
	}
	for (int i = 0; i < m; i++) {
		cin >> words[i];
		for (int j = 0; j < words[i].size(); j++) words[i][j] = tolower(words[i][j]);
	}
	int cnt;
	for (int i = 0; i < n; i++) {
		cnt = 0;
		for (int j = 0; j < m; j++) cnt += Checker(strs[i], words[j]);
		cout << cnt << endl;
	}
	delete[] strs;
	return 0;
}
