#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

// 大脑降级，最简单的对比字符串不会了 
// 主要是用排序加set 

set<string > res;
int main() {
	int n;
	cin >> n;
	string temp;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		sort(temp.begin(), temp.end());
		res.insert(temp); 
	}
	cout << res.size();
	return 0;
}
