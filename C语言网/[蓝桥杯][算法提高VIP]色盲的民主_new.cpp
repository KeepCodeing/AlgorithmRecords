#include <iostream>
#include <sstream>
#include <cstdio>
#include <map>
using namespace std;

// 看了之前的代码，和现在想的基本差不多，不过那时候似乎没有注意到：一行可以有多个字符串，也就是单纯的
// cin只能输入一个字符串..改成getline应该就可以了.. （太久没用甚至忘了这个函数的名字w..） 

map<string, int > vote;
int max_cnt = 0;
int main() {
	int n;
	cin >> n;
	// 注意getline会吞换行... 
	getchar();
	string str, temp;
	stringstream ss;
	while (n--) {
		getline(cin, str);
		ss << str;
		while (ss >> temp) vote[temp]++, max_cnt = max(vote[temp], max_cnt);
		ss.clear(); 
	}
	for (map<string, int >::iterator it = vote.begin(); it != vote.end(); ++it) {
		if (it->second == max_cnt) cout << it->first << endl;
	}
	return 0;
}
