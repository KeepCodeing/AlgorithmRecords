#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

// ͻȻ��������map��value����ķ����������ܲ��ܹ� 
// д�˻ᷢ��׹���ˣ���Ϊ����̶�ĳ���ṹ��

map<string, int > m;
vector<string > res;
void readstr(string& str) {
	char c;
	while ((c = getchar()) != '\n') str += c;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	// getline()�������س������ˣ����ԵļӸ�getchar���� 
	int maxCnt = -1;
	while (n--) {
		string str;
		// ��Ŀ˵�����д��飬Ҳ�����ÿո������һ���ַ���... 
		readstr(str);
		// cout << endl << str << endl;
		m[str]++;
		maxCnt = max(maxCnt, m[str]);
	}
	for (map<string, int >::iterator it = m.begin(); it != m.end(); it++) {
		cout << it->first << ' ' << it->second << endl;
		if (it->second == maxCnt) res.push_back(it->first); 
	}
	sort(res.begin(), res.end());
	int rLen = res.size();
	cout << endl;
	for (int i = 0; i < rLen; i++) {
		cout << res[i];
		if (i != rLen - 1) cout << endl;
	}
	return 0;
}
/*
5 
red 
blue 
black 
black 
blue
*/
