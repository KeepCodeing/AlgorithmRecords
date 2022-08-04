#include <iostream>
using namespace std;
int nums[1010];
int bucket[10010];
int main() {
	int n;
	cin >> n;
	fill(bucket, bucket + 1010, 0);
	for (int i = 1; i <= n; i++) cin >> nums[i];
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			for (int k = j + 1; k <= n; k++) {
				if (nums[i] < nums[j] && nums[j] < nums[k]) {
					if (bucket[j] != 0) break;
					bucket[j]++;
				}
			}
		}
	}
	int res = 0;
	for (int i = 1; i <= 10010; i++) {
		res += bucket[i];
	}
	cout << res;
	return 0;
}
