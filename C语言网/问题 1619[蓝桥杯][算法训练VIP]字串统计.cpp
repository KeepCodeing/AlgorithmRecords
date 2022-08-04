#include <iostream>
#include <map>
using namespace std;
map<string, int > m;
int main() {
	int l;
	string str;
	cin >> l >> str;
	string res;
	int maxCnt = -1;
	string temp;
	int sLen = str.size();
	for (int j = l; j < sLen; j++) {
		for (int i = 0 ; i < sLen; i++) {
			temp = str.substr(i, j);
			if (temp.size() < j) break;
			m[temp]++;
			if (m[temp] > maxCnt) {
				maxCnt = m[temp];
				res = temp;
			}
		}
	}
	cout << res;
	return 0;
}
