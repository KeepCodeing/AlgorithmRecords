#include <iostream>
using namespace std;
const int N = 100010;

// head表示头结点的下标
// e表示节点i的值
// ne表示节点i的next指针是多少
// idx存储当前已经用到了那个点 
int head, e[N], ne[N], idx;

// 初始化 
void initList() {
	head = -1, idx = 0;
}

// 将x插入到头结点 
void add_to_head(int x) {
	// 首先把这个点创建出来 
	e[idx] = x;
	// 然后把这个节点的下一个节点（向左指）指向head 
	ne[idx] = head;
	// 这个节点就成为了新的头结点，后续执行头插入操作就会从
	// 这个节点开始插入 
	head = idx;
	// 使用的节点数自增 
	idx++;
	// 2 -> 1 -> head... 
}
// 将x插入到下标为k的节点后 
void add(int k, int x) {
	// 同样先创建出这个节点 
	e[idx] = x;
	// 然后将这个节点指向k后面的节点 
	ne[idx] = ne[k];
	// 再将k指向这个节点 
	ne[k] = idx;
	idx++;
}
// 将下标为k的节点后面的一个节点删除 
void remove(int k) {
	// 删除就是让节点k跳过k+1个节点直接指向k+2个节点
	// 这里的操作就是取出k指向的下一个节点的下标，然后
	// 让k指向这个节点指向的节点，即跳过k+1个节点 
	ne[k] = ne[ne[k]];
}
int main() {
	initList();
	int n;
	cin >> n;
	char code;
	int x, y;
	while (n--) {
		cin >> code;
		if (code == 'H') {
			cin >> x;
			add_to_head(x);
		} else if (code == 'D') {
			cin >> x;
			// 删除头结点就是让头结点指向下一个节点 
			if (!x) head = ne[head];
			else
			// 节点从0开始，所以这里要-1 
			remove(x - 1);
		} else {
			cin >> x >> y;
			add(x - 1, y);
		}
	}
	while (head != -1) {
		cout << e[head] << ' ';
		head = ne[head];
	}
	return 0;
}
/*
输入样例：

10
H 9
I 1 1
D 1
D 0
H 6
I 3 6
I 4 5
I 4 5
I 3 4
D 6

输出样例：

6 4 6 5
*/
