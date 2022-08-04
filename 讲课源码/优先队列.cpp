#include <iostream>
#include <queue>
using namespace std;
int main() {
	priority_queue<int > que;
	for (int i = 1; i <= 10; i++) que.push(i);
	
	// 优先队列取出队头使用的是top()方法，而不是front()方法 
	while (que.size()) cout << que.top() << endl, que.pop();
	
	// 前面提到过优先队列可以根据“权值”进行插队，实际上就是制定
	// 排序规则，默认的排序规则是降序
	
	cout << endl;
	
	// 升序排序（权重越小越靠前）优先队列声明时需要如下额外的配置 
	priority_queue<int, vector<int >, greater<int > > que2;
	for (int i = 1; i <= 10; i++) que2.push(i);
	while (que2.size()) cout << que2.top() << endl, que2.pop();
	return 0;
}
