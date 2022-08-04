#include <iostream>
#include <vector>
using namespace std;
bool primes[1500000];
vector<int > vec;
int main() {
	int n;
	cin >> n;
	primes[0] = primes[1] = true;
	for (int i = 2;; i++) {
		if (!primes[i]) {
			vec.push_back(i); 
			
			for (int j = i * 2;; j += i) {
				primes[j] = true;
			}	
		}
		if (vec.size() > 100000) break;
	}	
	unsigned long long res = 1;
	for (int i = 0; i < n; i++) {
		res *= vec[i] % 50000;
	}
	cout << res;
	return 0;
}
