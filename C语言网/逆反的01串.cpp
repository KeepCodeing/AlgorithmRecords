#include <iostream>
using namespace std;
int main() {
	string str;
	while (cin >> str) {
		for (int i = 0; i < str.size(); i++) cout << (str[i] == '1' ? '0' : '1');
		cout << endl; 
	}
	return 0;
}
