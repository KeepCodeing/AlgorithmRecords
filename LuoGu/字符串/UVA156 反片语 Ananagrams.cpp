#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

// 紫书上给出了一种排序两次的做法，这里把排序后的字符串和排序前的字符串对应起来了
// 免去了一次排序...

// 另外这个题应该可以用Trie树做，我认为这是好的，没有任何坏处 

map<string, int > mp;
map<string, string > pm;
vector<string > vec, res;
string solve(string str) {
	int sLen = str.size();
	for (int i = 0; i < sLen; i++) str[i] = tolower(str[i]);
	sort(str.begin(), str.end());
	return str;
}
int main() {
	string str, temp;
	while (cin >> str) {
		if (str == "#") break;
		temp = solve(str);
		mp[temp]++;
     // 省去第二次排序的里技：直接多开个map把排序后的字符和原字符对应就行
		pm[str] = temp;
		vec.push_back(str); 
	}
	int vLen = vec.size();
	for (int i = 0; i < vLen; i++) {
    // 通过原字符取到排序字符，再通过排序字符询问这个字符出现次数
		if (mp[pm[vec[i]]] != 1) continue;
		res.push_back(vec[i]); 
	}
	sort(res.begin(), res.end());
	int rLen = res.size();
	for (int i = 0; i < rLen; i++) {
		cout << res[i] << endl;
		//if (i != rLen - 1) cout << endl;
	}
	return 0;
} 
