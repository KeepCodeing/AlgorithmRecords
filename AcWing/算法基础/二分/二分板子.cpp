#include <iostream>
using namespace std;

// ͻȻ�����������ְ��Ӷ�����w��ѧ���߶���֮���������... 

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
		// ȡ�����м�����Ȼ�󻮷��������䣬���Ҫ�ҵ����������䣨��nums[mid] > target�����ͽ���������С��mid - 1��λ��
		// ע�ⲻ�ܺ�mid�����ص����������������λ������mid + 1��λ��... 
		mid = (left + right) >> 1;
		if (nums[mid] == target) return mid;
		if (nums[mid] > target) right = mid - 1;
		else left = mid + 1;
	}
	return 0;
}
