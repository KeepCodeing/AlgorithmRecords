#include<iostream>
#include<algorithm>
#define endl '\n'
using namespace std;
const int N = 1e6 + 10;
struct line {
	int l, r;
} a[N];
bool operator<(const line& a,const line& b) {
	return a.r < b.r;

}
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); 
	int n, tot = 1;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].l >> a[i].r;
		if (a[i].l>a[i].r) swap(a[i].l, a[i].r);
	}
	sort(a + 1, a + n + 1);
	int end = a[1].r;
	for (int i = 2; i <= n; i++) {
		if (a[i].l >= end) {
			tot++;
			end = a[i].r;
		}
	}
	cout << tot << endl;
	return 0;
}
