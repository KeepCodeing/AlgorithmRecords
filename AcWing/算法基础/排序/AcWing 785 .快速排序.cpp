#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int > vec;
int main() {
	int n, temp;
	cin >> n;	
	while (n--) cin >> temp, vec.push_back(temp);
	sort(vec.begin(), vec.end()); 
	int vLen = vec.size();
	for (int i = 0; i < vLen; i++) {
		cout << vec[i];
		if (i != vLen - 1) cout << ' ';
	}
	return 0;
}
