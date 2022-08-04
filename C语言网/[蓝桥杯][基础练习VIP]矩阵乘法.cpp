#include <iostream>
using namespace std;

// 学了线代，有必要做下这个题了（使命感）..
// 矩阵的乘法就是第一行乘上另一个矩阵的1..n个列，每次相乘的和就是第一行，第1..n个位置的元素
// 的值.. 

const int N = 30 + 10, M = 10;
int matrix[N][N], res[N][N], temp[N][N];
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	m -= 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) scanf("%d", &matrix[i][j]), res[i][j] = matrix[i][j];
	}
	while (m--) {
		int tot = 0;
		for (int k = 1; k <= n; k++) {
			for (int i = 1; i <= n; i++) {
				tot = 0;
				for (int j = 1; j <= n; j++) {
					// 表示第1行的j个元素乘上第j行的i个元素..然后把1换成k，
					// 就可得到矩阵了... 
					tot += matrix[k][j] * res[j][i];
				}
				temp[k][i] = tot;
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) res[i][j] = temp[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) printf("%d ", res[i][j]);
		puts("");
	}
	return 0;
}
