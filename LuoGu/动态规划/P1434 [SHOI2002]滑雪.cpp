#include <iostream>
#include <cstring>
#define endl '\n'
using namespace std;

const int N = 300 + 10;
int mp[N][N], f[N][N];
bool vis[N][N];
int r, c;
int mv[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

// 这个题思路比较裸，就是普通的走迷宫类型问题，但是也有几点要注意：首先我们可以用dfs*4的方式写，这样看起来比较好懂，但是
// 这样写也有些缺陷，首先对于当前点是否大于下一个点是要对四个方向单独进行的，这样就导致我们的代码变得更加难懂，而且这样
// 写还要判断下个点会不会出界之类的。
// 另外关于vis的使用，在这个题里是不需要的，原因是我们已经有一个f数组标记了。
// 还有就是为什么这个题没有和上一个五倍经验日那个题一样的level维度，我们想一下可以发现五倍经验日那个题它的体力值x是很可能
// 不唯一的，假如有这种情况，我们体力值不够打过任何人，那么根据题目的意思，我们从头到尾体力值都不会发生改变，这就导致f[x]的唯
// 一性无法判断，我们不知道当前这个x是经过哪一个选择得到的，所以要加个level维度保证选择唯一。而这个题可以发现x，y本身就是
// 地图里唯一的一个点，所以可以不用加level维度。 
// 最后我们要对所有点进行搜索，而不是只从最高点开始搜索，为什么会这样呢，一种假设是最高点可能有多个，那么我们就无法确定从
// 那个最高点出发能滑最远了，因为我们永远只会从最后一个最高点出发.... 

int dfs(int x, int y) {
	
	if (f[x][y]) return f[x][y];
	
	for (int i = 0; i < 4; i++) {
		int nx = x + mv[i][0], ny = y + mv[i][1];
		if (nx >= r || nx < 0 || ny >= c || ny < 0) continue;
		if (mp[x][y] <= mp[nx][ny]) continue;
		f[x][y] = max(f[x][y], dfs(nx, ny) + 1);
	}
	
	return f[x][y]; 	
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int ans = 0;
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> mp[i][j];
		}
	}
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			ans = max(ans, dfs(i, j) + 1);
		}
	}
	cout << ans << endl;
	return 0;
}
