#include <iostream>
#include <map>
using namespace std;

// ˯ǰСˮ��...��mapӳ����� 

map<string, int > mp;
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);   
	string str;
	cin >> str;
	string temp;
	for (int i = 0; i <= 9; i++) cin >> temp, mp[temp] = i;
	int sLen = str.size();
	for (int i = 0; i < sLen; i += 10) cout << mp[str.substr(i, 10)];
	return 0;
}
