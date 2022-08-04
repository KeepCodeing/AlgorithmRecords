#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 多打几遍加深印象 

const int N = 300010;
int a[N], s[N];
vector<int > alls;
vector<pair<int, int > > add, query;
int find(int x) {
	// +1是因为我们设定的下标是从1开始的 
	return lower_bound(alls.begin(), alls.end(), x) - alls.begin() + 1;
}
int main() {
	int n, m;
	cin >> n >> m;
	while (n--) {
		int x, c;
		cin >> x >> c;
		alls.push_back(x); 
		add.push_back({x, c}); 
	}
	while (m--) {
		int l, r;
		cin >> l >> r;
		// 谔谔，之前理解错了，要把这些输入的数据想象成一个数轴，在这个数轴上有着各种刻度
		// 这个刻度就是l，r，x，下面的a数组才是用来统计区间和的... 
		alls.push_back(l);
		alls.push_back(r);
		query.push_back({l, r});   
	}
	sort(alls.begin(), alls.end());
	alls.erase(unique(alls.begin(), alls.end()), alls.end());
	// 想了下，这里加的过程必须要在去重后完成，而不能在输入的时候直接做，不然会出现重复 
	for (vector<pair<int, int > >::iterator it = add.begin(); it != add.end(); it++) {
		// 增加区间值，比如[1,3]有2,和6，对应执行的操作就是1 2
		// 3 6，转换成a就是a[1]=2,a[2]=6，然后在下面利用前缀和
		// 统计区间和 
		a[find(it->first)] += it->second;
	}
	s[0] = 0;
	// 前缀和统计区间和 
	for (int i = 1; i <= alls.size(); i++) {
		s[i] = s[i - 1] + a[i];
	}
	for (vector<pair<int, int > >::iterator it = query.begin(); it != query.end(); it++) {
		int l = find(it->first), r = find(it->second);
		cout << s[r] - s[l - 1] << endl;
	}
	return 0;
}
