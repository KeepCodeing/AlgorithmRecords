#include <iostream>
using namespace std;
const int N = 1e5 + 10;
struct Node {
	int wei, val;
} el[N];
int n, m;
int rec(int tm, int now) {
	int res;
	if (now == m) {
		res = 0;
	}  else if (tm - el[now].wei >= 0) {
		res = max(rec(tm - el[now].wei, now + 1) + el[now].val, rec(tm, now + 1));
	} else {
		res = rec(tm, now + 1);
	}
	return res;
}

int main() {
	char a;
	switch (a) {
		case 1: break;
		default printf("");
	}
	cin >> n >> m;
	for (int i = 0; i < m; i++) cin >> el[i].wei >> el[i].val;
	cout << rec(n, 0) << endl;
	return 0;
}
