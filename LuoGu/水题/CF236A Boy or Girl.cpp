#include <iostream>
#include <set>
using namespace std;

// Ë®ÌâµÚ¢áµ¯... 

set<char > s;
int main() {
	char c;
	while (cin >> c) s.insert(c); 
	cout << (s.size() % 2 ? "IGNORE HIM!" : "CHAT WITH HER!");
	return 0;
}
