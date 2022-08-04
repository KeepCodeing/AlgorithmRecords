#include <iostream>
#include <set>
#define endl '\n'
using namespace std;
const int N = 300 + 10;

//int nums[N], f[N];
string str;
set<string > st;

void dfs(int i, int deepth, char last, string path) {
	
	if (i > deepth) {
		st.insert(path); 
		cout << path << endl;
		return;
	}
	
	if (str[i] > last) dfs(i + 1, deepth, str[i], path + str[i]);
	dfs(i + 1, deepth, last, path);
	
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> str;
	dfs(0, str.size() - 1, '*', "");
	cout << st.size();
	return 0;
}

//#include <iostream>
//#define endl '\n'
//using namespace std;
//const int N = 300 + 10;
//
//int nums[N];
//
//int dfs(int i, string path, int deepth, int last) {
//	
//	// if (nums[i] <= last) return 0;
//	
//	if (i > deepth) {
//		cout << path << endl;
//		return 0;
//	}
//	
//	// 注意这里的写法：如果像上面那样写算是直接把整个路径都给截断了，也就不存在不选的情况了... 
//	if (nums[i] > last) dfs(i + 1, path + (char)(nums[i] + '0') + " ", deepth, nums[i]);
//	dfs(i + 1, path, deepth, last);
//}
//
//int main() {
//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	int n;
//	cin >> n;
//	for (int i = 1; i <= n; i++) cin >> nums[i];	
//	dfs(1, "", n, -1);
//	return 0;
//}
