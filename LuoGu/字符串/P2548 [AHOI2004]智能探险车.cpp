#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

// 屑题目，看了半天才明白其意思，其实就是相同字符串输出
// 不同字符串输出* 
// 一开始想用个set统计，但细想下就知道不可行了，还是得用
// map统计单词个数 

map<string, int > mp;
vector<string > v;
int main() {
	int n, m;
	cin >> n >> m;
	string temp;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> temp;
			mp[temp]++;
			// 把键存起来，本来打算用set的，但是set排序了不好做 
			// 把第一行作为键列表，不然会有多余的key 
			// !count(v.begin(), v.end(), temp) && 之前为了保证键唯一的判断，不过没必要 
			if (i == 0) {
				v.push_back(temp); 
			}
		}
	}
	int vLen = v.size();
	for (int i = 0; i < vLen; i++) {
		if (mp[v[i]] == m) cout << v[i];
		else cout << '*';
		if (i != vLen - 1) cout << ' ';
	}
	return 0;
}
