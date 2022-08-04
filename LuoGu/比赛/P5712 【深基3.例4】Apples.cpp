#include <iostream>
using namespace std;
int main() {
	int c;
	cin >> c;
	if (c == 0) cout << "Today, I ate 0 apple.";
	if (c == 1) cout << "Today, I ate 1 apple.";
	if (c > 1) cout << "Today, I ate " << c << " apples.";
	return 0;
}
