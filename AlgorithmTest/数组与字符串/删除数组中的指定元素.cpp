#include <iostream>
#include <vector>
using namespace std;
// 给出一个数组，如[1, 2, 3 ,4, 5],给出一个元素值，要求去除数组中的该元素并
// 返回新数组的长度 
int removeElement(vector<int > arr, int ele) {
	for (vector<int >::iterator it = arr.begin(); it != arr.end(); it++) {
		if (*it == ele) {
			// 去除该元素的同时，数组长度也会变化，所以下面还要对其进行自减操作
			// 防止越界 
			it = arr.erase(it);
			--it;
		}
	}
	return arr.size();
} 
int main() {
	return 0;
}
