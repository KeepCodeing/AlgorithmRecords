#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int n;
	cin >> n;
	while (n--) {
		int x;
		cin >> x;
		vector<int > vec;
		for (int i = 1; i <= x / i; i++) {
			if (x % i == 0) {
				vec.push_back(i);
				if (i != x / i) vec.push_back(x / i);  
			}
		}
		sort(vec.begin(), vec.end());
		for (int i = 0; i < vec.size(); i++) cout << vec[i] << ' ';
		cout << endl;
	}
	return 0;
}
