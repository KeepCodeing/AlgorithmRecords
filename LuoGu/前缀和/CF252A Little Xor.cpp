#include <iostream>
using namespace std;
long nums[110];
int arr[110];
int main() {
	int n;
	cin >> n;
	nums[0] = 0;
	for (int i =1; i <= n; i++) cin >> arr[i];
	int x = 0;
	int t;
	t = 0;
	for (int i = 1; i <= n; i++) {
		x ^= arr[i]; 
		if (arr[i] > t) {
			nums[i] = nums[i - 1] + x;	
		}
		t = arr[i];
	}
	for (int i = 1; i <= n; i++) {
		cout << nums[i] << endl;
	}
	return 0;
}
