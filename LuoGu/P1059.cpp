#include <iostream>
#include <set>
using namespace std;
int main() {
	int n, num;
	set<int > result;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		result.insert(num);
	}

	for (set<int >::iterator it = result.begin(); it != result.end(); it++) {
		cout << *it << ' ';
	}
	return 0;
} 
