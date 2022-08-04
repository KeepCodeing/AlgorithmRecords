#include <iostream>
using namespace std;

// 水题第十五弹（绝望） 

int main() {
	int n, res = 0;
	cin >> n;
	string str;
	while (n--) {
		cin >> str;
		if (str == "++X" || str == "X++") res++;
		else res--; 
	}
	cout << res;
	return 0;
}
