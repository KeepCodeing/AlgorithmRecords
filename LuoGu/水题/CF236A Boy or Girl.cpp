#include <iostream>
#include <set>
using namespace std;

// ˮ��ڢᵯ... 

set<char > s;
int main() {
	char c;
	while (cin >> c) s.insert(c); 
	cout << (s.size() % 2 ? "IGNORE HIM!" : "CHAT WITH HER!");
	return 0;
}
