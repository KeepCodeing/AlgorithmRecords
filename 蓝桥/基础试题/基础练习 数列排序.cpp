#include <iostream>
#include <vector> 
#include <algorithm>
using namespace std;
vector<int > vec;
int main() {
	int n, t;
	cin >> n;
	while(n--) cin >> t, vec.push_back(t);
	sort(vec.begin(), vec.end()); 
	int vLen = vec.size();
	for (int i = 0; i < vLen; i++) {
		cout << vec[i];
		if (i != vLen - 1) cout << ' ';
	}
	return 0;
}
