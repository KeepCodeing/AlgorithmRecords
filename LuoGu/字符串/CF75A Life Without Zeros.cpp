#include <iostream>
#include <sstream>
using namespace std;

// 大水题，用字符串流可以轻松AC 
// 然而代码写的和屎一样，不多谈！ 

// UKE了ww，不管了w 

typedef long long LL;
int main() {
	string a, b;
	cin >> a >> b;
	LL t1, t2;
	stringstream ss;
	ss << a;
	ss >> t1;
	ss.clear();
	ss << b;
	ss >> t2;
	ss.clear();
	LL zero = t1 + t2;
	string at, bt;
	for (int i = 0; i < a.size(); i++) if (a[i] != '0') {
		at += a[i];
	}
	for (int i = 0; i < b.size(); i++) if (b[i] != '0') {
		bt += b[i];
	}
	LL nzero;
	LL t11, t22;
	ss << at;
	ss >> t11;
	ss.clear();
	ss << bt;
	ss >> t22;
	ss.clear();
	nzero = t11 + t22;
	string szero;
	ss << zero;
	ss >> szero;
	ss.clear();
	string rzero;
	for (int i = 0; i < szero.size(); i++) if (szero[i] != '0') {
		rzero += szero[i];
	} 
	ss << rzero;
	ss >> t1;
	if (t1 == nzero) cout << "YES";
	else cout << "NO";
	// cout << zero << ' ' << nzero; 
	return 0;
} 
