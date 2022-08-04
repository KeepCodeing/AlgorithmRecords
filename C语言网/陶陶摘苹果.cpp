#include <iostream>
#include <cstdio>
const int N = 20;
int nums[N];
int main() {
	int h, cnt = 0;
	for (int i = 1; i <= 10; i++) scanf("%d", &nums[i]);
	scanf("%d", &h);
	for (int i = 1; i <= 10; i++) {
		if (nums[i] <= h + 30) cnt++;
	}
	printf("%d", cnt);
	return 0;
}
