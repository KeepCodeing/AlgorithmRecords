#include <iostream>
#include <algorithm>
using namespace std;

// ���Բ���תֱ��ͷβ�Աȣ������о������鷳��... 

int main() {
	string a, b;
	cin >> a >> b;
	int left = 0, right = b.size() - 1;
	while (left < right) swap(b[left++], b[right--]);
	if (a == b) cout << "YES";
	else cout << "NO";
	cout << endl;
	return 0;
}
