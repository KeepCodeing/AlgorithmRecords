#include <iostream>
using namespace std;

// 数据范围小，暴力就行 

// 不过这三层循环还是很容易搞混的，果然还是打了之后输出下看下罢...
// 我谔谔，之前写的i + 1, j + 1的循环似乎是可以保证i，j，k不同，但是
// WA了，蒙古，不过写成i == j || i == k || j == k确实更加容易理解，还有
// 就是题目要求的是ai = aj + ak，而不是ak =...，不看题者的末路 

const int N = 110;
int nums[N];
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> nums[i];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				if (i == j || i == k || j == k) continue;
				if (nums[i] == nums[j] + nums[k]) {
					cout << i << ' ' << j << ' ' << k << endl;
					return 0;
				}
				// cout << nums[i] << ' ' << nums[j]  << ' ' << nums[k] << endl;
			}
		}
	}
	cout << -1 << endl;
	return 0;
} 
