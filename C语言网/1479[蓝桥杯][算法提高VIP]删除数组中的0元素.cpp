//#include <iostream>
//#include <list>
//using namespace std;
//
//// ȫ��ɾ���������������� 
//
//// Ҫ��д��������ֻ�������� 
//int CompactIntegers(list<int >& nums, int cnt) {
//	for (list<int >::iterator it = nums.begin(); it != nums.end(); it++) {
//		// ɾ��0 
//		if (!*it) nums.erase(it); 
//	}
//	return nums.size();
//}
//
//int main() {
//	int n;
//	int t;
//	list<int > nums;
//	cin >> n;
//	for (int i = 0; i < n; i++) cin >> t, nums.push_back(t);
//	int len = CompactIntegers(nums, n);
//	list<int >::iterator e = --nums.end();
//	for (list<int >::iterator it = nums.begin(); it != nums.end(); it++) {
//		cout << *it;
//		if (it != (e)) cout << ' ';
//	}
//	cout << endl << len;
//	return 0;
//}

// ׹�٣����գ�

#include <iostream>
#include <vector>
using namespace std;
vector<int > vec;
int main() {
	int n;
	cin >> n;
	int t;
	for (int i = 0; i < n; i++) {
		cin >> t;
		if (t) vec.push_back(t); 
	}
	int len = vec.size();
	for (int i = 0; i < len; i++) {
		cout << vec[i];
		if (i != len - 1) cout << ' ';
	}
	cout << endl << len;
	return 0;
}
