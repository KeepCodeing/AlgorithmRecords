#include <iostream>
#include <vector>
using namespace std;
vector<string > vec;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	while (n--) {
		string temp;
		char c;
		for (int i = 0; i < 6; i++) cin >> c, c = (char)t - '0', cout <<c, temp += c;
		cout << temp;
	}  
	return 0;
}
