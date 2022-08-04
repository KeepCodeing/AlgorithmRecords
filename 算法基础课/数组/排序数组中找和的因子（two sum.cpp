#include <iostream>
#include <map>
using namespace std;
const int LEN = 10;
// 给出一个数组，如{-8, -4, -3, 0, 2, 4, 5, 8, 9, 10} ,k=10，输出(0,10),(2,8) 
void my_sum(int arr[], int target) {
	map<int, int > numToIndex;
	for (int i = 0; i < LEN; i++) {
		if (numToIndex.count(target - arr[i])) {
			// 这里之前直接输出了arr[target-arr[i]]，这获取的既不是下标，也不是元素
			//  arr[numToIndex[target - arr[i]]]是通过下标获取arr的值， target - arr[i]表示满足元素的值 
			cout << '(' << target - arr[i] << ',' << arr[i] << ')' << endl;
		}
		numToIndex[arr[i]] = i;
	}
}
int main() {
	int arr[] = {-8, -4, -3, 0, 2, 4, 5, 8, 9, 10};
	int target = 10;
	my_sum(arr, target);
	return 0;
}
