#include <iostream>
#include <cstdio>
#include <set>
using namespace std;
set<int > s1, s2;
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	int t;
	while (n--) cin >> t, s1.insert(t);
	int ans = 0;
	while (m--) cin >> t, s2.insert(t);
	set<int >::iterator it;
	int s1Len = s1.size(), s2Len = s2.size();
	it = s1Len >= s2Len ? s1.begin() : s2.begin();
	cout << ans;
	return 0;
}
