#include <iostream>
#include <vector>
using namespace std;
vector<int > vec;
int main() {
	int n;
	cin >> n;
	vec.push_back(n); 
	while (n != 1) {
		if (n % 2 != 0) n = n * 3 + 1;
		else n /= 2;
		vec.push_back(n); 
	}
	int vLen = vec.size() - 1;
	for (int i = vLen; i >= 0; i--) {
		cout << vec[i];
		if (i != 0) cout << ' ';
	}
	return 0;
} 
