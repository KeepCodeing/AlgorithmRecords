#include <iostream>
using namespace std;
string *arr;
int main() {
	int n;
	cin >> n;
	// �ӣ�����̫����
	arr = new string[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	} 
	for (int i = 0; i < n; i++) {
		string temp = arr[i];
		cout << (((temp[temp.size() - 1] - '0') % 2) ? "odd" : "even");
		if (i != n - 1) cout << endl;
	}
	delete[] arr;
	return 0;
}
