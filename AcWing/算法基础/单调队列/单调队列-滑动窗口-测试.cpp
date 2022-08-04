#include <iostream>
using namespace std;
const int N = 100010;
int nums[N], que[N];
int main() {
	int n, k;
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> nums[i];
	int hh = 0, tt = -1;
	for (int i = 0; i < n; i++) {
		if (hh <= tt && i - k + 1 > que[hh]) hh++;
		while(hh <= tt && nums[que[tt]] >= nums[i]) tt--;
		que[++tt] = i;
		if (i >= k - 1) cout << nums[que[hh]] << ' ';
	}
	return 0;
}
