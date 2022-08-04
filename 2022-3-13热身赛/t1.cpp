#include <iostream>
using namespace std;

int main() {
	int t;
	while (cin >> t) {
		for (int i = 0; i < t; i++) {
			for (int j = 0; j < t - i - 1; j++) cout << " ";
			for (int j = 0; j < i * 2 + 1; j++) {
				cout << "*";
			}
			cout << endl;
		}	
		for (int i = t - 1; i > 0; i--) {
			for (int j = 0; j <t -  i; j++) cout << " ";
			for (int j = 0; j < i * 2 - 1; j++) {
				cout << "*";
			}
			cout << endl;
		}
	}
	return 0;
}
