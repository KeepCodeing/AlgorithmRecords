#include <iostream>
#include <sstream>
using namespace std;
int main() {
	string str, temp;
	while (getline(cin, str)) {
		stringstream ss;
		ss << str;
		while (ss >> temp) cout << temp;
		cout << endl;
	}
	return 0;
}
