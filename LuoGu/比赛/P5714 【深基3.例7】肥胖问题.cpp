#include <iostream>
using namespace std;
int main() {
	long double m, h;
	cin >> m >> h;
	long double ans = m / (h * h);
	if (ans < 18.5) cout << "Underweight";
	else if (ans >= 18.5 && ans < 24) cout << "Normal";
	else cout << ans << endl << "Overweight";
	return 0;
}
