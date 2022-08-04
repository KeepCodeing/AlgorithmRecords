#include <iostream>
#include <map>
using namespace std;
struct ele {
	int x, y;
	ele(int x, int y) : x(x), y(y) {};
	bool operator<(const ele& e) const {
		if (x != e.x) return x < e.x;
		return y < e.y; 
	}
};
map<ele, int > box;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, q;
	cin >> n >> q;
	while (q--) {
		int x, y, w, op;
		cin >> op;
		if (op == 1) {
			cin >> x >> y >> w;
			box[ele(x, y)] = w;
		} else {
			cin >> x >> y;
			cout << box[ele(x, y)] << endl;
		}
	}
	return 0;
}
