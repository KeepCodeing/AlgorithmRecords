#include <iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	string str;
	while(getline(cin, str)) {
		if (n-- >= 0) {
			cout << str << endl;
			cout << endl;
		} else {
			for (int i = 0; i < str.size(); i++) {
				if (str[i] != ' ') cout << str[i];
				else cout << endl << endl;
			}
		}
	}
	// while()
	return 0;
}
