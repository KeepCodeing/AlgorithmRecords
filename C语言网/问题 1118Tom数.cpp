#include <iostream>
using namespace std;
int main() {
	// 谔谔，真就不用long long见祖宗了..，没有搞清楚int范围坠毁了一次 
	long long num;
	// 4294967295
	while(cin >> num) {
		long long tot = 0;
		while (num) {
			tot += num % 10;
			num /= 10;
		}
		cout << tot << endl;
	}
	return 0;
}
