#include <iostream>
#include <map>
using namespace std;

// 主要是怎么把字符串映射成下标，大概可以用map来

struct unionFind {
	int bin[20010];
	unionFind() {
		for (int i = 1; i <= 20010; i++) bin[i] = i;
	}
	int anc(int x) {
		if (x == bin[x]) return x;
		bin[x] = anc(bin[x]);
		return bin[x];
	}
	void uni(int x, int y) {
		bin[anc(x)] = anc(y);
	}
	bool ask(int x, int y) {
		return anc(x) == anc(y);
	}
}; 
unionFind u;
map<string, int > student;
int n, m;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		string name;
		cin >> name;
		student[name] = i;
	}
	while (m--) {
		string x, y;
		cin >> x >> y; 
		u.uni(student[x], student[y]); 
	}
	int k;
	cin >> k;
	while (k--) {
		string x, y;
		cin >> x >> y;
		if (u.ask(student[x], student[y])) cout << "Yes.";
		else cout << "No.";
		cout << endl;
	}
	return 0;
}
