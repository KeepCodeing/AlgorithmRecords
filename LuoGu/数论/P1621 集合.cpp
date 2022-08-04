#include <iostream>
#include <set>
#include <map>
using namespace std;
map<int, set<int > > zs;
struct unionFind {
	int bin[100010];
	unionFind () {
		for (int i = 1; i <= 100010; i++) bin[i] = i;
	}
	int anc(int x) {
		if (x == bin[x]) return x;
		bin[x] = anc(bin[x]);
		return bin[x];
	}
	void uni(int x, int y) {
		bin[anc(x)] = bin[anc(y)];
	}
	bool ask(int x, int y) {
		return anc(x) == anc(y);
	}
};
int main() {
	int a, b, p;
	cin >> a >> b >> p;
	for (int i = a; i <= b; i++) {
		int t = i;
		for (int j = 2; j <= t / j; j++) {
			while (!(t % j)) {
				if (j >= p) zs[j].insert(i);
				t /= j;
			}
		}
		if (t > 1) zs[t].insert(i);
	}
	cout << zs.size();
//	for (map<int, set<int > >::iterator it = zs.begin(); it != zs.end(); it++) {
//		cout << it->first << ' ';
//		set<int > it2 = it->second;
//		//set<int > temp;
//		for (set<int >::iterator tt = it2.begin(); tt != it2.end(); tt++) {
//			//cout << *tt << ' ';
//			//temp.insert(*tt); 
//		}
//		//cout << temp.size() << endl;;
//		cout << endl;
//	}
	return 0;
}
