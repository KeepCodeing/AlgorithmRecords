#include <iostream>
#include <algorithm>
#include <cmath>
#define endl '\n'
#define x first
#define y second
using namespace std;
typedef pair<int, int > PII;
const int N = 200 + 10;
PII books[N];
int f[N][N];

int dfs(int level, int deepth, int k, int cnt, int pre, string path) {
	
	if (f[level][cnt]) return f[level][cnt];
	
	if (!k && !cnt) {
		cout << path << endl;
		return 0;
	}
	
	if (level >= deepth) return 0;
	
	int ta = dfs(level + 1, deepth, k, cnt - 1, books[level].y,  path + (char)(books[level].y + '0') + "->" + (char)(pre + '0') + "===") + abs(books[level].y - pre);
	int tb = dfs(level + 1, deepth, k - 1, cnt, pre, path);
	
	cout << ta << endl;
	cout << tb << endl;
//	f[level][cnt] = min(
//		, 
//		
//	);
	
//	cout << f[level][cnt] << endl;
	
	return f[level][cnt];
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> books[i].x >> books[i].y;
	sort(books, books + n);
	cout << dfs(0, n, k, n - k, books[0].y, "") << endl;
	return 0;
}

/*

#include <iostream>
#include <algorithm>
#include <cmath>
#define endl '\n'
#define x first
#define y second
using namespace std;
typedef pair<int, int > PII;
const int N = 200 + 10;
PII books[N];
int res = 99999;

int dfs(int level, int deepth, int k, int cnt, int pre, int sum, string path) {
	
	if (!k && !cnt) {
		res = min(res, sum);
		return 0;
	}
	
	if (level >= deepth) return 0;
	
	if (pre == -1) pre = books[level].y;
	
	// 第一本书没有前一本书，也就意味着它不参与相减运算，如果我们把它加到相减运算里，就会导致结果
	// 多出来一部分第一本书的宽度 
	dfs(level + 1, deepth, k, cnt - 1, books[level].y, sum + abs(books[level].y - pre), path + (char)(books[level].y + '0') + "->" + (char)(pre + '0') + "===");
	// 不选这本书，那么前一本书不变（仔细想下，对于当前这本不选的书，它的前一本书就是上一步的选了的书，而这本书
	// 就是pre参数） 
	dfs(level + 1, deepth, k - 1, cnt, pre, sum, path);
	
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> books[i].x >> books[i].y;
	sort(books, books + n);
	dfs(0, n, k, n - k, -1, 0, "");
	cout << res << endl;
	return 0;
}
*/

