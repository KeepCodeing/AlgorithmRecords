#include <iostream>
using namespace std;

// 最基本的排序，但是还是要注意，这个题可以用桶排，
// 这就是为什么给了个变量n的原因 

int *bucket;
int main() {
	int n, m, temp;
	// m只是投票数量，不是候选人数量，所以m <= n 
	cin >> n >> m;
	bucket = new int[n + 1]();
	for (int i = 0; i < m; i++) {
		cin >> temp;
		bucket[temp]++;
	}
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j < bucket[i]; j++) {
			cout << i;
			cout << ' ';
		}
	}
	delete[] bucket;
	return 0;
}
