#include <iostream>
#include <set>
using namespace std;
typedef long long LL;
set<int > res;
int main() {
	// м��Ŀ��û�����ݷ�Χ�����û��long long׹����w.. 
	LL n, num = 1;
	cin >> n;
	for (int i = 2; i <= n / i; i++) 
		while (!(n % i)) res.insert(i), n /= i;
	if (n > 1) res.insert(n);
	for (set<int >::iterator it = res.begin(); it != res.end(); ++it) num *= *it;
	cout << num;
	return 0;
}
