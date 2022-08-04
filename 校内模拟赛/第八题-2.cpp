#include <iostream>
using namespace std;
int getnum(int n, int m, int x, int y) {
	int len = min(min(x, n - 1 - x), min(y, m - 1 - y));
	int d = x + y - len * 2;
	int st = 2 * len * (n + m - 2 * len) + 1;
	if(x == len || y == m - 1 - len || (m < n && len * 2 + 1 == m)) return st + d;
	return st + (n + m - 4 * len - 2) * 2 - d;
}
int main() {
	int n, m;
	cin >> n >> m; 
	int x, y;
	cin >> x >> y;
	cout << getnum(n, m, x - 1, y - 1);
	return 0;
}
/*
11 1
0
11 2
1
11 3
234
11 4
9231
11 5
9228
11 6
9371
11 7
9298
11 8
5612
11 9
6534
11 10
2687
12 1
0
12 2
1
12 3
378
12 4
594
12 5
3698
12 6
992
12 7
6261
12 8
9296
12 9
6685
12 10
2966
12 11
6402
13 1
0
13 2
1
13 3
611
13 4
6036
13 5
6729
13 6
1321
13 7
7778
13 8
9488
13 9
3614
13 10
6041
*/
