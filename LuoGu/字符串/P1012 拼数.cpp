#include <iostream>
#include <algorithm>
using namespace std;

// 这个题算是个特殊排序题，主要是对比ASCII码然后排序 

// 提供排序算法 
bool cmp(string a, string b) {
	// 自定义排序函数，这一步非常巧妙，假设a=321，b=32；a+b=32132，b+a=32321这样下
	// 面sort排下来就是32>321避免出现32132>32321的情况
	return a + b > b + a;
}

int main() {
	int n;
	string *arr;
	cin >> n;
	arr = new string[n];
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n, cmp);
	for (int i = 0; i < n; i++) cout << arr[i];
	delete[] arr;
	return 0;
}
