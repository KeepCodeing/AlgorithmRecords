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
	// ���һ����ʣ����Ԫ�أ����������д��>1 
	while (que.size() > 1) {
		int a = que.top();que.pop();
		int b = que.top();que.pop();
		res += a + b;
		que.push(a + b); 
	}
	printf("%d", res);
	return 0;
}
