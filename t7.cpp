#include <iostream>
#include <set>
#define endl '\n'
using namespace std;

const int N = 100 * 2+ 10;
int nums[N];
set<int > st;

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> nums[i], nums[i + n] = -nums[i];
	n <<= 1;
	for (int i = 0; i < (1 << n); i++) {
		int temp = 0;
		for (int j = 0; j < n; j++) {
			// 将子集加起来
			// 然后统计不同和 
			if ((i >> j) & 1) temp += nums[j];
		}
		if (temp > 0) st.insert(temp);
	}
	cout << st.size();
	return 0;
}
