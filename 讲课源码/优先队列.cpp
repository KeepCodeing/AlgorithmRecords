#include <iostream>
#include <queue>
using namespace std;
int main() {
	priority_queue<int > que;
	for (int i = 1; i <= 10; i++) que.push(i);
	
	// ���ȶ���ȡ����ͷʹ�õ���top()������������front()���� 
	while (que.size()) cout << que.top() << endl, que.pop();
	
	// ǰ���ᵽ�����ȶ��п��Ը��ݡ�Ȩֵ�����в�ӣ�ʵ���Ͼ����ƶ�
	// �������Ĭ�ϵ���������ǽ���
	
	cout << endl;
	
	// ��������Ȩ��ԽСԽ��ǰ�����ȶ�������ʱ��Ҫ���¶�������� 
	priority_queue<int, vector<int >, greater<int > > que2;
	for (int i = 1; i <= 10; i++) que2.push(i);
	while (que2.size()) cout << que2.top() << endl, que2.pop();
	return 0;
}
