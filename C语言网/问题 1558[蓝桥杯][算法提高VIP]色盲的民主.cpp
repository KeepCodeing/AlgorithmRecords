#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
map<string, int > m;
vector<string > vec;
int main() {
	int n;
	cin >> n;
	int maxCnt = -1;
	while (n--) {
		string str;
		// 可以包括单词和词组... 
		getline(cin, str);
		m[str]++;
		maxCnt = max(m[str], maxCnt);
	}
	for (map<string, int >::iterator it = m.begin(); it != m.end(); it++) {
		if (it->second == maxCnt) vec.push_back(it->first); 
	} 
	sort(vec.begin(), vec.end());
	int vLen = vec.size();
	for (int i = 0; i < vLen; i++) {
		cout << vec[i];
		if (i != vLen - 1) cout << endl;
	}
	return 0;
}
