#include <iostream>
#include <algorithm>
using namespace std;

// м��Ŀ����Ȼ��������Ѷȣ����������˳����Ҳֻ����AC�� 

int nums[4];
int main() {
	for (int i = 0; i < 4; i++) cin >> nums[i];
	sort(nums, nums + 4);
	for (int i = 0; i < 4; i++) {
		cout << nums[i];
		if (i != 3) cout << ' ';
	}
	return 0;
}
