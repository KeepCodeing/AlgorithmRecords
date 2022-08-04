#include <iostream>
#include <queue>
#include <cstdio>
using namespace std;
priority_queue<int, vector<int >, greater<int > > que;
int main() {
	int n, t, res = 0;
	scanf("%d", &n);
	while (n--) {
		scanf("%d", &t);
		que.push(t); 
	}
	// 最后一步会剩连个元素，所以这里得写成>1 
	while (que.size() > 1) {
		int a = que.top();que.pop();
		int b = que.top();que.pop();
		res += a + b;
		que.push(a + b); 
	}
	printf("%d", res);
	return 0;
}
