#include <iostream>
#include <map>
using namespace std;
const int LEN = 10;
// ����һ�����飬��{-8, -4, -3, 0, 2, 4, 5, 8, 9, 10} ,k=10�����(0,10),(2,8) 
void my_sum(int arr[], int target) {
	map<int, int > numToIndex;
	for (int i = 0; i < LEN; i++) {
		if (numToIndex.count(target - arr[i])) {
			// ����֮ǰֱ�������arr[target-arr[i]]�����ȡ�ļȲ����±꣬Ҳ����Ԫ��
			//  arr[numToIndex[target - arr[i]]]��ͨ���±��ȡarr��ֵ�� target - arr[i]��ʾ����Ԫ�ص�ֵ 
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
