#include <iostream>
#include <queue>
using namespace std;

int main() {
	queue<int > que;
	for (int i = 1; i <= 10; i++) que.push(i);
	
	// ����ȡ����ͷԪ��ʹ�õ���front()���� 
	while (que.size()) cout << que.front() << endl, que.pop();
	return 0;
}
