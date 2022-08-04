#include <iostream>
using namespace std;

const int N = 10;

int main() {
	int arr[N] = {2, 1, 4, 264, 13, 45, 5, 5, 2, 0};
	
	// 注意这个 <= N，是为了对比最后一个元素的 
	for (int i = 1; i <= N; i++) {
		for (int j = i - 1; j >= 0; j--) {
			// 怎么看都觉得这个插入排序是个换皮冒泡排序... 
			// 思路很简单，从右往左，前一项是否大于当前项，如果大于就调换下位置.. 
			if (j > 0 && arr[j - 1] > arr[j]) swap(arr[j - 1], arr[j]);
		}
	}
	
	for (auto el: arr) {
		cout << el << ' ';
	}
	
	return 0;
}
