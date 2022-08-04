#include <iostream>
#include <vector>
using namespace std;

// 居然不是多重背包... 

typedef long long LL;
vector<int > vec;
const int N = 1e5 + 10;
LL f[N];
int nums[3] = {5, 10, 20};
int main() {
	int n;
	cin >> n;
	n *= 10;
	int s;
	for (int i = 0; i < 3; i++) {
		cin >> s;
		for (int  j = 1; j <= s; s <<= 1) {
			vec.push_back(j * nums[i]); 
			s -= j;
		}
		if (s > 0) vec.push_back(s * nums[i]); 
	}
	int vLen = vec.size();
	// for (int i = 0; i < vLen; i++) cout << vec[i] << endl;
	f[0] = 1;
	for (int i = 0; i < vLen; i++) {
		for (int j = vec[i]; j <= n; j++) {
			f[j] += f[j - vec[i]];
		}
		
	}
	// for (int i = 0; i < 10000; i++) cout << f[i] << endl;
	cout << f[n];
	return 0;
}
