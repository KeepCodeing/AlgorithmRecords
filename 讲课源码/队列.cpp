#include <iostream>
#include <queue>
using namespace std;

int main() {
	queue<int > que;
	for (int i = 1; i <= 10; i++) que.push(i);
	
	// 队列取出队头元素使用的是front()方法 
	while (que.size()) cout << que.front() << endl, que.pop();
	return 0;
}
