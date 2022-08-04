#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// 池沼了，本来打算离散化做的，结果忘了是怎么做了... 

// 不知道这个题能不能用离散化，不过题目很像，但是被five做不出来（无能） 

const int N = 5 * 100010;
typedef pair<int, int > PII;
long long s[N], nt[N];
int n, m;
vector<PII > add, query; 
vector<int > nums;
int findIndex(int num) {
	return (lower_bound(nums.begin(), nums.end(), num) - nums.begin()) + 1;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	while (n--) {
		int t;
		cin >> t;
		nums.push_back(t);
	}
	int op, x, y;
	while (m--) {
		cin >> op >> x >> y;
		if (op == 1) {
			add.push_back(PII(x, y));
		} else {
			nums.push_back(x); 
			nums.push_back(y); 
			query.push_back(PII(x, y));
		}
	}
	sort(nums.begin(), nums.end()); 
	nums.erase(unique(nums.begin(), nums.end()), nums.end());
	for (int i = 0; i < add.size(); i++) {
		nt[findIndex(add[i].first)] += add[i].second;
	}
	s[0] = 0;
	for (int i = 1; i <= nums.size(); i++) {
		s[i] = s[i - 1] + nt[i];
	}
	for (int i = 1; i <= nums.size(); i++) {
		cout << s[i] << ' ';
	}
	cout << endl;
	for (int i = 0; i < query.size(); i++) {
		cout << s[findIndex(query[i].second)] - s[findIndex(query[i].first) - 1] << endl;
	}
	return 0;
}
