#include <iostream>
using namespace std;
int main() {
	// ���̣���Ͳ���long long��������..��û�и����int��Χ׹����һ�� 
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
