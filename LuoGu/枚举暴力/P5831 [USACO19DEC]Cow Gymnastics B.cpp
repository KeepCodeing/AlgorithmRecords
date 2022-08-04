#include <iostream>
#include <map>
using namespace std;
int n, k;
int cows[15][25];

struct data {
	int x, y;
	data(int x, int y) : x(x), y(y) {};
	bool operator<(const data& d) const {
		if (x != d.x) return x > d.x;
		return y > d.y;
	}
};

map<data, int > mp;

int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			cin >> cows[i][j];
		}
	}
	// 这里之前写成了n，还在疑惑哪里错了 
	for (int t = 1; t <= n; t++) {
		for (int i = t; i <= n; i++) {
			for (int j = i; j <= k - 1; j++) {
				mp[(data){cows[i][j], cows[i][j + 1]}]++;
			}
		}
	
	}
	
	for (map<data, int >::iterator it = mp.begin(); it != mp.end(); it++) {
		cout << it->first.x << ' ' << it->first.y << ' ' << it->second << endl;
	}
	return 0;
}
