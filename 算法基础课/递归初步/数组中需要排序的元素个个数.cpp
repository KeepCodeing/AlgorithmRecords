#include <iostream>
using namespace std;
// ����һ�����飬��{2, 3, 7, 5, 4, 6}������4����Ϊֻ��{7, 5, 4, 6}��Ҫ����
// Ҫ��ʱ�临�Ӷ�ΪO(n)
// ˼·����������鿴��һ������ͼ�������һ�����������������һ�������ϻ������µ�
// ������Ǹ�������������飬�м��Ȼ�������ۣ�����ߵ��Ҳ�������˵���������û��
// ���򣬷���������͵����������Ҳ���Կ���δ���������ڱ��������ͬʱ������ߵ��ֵ
// ����͵��ֵ������¼�����ǵ��±꣬����������ڵ�������Ҫ������� 
const int LEN = 6;
int checkArr(int arr[]) {
	int arrMax, arrMin, maxIndex = 0, minIndex = 0;
	arrMax = arr[0], arrMin = arr[LEN - 1];
	for (int i = 0; i < LEN; i++) {
		if (arr[i] < arrMax) maxIndex = i;
		if (arr[i] > minIndex) minIndex = i;
		if (arr[i] > arrMax) arrMax = arr[i];
		if (arr[i] < arrMin) arrMin = arr[i];
	}
	return maxIndex - minIndex;
}  
int main() {
	int arr[LEN] = {2, 3, 7, 5, 4, 6};
	// 2, 3, 7, 5, 4, 6
	// 2, 3, 4, 5, 6, 7
	cout << checkArr(arr) << endl;
	return 0;
}
