#include <iostream>
using namespace std;
int box[25][25][25];
int main() {
	int x, y, z, n;
	cin >> x >> y >> z >> n;
	for (int i = 1; i <= x; i++) {
		for (int j = 1; j <= y; j++) {
			for (int k = 1; k <= z; k++) box[i][j][k] = 1;
		}
	}
	int x1, x2, y1, y2, z1, z2;
	while(n--) {
		cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
		for (int i = x1; i <= x2; i++) {
			for (int j = y1; j <= y2; j++) {
				for(int k = z1; k <= z2; k++) box[i][j][k] = 0;
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= x; i++) {
		for (int j = 1; j <= y; j++) {
			for (int k = 1; k <= z; k++) ans += box[i][j][k];
		}
	}
	cout << ans;
	return 0;
}
