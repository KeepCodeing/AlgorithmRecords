#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// 我谔谔，1 * 3 == 3 * 1却要输出两次，3 * 3 == 3 * 3却只用输出一次... 
void printNum(int x, int n, int num) {
	cout << x << " * " << n << " = " << num << endl;
}
vector<int > res;
int main() {
	int n;
	cin >> n;
	int tn = n;
	// 把约数算出来，除数和约数就是一个数对 
	for (int i = 1; i <= n / i; i++) {
		// 本来打算直接输出的，但是这样不能满足所有情况，比如n=9，
		// 原本应该输出一个3*3的，但是因为下面判断i!=n/i所以只会
		// 输出一个3* 
		if (!(n % i)) {
			res.push_back(i); 
			if (i != n / i) res.push_back(n / i); 
		}
	}
	sort(res.begin(), res.end());
	int rLen = res.size();
	for (int i = 0; i < rLen; i++) printNum(res[i], tn / res[i], tn);
	return 0;
}
