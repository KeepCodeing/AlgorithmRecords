#include <iostream>
using namespace std;
bool arr[100005];
int main() {
	int l;
	cin >> l;
	arr[0] = arr[1] = true;
	for (int i = 2; i < 100000; i++) {
		if (!arr[i]) {
			for (int j = i * 2; j < 100000; j += i) {
				arr[j] = true;
			}
		}
	} 
	int cnt = 0;
	for (int i = 2; i < 100000; i++) {
		if (!arr[i]) {
			if (l >= i) {
				cnt++;
				l -= i;
				cout << i << endl;	
			} else {
				break;
			}
		}
	}
	cout << cnt;
	return 0;
}
