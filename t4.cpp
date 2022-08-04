#include <iostream>
#include <vector>
#define endl '\n'
using namespace std;

typedef long long LL;

vector<LL > vec;
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	LL num = 2021041820210418;
	for (LL i = 1; i <= num / i; i++) {
		if (num % i == 0) {
			vec.push_back(i);
			if (num / i != i) vec.push_back(num / i);
		} 
	}
	int vLen = vec.size(), res = 0;
	for (int i = 0; i < vLen; i++) {
		for (int j = 0; j < vLen; j++) {
			for (int k = 0; k < vLen; k++) {
				if (vec[i] * vec[j] * vec[k] == num) {
					res++;
				}
			}
		}
	}
	cout << res;
	return 0;
}
