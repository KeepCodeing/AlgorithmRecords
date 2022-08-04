#include <iostream>
#include <cmath>
using namespace std;

// 非负整数说明会有0 

int main() {
	double m, t, s;
	cin >> m >> t >> s;
	if (t == 0) {
		cout << m;
	} else {
		cout<<m-min(int(m),int(ceil(s/t)));
	}
	return 0;
}
