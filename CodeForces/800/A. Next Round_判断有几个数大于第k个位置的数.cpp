#include <iostream>
using namespace std;

// 这个题的意思是给n个数，然后给一个位置k，要求统计有几个数大于等于nums[k]，可能有比较聪明的做法
// 因为这个序列是递减的，但是这样或许是画蛇添足，不如直接遍历遍完事... 

const int N = 50 + 10;
int nums[N];
int main() {
	int n, k, cnt = 0;
	cin >> n >> k;
	// 下标从1开始 
	for (int i = 1; i <= n; i++) cin >> nums[i];
	// 注意第二个测试用例，它提示我们分数为0的队伍不能被算入排名，但第k个位置的队伍分数可能为0，
	// 也就是说nums[i] >= nums[k]有效当且仅当nums[i] > 0 
	for (int i = 1; i <= n; i++) cnt += (nums[i] >= nums[k] && nums[i] > 0);
	cout << cnt << endl;
	return 0;
}
