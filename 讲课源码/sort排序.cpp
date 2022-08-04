#include <iostream>
// sort函数被包含在此头文件中
#include <algorithm>
using namespace std;

bool cmp(int a, int b) { return a > b; }

struct Node {
	int x;
	bool operator< (Node n) const {
		return n.x < x;
	}
};

int main() {
	int arr[6] = { 4, 24, 1, 6, 5, 13 };
	Node ns[3];
	for (int i = 0; i < 3; i++) ns[i].x = i;
    // 传入起始和末尾引用，会将这个区间内的数进行排序
	sort(arr, arr + 6);
	for (int i = 0; i < 6; i++) cout << arr[i] << ' ';
	cout << endl;
	
	// 自定义排序规则，降序排序 
	sort(arr, arr + 6, cmp);
    for (int i = 0; i < 6; i++) cout << arr[i] << ' ';
    cout << endl;
    
    // 传入结构体，需要重载排序操作符 
    sort(ns, ns + 3);
    
	return 0;
}
