#include <iostream>
#include <vector>
using namespace std;
vector<pair<int, int > > segs;
void meg(vector<pair<int, int > >& s) {
	vector<pair<int, int > > res;
	int sIndex = -2e9, eIndex = -2e9;
	for (vector<pair<int, int > >::iterator it = s.begin(); it != s.end(); it++) {
		if (eIndex < it->first) {
			if (sIndex != -2e9) res.push_back({sIndex, eIndex});
			 sIndex = it->first, eIndex = it->second;
		} else {
			eIndex = max(eIndex, it->second);
		}
	}
	if (sIndex != -2e9) res.push_back({sIndex, eIndex});
	segs = res; 
}
int main() {
	int n;
	cin >> n;
	while (n--) {
		int l, r;
		cin >> l >> r;
		segs.push_back({l, r}); 
	}
	meg(segs);
	cout << segs.size();
	return 0;
}
