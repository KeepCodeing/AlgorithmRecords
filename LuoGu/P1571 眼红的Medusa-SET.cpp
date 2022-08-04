#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

// 应该可以用个数组标记某个元素是否出现过，这就类似于桶排的思想 
// 看了下数据范围，太大了，不能用桶排，但是应该可以用set

// 坠毁，没想到用一个map标记元素是否出现过，然后去第一个数组
// 找 

map<long long, int> mp;
vector<long long > v;
int main() {
	int n, m;
	cin >> n >> m;
	long long temp;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		v.push_back(temp); 
	}
	for (int i = 0; i < m; i++) {
		cin >> temp;
		mp[temp] = 1;
	}
	for (int i = 0; i < n; i++) {
		if (mp[v[i]]) {
			cout << v[i];
			if (i != n - 1) cout << ' ';
		}
	}
	return 0;
}
