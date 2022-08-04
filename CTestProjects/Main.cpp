#include <iostream>
using namespace std;
// 使用一个数组存储已经生成了的结果 
long long visited[1001];
long long fib(int n) {
	if (n <= 2) return 1;
	// 在产生新分支之前，先判断这个问题是不是被解决过
	// 了，如果已经被解决了，直接返回结果就行，这样就
	// 能避重复的分支的产生 
	if (visited[n]) return visited[n];
	// 存储问题结果，然后将其返回回去，和求最短路径的DFS
	// 不同，它的目的就是存放结果，不存在回退 
	visited[n] = fib(n - 1) + fib(n - 2);
	return visited[n];
}
int main() {
	// 改进后的程序的运行速度提升了十倍甚至九倍 
	cout << fib(1000);
	return 0;
}
