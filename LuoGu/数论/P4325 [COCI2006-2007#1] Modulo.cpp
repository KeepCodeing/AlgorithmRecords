#include <iostream>
#include <set>
using namespace std;

// 热身题3：set解决 

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
