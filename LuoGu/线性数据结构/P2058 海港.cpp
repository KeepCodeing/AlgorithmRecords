#include <iostream>
#include <map>
#include <set>
using namespace std;

map<int, int > ship;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	while (n--) {
		int t, k, p;
		cin >> t >> k;
		set<int > cnts;
		while (k--) cin >> p, cnts.insert(p);
		ship[t] = cnts.size();
		
	} 
	return 0;
}
