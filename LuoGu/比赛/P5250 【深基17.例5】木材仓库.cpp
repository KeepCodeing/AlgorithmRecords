#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
set<int > s;
int main() {
	set<int > s;
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	while (n--) {
		int op, x;
		cin >> op >> x;
		if (op == 1) {
			if (s.count(x)) {
				cout << "Already Exist" << endl;
			} else {
				s.insert(x); 	
			}			
		} else {
			if (s.size()) {
				set<int >::iterator lower, upper;
				set<int >::iterator t = s.begin();
				if (!s.count(x)) {
					lower = lower_bound(s.begin(), s.end(), x);
					upper = upper_bound(s.begin(), s.end(), x);
					cout << *lower << endl;
				} else {
					s.erase(x); 
					cout << x << endl;
				}
			} else {
				cout << "Empty" << endl;
			}
		}
	}
	return 0;
}
