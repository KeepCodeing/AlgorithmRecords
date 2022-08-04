#include <iostream>
#include <algorithm>
using namespace std;

// 想了会发现会统计字符数，但是不知道怎么按顺序输出
// 现在看来桶排计次数然后再把原字符遍历遍就行了 

int bucket[300];
int main() {
	string str;
	cin >> str;
	for (int i = 0; i < str.size(); i++) bucket[str[i]]++;
	for (int i = 0; i < str.size(); i++) if (bucket[str[i]] <= 1) cout << str[i];
	return 0;
}
