#include <iostream>
#define endl '\n'
using namespace std;
long long sum = 0;
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int num;
	while (cin >> num) sum += num;
	cout << sum;
	return 0;
}
