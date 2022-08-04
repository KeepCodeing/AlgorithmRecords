#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	string strs[3];
	cin >> strs[0] >> strs[1] >> strs[2];
	sort(strs, strs + 3);
	cout << strs[0] << endl << strs[1] << endl << strs[2]; 
	return 0;
}
