#include <iostream>
using namespace std;

const int N = 310;

int graph[N][N];

int main() {
	int n, m;
	cin >> n >> m;
	
	int x; 
	for (int i = 1; i <= n; i++) {
	    for (int j = 1; j <= n; j++) {
	        cin >> x;
	        graph[i][j] = x;
	    }
	}	
	return 0;
}
