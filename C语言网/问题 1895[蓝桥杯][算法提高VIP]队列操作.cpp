#include <iostream>
#include <queue>
using namespace std;
queue<int > que;
int main() {
	int n;
	cin >> n;
	while (n--) {
		int op;
		cin >> op;
		if (op == 1) {
			int x;
			cin >> x;
			que.push(x); 
		} else if (op == 2) {
			if (que.empty()) {
				cout << "no";
				return 0;
			}
			cout << que.front() << endl;
			que.pop();
		} else {
			cout << que.size() << endl;
		} 
	}
	return 0;
} 
