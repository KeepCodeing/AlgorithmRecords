#include <iostream>
using namespace std;
// ʹ��һ������洢�Ѿ������˵Ľ�� 
long long visited[1001];
long long fib(int n) {
	if (n <= 2) return 1;
	// �ڲ����·�֧֮ǰ�����ж���������ǲ��Ǳ������
	// �ˣ�����Ѿ�������ˣ�ֱ�ӷ��ؽ�����У�������
	// �ܱ��ظ��ķ�֧�Ĳ��� 
	if (visited[n]) return visited[n];
	// �洢��������Ȼ���䷵�ػ�ȥ���������·����DFS
	// ��ͬ������Ŀ�ľ��Ǵ�Ž���������ڻ��� 
	visited[n] = fib(n - 1) + fib(n - 2);
	return visited[n];
}
int main() {
	// �Ľ���ĳ���������ٶ�������ʮ�������ű� 
	cout << fib(1000);
	return 0;
}
