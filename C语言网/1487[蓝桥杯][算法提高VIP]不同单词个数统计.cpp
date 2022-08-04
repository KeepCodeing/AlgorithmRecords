#include <iostream>
#include <set>
using namespace std;

// 打算用map做的，但感觉没必要，只要给个去重功能就行 
// 至于空格直接while cin就行，用getline可能还会有奇妙的换行符 

set<string > st;
int main() {
	string str;
	while (cin >> str) {
		if (!st.count(str)) st.insert(str); 
	}
	cout << st.size();
	return 0;
}
