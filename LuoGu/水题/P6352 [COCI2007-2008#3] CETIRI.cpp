#include <iostream>
#include <algorithm>
using namespace std;

// ˮ�������...����ˮ�����.. 
// ͷ�ļ���дȫCE�ˣ����Ҹ�����... 

int nums[4];
int main() {
	cin >> nums[0] >> nums[1] >> nums[2];
	sort(nums, nums + 3);
	int d1 = nums[1] - nums[0], d2 = nums[2] - nums[1];
	if (d1 == d2) printf("%d", nums[2] + d2);
	else if (d1 == (2 * d2)) printf("%d", nums[1] - d2);
	else printf("%d", nums[2] - d1);
	return 0;
}
