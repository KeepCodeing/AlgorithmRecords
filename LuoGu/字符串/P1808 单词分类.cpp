#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

// ���Խ�������򵥵ĶԱ��ַ��������� 
// ��Ҫ���������set 

set<string > res;
int main() {
	int n;
	cin >> n;
	string temp;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		sort(temp.begin(), temp.end());
		res.insert(temp); 
	}
	cout << res.size();
	return 0;
}
