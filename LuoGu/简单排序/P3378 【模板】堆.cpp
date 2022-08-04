#include <iostream>
#include <queue>
using namespace std;

// 优先队列，不多谈！ 
// 谔谔，TLE一个点，开O2过的 

priority_queue<int > que;
int main() {
	int n, code, x;
	cin >> n;
	while(n--) {
		cin >> code;
		if (code == 1) {
			cin >> x;
			// 转成小根堆，然后还原 
			que.push(-x); 
		} else if (code == 2) {
			cout << -que.top() << endl;
		} else {
			que.pop();
		}
	}
	return 0;
}
