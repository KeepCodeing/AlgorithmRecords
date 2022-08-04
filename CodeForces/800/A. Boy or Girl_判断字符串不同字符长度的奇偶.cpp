#include <iostream>
#include <set>
using namespace std;

// 奇数为male，否则为female... 

set<char > st;
int main() {
	char c;
	while (cin >> c) st.insert(c);
	int res = st.size();
	if (!(res % 2)) cout << "CHAT WITH HER!" << endl;
	else cout << "IGNORE HIM!" << endl;
	return 0;
}
