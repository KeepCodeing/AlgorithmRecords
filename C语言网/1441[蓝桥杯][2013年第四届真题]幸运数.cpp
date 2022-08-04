#include <iostream>
using namespace std;
int *nums;
int main() {
	int m, n;
	cin >> m >> n;
	nums = new int[n + 3];
	for (int i = 1; i < n; i++) nums[i] = i;
	delete[] nums;
	return 0;
}
