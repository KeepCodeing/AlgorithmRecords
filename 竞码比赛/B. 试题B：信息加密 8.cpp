#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string mes;
	string password = "JKLMNOPQRSTUVWXYZABCDEFGHI";
	string t = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	cin >> mes;
	for (int i = 0; i < mes.size(); i++) {
		mes[i] = t[password.find(mes[i])]; 
	}
	cout << mes;
	// ABCDEFGHIJKLMNOPQRSTUVWXYZ
	// JKLMNOPQRSTUVWXYZABCDEFGHI
	// JKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHI
	return 0;
}
