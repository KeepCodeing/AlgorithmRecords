#include <iostream>
using namespace std;
int *arr;
bool *choose;
// 子集问题：给出一个集合，要求输出其全部子集

// 分析：递归法可以想象成二叉树，可选择的状态选项只有2个，
// 有这个元素和没有这个元素，先一条道走到头，然后回溯一步，再走到头...也就是回溯法。
// 可以理解为不断的压栈出栈的过程 
void printZiji(int len) {
	for (int i = 0; i < len; i++) {
		if (choose[i]) {
			cout << arr[i] << ' ';
		}
	}
	cout << endl;
}
void ziji(int level, int len) {
	if (level >= len) {
		printZiji(len);
		return;
	}
	choose[level] = true;
	ziji(level + 1, len);
	choose[level] = false;
	ziji(level + 1, len);
}
int main() {
	int n;
	cin >> n;
	arr = new int[n]();
	choose = new bool[n];
	for (int i = 0; i < n; i++) arr[i] = i + 1;
	ziji(0, n);
	delete[] choose;
	delete[] arr;
	return 0;
}
