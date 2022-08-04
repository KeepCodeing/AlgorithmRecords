#include <iostream>
using namespace std;

// 可以用个变量，因为给了总局数，不过感觉麻烦，故此用两个变量好了w 

int main() {
	int n, a, b;
	char c;
	// 忘记初始化，后面的变量值不确定... 
	a = b = 0;
	cin >> n;
	while (n--) {
		cin >> c;
		if (c == 'A') a++;
		else b++;
	}
	if (a > b) cout << "Anton";
	else if (a < b) cout << "Danik";
	else if (a == b) cout << "Friendship";
	cout << endl;
	return 0; 
}
