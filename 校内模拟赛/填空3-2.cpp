#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
set<string > ss;
int main() {
	string str = "LANQIAO";
	int cnt = 0;
	sort(str.begin(), str.end());
	do {
		cout << str << endl;
		ss.insert(str); 
		cnt++;
	} while (next_permutation(str.begin(), str.end()));
	cout << cnt << endl;
	cout << ss.size() << endl;
	return 0;
}
