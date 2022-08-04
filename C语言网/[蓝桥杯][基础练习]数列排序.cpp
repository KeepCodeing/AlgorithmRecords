#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int > vec;
int main() {
	int n, num;
	cin >> n;
	while (n--) cin >> num, vec.push_back(num);
	sort(vec.begin(), vec.end());
	for (vector<int >::iterator it = vec.begin(); it != vec.end(); ++it) cout << *it << ' '; 
	return 0;
}
