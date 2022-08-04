#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
using namespace std;
typedef set<int >::iterator st;
set<int > s1, s2, s3;
vector<int > res;
int main() {
	int n, m, t;
	cin >> n;
	while (n--) cin >> t, s1.insert(t), s3.insert(t) ;
	cin >> m;
	while (m--) cin >> t, s2.insert(t), s3.insert(t) ;
	for (st it = s1.begin(); it != s1.end(); it++) {
		if (s2.count(*it)) res.push_back(*it); 
	}
	sort(res.begin(), res.end());
	int rLen = res.size();
	for (int i = 0; i < rLen; i++) {
		cout << res[i];
		if (i != rLen - 1) cout << ' ';
	}
	cout << endl;
	res.clear();
	st it1 = s3.begin();
	int sLen = s3.size();
	for (int i = 0; i < sLen; i++) {
		cout << *it1;
		if (i != sLen - 1) cout << ' ';
		it1++;
	}
	cout << endl;
	for (st it = s1.begin(); it != s1.end(); it++) {
		if (!s2.count(*it)) res.push_back(*it); 
	}
	rLen = res.size();
	for (int i = 0; i < rLen; i++) {
		cout << res[i];
		if (i != rLen - 1) cout << ' ';
	}
	return 0;
}
