#include <iostream>
#include <map>
using namespace std;
map<long long, int > result;
int main() {
	int n;
	long long temp;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> temp;
		result[temp]++;
	}
	for (map<long long, int >::iterator it = result.begin(); it != result.end(); it++) {
		cout << it->first  << ' ' << it->second << endl;
	}
	return 0;
}
