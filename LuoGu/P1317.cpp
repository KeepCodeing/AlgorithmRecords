#include <iostream>
#include <queue>
#include <vector>
using namespace std;
queue<int > q;
int main() {
	int n, temp, s, result = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		q.push(temp);
		if (q.size() == 3) {
			s = q.front();
			q.pop();
			if (s > q.front() && q.front() <= q.back()) result++;
		}
	}
	cout << result;
	return 0;
}
