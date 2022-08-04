#include <iostream>
using namespace std;
const int N = 100010;
// 感觉其并不习惯于写完了再调个init函数，所以直接全局遍历
// 赋值算了 
int head = -1, idx = 0;
int e[N], nx[N];
//void initList() {
//	head = -1, idx = 0;
//}
void add_to_head(int val) {
	e[idx] = val;
	nx[idx] = head;
	head = idx;
	idx++;
}
void add(int pos, int val) {
	e[idx] = val;
	nx[idx] = nx[pos];
	nx[pos] = idx;
	idx++;
}
void remove(int pos) {
	nx[pos] = nx[nx[pos]];
}
int main() {
	// initList();
	int n;
	cin >> n;
	char code;
	int k, x;
	while (n--) {
		cin >> code >> x;
		if (code == 'H') {
			add_to_head(x);
		} else if (code == 'D') {
			if (!x) head = nx[head];
			else remove(x - 1);
		} else {
			cin >> k;
			add(x - 1, k);
		}
	}
	while(head != -1) {
		cout << e[head] << ' ';
		head = nx[head];
	}
	return 0;
}
