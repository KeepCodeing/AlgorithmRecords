#include <iostream>
#include <set>
using namespace std;

// ������3��set��� 

set<int > s;
int main() {
	int temp;
	for (int i = 0; i < 10; i++) {
		cin >> temp;
		s.insert(temp % 42); 
	}
	cout << s.size();
	return 0;
}
