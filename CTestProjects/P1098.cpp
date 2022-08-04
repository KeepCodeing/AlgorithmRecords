#include <bits/stdc++.h>
using namespace std;
vector<int > indexs;
int main() {
	int p1, p2, p3;
	cin >> p1 >> p2 >> p3;
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '-') {
			indexs.push_back(i);
		}
	}
	
} 
