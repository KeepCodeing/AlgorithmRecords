#include <iostream>
#include <vector>
using namespace std;
vector<int > res;
int main() {
	int x, y;
	cin >> x >> y;
	int cnt = 0;
	for (int i = x; i <= y; i++) {
		if ((i % 4 == 0 && i % 100 != 0 )|| (i % 400 == 0)) {
			cnt++;
			res.push_back(i); 
		}
	}
	cout << cnt << endl;
	for (int i = 0; i < res.size(); i++) cout << res[i] << ' ';
	return 0;
}
