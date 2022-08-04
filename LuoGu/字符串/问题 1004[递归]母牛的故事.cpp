#include <iostream>
using namespace std;

// 打表找规律结果打到第一个未知项把值搞错了，不过其实也可以从已知的表来推
// 这只是个fib的变形罢了 

long long nums[60];
int main() {
	nums[1] = 1, nums[2] = 2, nums[3] = 3, nums[4] = 4;
	for (int i = 5; i <= 55; i++) nums[i] = nums[i - 1] + nums[i - 3];
	int n;
	do {
		cin >> n;
		// 没有判断0全WA，本来以为0不会输出的（无能） 
		if (n) cout << nums[n] << endl;
	} while(n);
	return 0;
} 
