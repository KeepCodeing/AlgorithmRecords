#include <iostream>
using namespace std;
int main() {
	int n, x = 0;
	string str;
	cin >> n;
	while (n--) {
		cin >> str;
		if (str == "++X" || str == "X++") x++;
		else x--;
	}
	cout << x << endl;
	return 0;
}
