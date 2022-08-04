#include <iostream>
#include <stack>

using namespace std;

int main() {
	stack<int > s;
	for (int i = 1; i <= 10; i++) s.push(i);
	while (s.size()) {
		// top方法只是用来取出栈顶元素，不会弹出栈顶元素 
		cout << s.top() << endl;
		s.pop();
	}
	return 0;
}
