#include <iostream>
using namespace std;

// 突然发现其连二分板子都不会w，学了线段树之类的来补补... 

const int N = 1e5 + 10;
int nums[N];
void ksm() {
	int p, q, m;
	while (q) {
		if (q & 1) res = res * 1ll * p % m;
		q >>= 1;
		p *= p;
	}
}
for (int i = 2; i <= x / i; i++) {
	while (!(x % i)) {
		x /= i;
		
	}
}
int main() {
	int left, right, target, mid;
	while (left <= right) {
		// 取数组中间数，然后划分两个区间，如果要找的数在左区间（即nums[mid] > target），就将右区间缩小到mid - 1的位置
		// 注意不能和mid区间重叠，反正则将左区间的位置扩大到mid + 1的位置... 
		mid = (left + right) >> 1;
		if (nums[mid] == target) return mid;
		if (nums[mid] > target) right = mid - 1;
		else left = mid + 1;
	}
	return 0;
}
