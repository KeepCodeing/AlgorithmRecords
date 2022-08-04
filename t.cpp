#include <iostream>
using namespace std;

const int N = 110, M = 1110;

struct Node {
	int w, v;
	Node(int w1, int v1): w(w1), v(v1) {};
	Node() {};
};

Node node[N];

long long f[M];


int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> node[i].w >> node[i].v;
	
	for (int i = 1; i <= n; i++) {
		for (int j = m; j >= node[i].w; j--) {
			f[j] += f[j - node[i].w];
		}
	}
	cout << f[m] << endl;
	return 0;
}
