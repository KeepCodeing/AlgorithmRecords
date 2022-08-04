#include <iostream>
#include <cstdio>
using namespace std;
int main() {
	int n;
	cin >> n;
	int start = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%3d", start);
			start++;
		}
		cout << endl;
	}
	return 0;
}
