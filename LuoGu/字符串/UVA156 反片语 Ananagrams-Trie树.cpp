#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

// Trie树写法：同样需要把原字符串和排序后的字符对应，用来省去一次排序
// 做法就是把所有排序过的字符存到树里，然后统计这个字符串出现的次数
// 出现一次就是无法被组成的字符串 

const int N = 1e5 + 10;
int son[N][26], cnt[N], id = 0;
map<string, string > mp;
// Trie树板子 
string getStr(string str) {
	int sLen = str.size();
	for (int i = 0; i < sLen; i++) str[i] = tolower(str[i]);
	return str;
}
void add(string str) {
	int p = 0, sLen = str.size();
	for (int i = 0; i < sLen; i++) {
		int cur = str[i] - 'a';
		if (!son[p][cur]) son[p][cur] = ++id;
		p = son[p][cur];
	}
	cnt[p]++;
}
bool fd(string str) {
	int p = 0, sLen = str.size();
	for (int i = 0; i < sLen; i++) {
		int cur = str[i] - 'a';
		// 这里可有可无，准确来说出现非法字符串的可能性为0% 
		// if (!son[p][cur]) return false;
		p = son[p][cur];
	}
	// 判断下这个字符串是否只出现了一次 
	return cnt[p] == 1;
}
int main() {
	string str, temp;
	while (cin >> str) {
		if (str == "#") break;
		temp = getStr(str);
		sort(temp.begin(), temp.end());
		// 将排序后的字符串和原字符串进行映射，这样可以省去一次排序 
		mp[str] = temp;
		add(temp);
	}
	// 压行什么的完全没必要啊 
	for (map<string, string >::iterator it = mp.begin(); it != mp.end(); it++) {
		// 如果key字符串的排序形式（value）只出现过一次，那么这个字符串就是唯一的 
		if (fd(it->second)) cout << it->first << endl;
	}
	return 0;
} 
