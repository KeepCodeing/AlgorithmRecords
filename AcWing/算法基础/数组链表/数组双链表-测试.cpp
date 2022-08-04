#include <iostream>
using namespace std;
const int N = 100010;
int e[N], l[N], r[N];
int idx;

void add(int k, int x) {
	// 这里的连接操作一定要严格按照先左后右的顺序来 
	e[idx] = x;
	l[idx] = k;
	r[idx] = r[k];
	l[r[k]] = idx;
	r[k] = idx;
	idx++;
}

void remove(int k) {
	l[r[k]] = l[k];
	r[l[k]] = r[k];
}
int main() {
	r[0] = 1, l[1] = 0;
	// 注意这里下标从2开始，因为头尾各占了一个位置 
	idx = 2;
	int n;
	cin >> n;
	int x, y;
	while (n--) {
		string code;
		cin >> code >> x;
		if (code == "L") {
			// 在最左端插入，也就意味是是从头部插入
			add(0, x); 
		} else if (code == "R") {
			// 在最右边插入只需要传入最左端的元素（头结点）即可，因为
			// 头结点连接了尾结点（最右端的元素） 
			add(l[1], x);
		} else if (code == "D") {
			// 下标从2开始，所以还要+1 
			remove(x + 1);
		} else if (code == "IL") {
			cin >> y;
			// 左侧插入先得找到这个点左边的元素，然后再通过左边的元素的右插入
			// 达到给这个元素左插入的效果（因为add默认是右插入） 
			add(l[x + 1], y);
		} else {
			cin >> y;
			// 右侧插入直接传入插入位置即可，和单链表一样 
			add(x + 1, y);
		}
	}
	int head = r[0];
	// 注意这里设置的终止条件，是当right指向了1为止 
	while (head != 1) {
		cout << e[head] << ' ';
		head = r[head];
	}
	return 0;
}

/*
输入样例：
10
R 7
D 1
L 3
IL 2 10
D 3
IL 2 7
L 8
R 9
IL 4 7
IR 2 2
输出样例：
8 7 7 3 2 9
*/
