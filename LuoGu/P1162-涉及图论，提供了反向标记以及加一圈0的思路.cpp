#include <iostream>
using namespace std;
// 这一题乍一看是要用漫水填充法，但实际上用这个方法需要判断边界，
// 所以不妨反过来想想，被边界围住的要染色，那么把边界外的元素染色
// 而在输出时对边界内的特殊元素进行判断即可，注意全是墙没有通路的情况
// 需要额外加一圈0 
int myMap[32][32], visited[32][32];
int brim;
void dfs(int x, int y) {
	// 出界判定 ，注意这里因为加了一圈元素所以边界判定也要多一个 
	if (x < 0 || x > brim + 1 || y < 0 || y > brim + 1) return;
	// 访问过判定
	if (visited[x][y]) return;
	// 为边界判定，这里因为要把元素染为-1，所以特意判断下该元素是不是障碍 
	// if (myMap[x][y] == 1) return;这里写出这样会超时，估计是==1的条件太苛刻了
	// 以后用bfs这种算法尽量少写这种情况很死的判断 
	if (myMap[x][y] != 0) return;
	// 开始染色
	visited[x][y] = 1;
	if (myMap[x][y] == 0) myMap[x][y] = -1;
	dfs(x + 1, y); 
	dfs(x - 1, y); 
	dfs(x, y + 1); 
	dfs(x, y - 1); 
	visited[x][y] = 0;
}
int main() {
	cin >> brim;
	// 对地图进行初始化 
	for (int i = 1; i <= brim; i++) {
		for (int j = 1; j <= brim; j++) {
			cin >> myMap[i][j];
		}
	}
	// 给地图加一圈0，否则遇到第一条元素为00111100，第二条元素为11111..程序就不能正常执行了，因为全是墙 
	// 所谓加一圈0其实就是把起点-1了，因为其地图是全局的，所以默认为0，然后再到边界判定部分加1就行 
	dfs(0, 0);
	// 增加的一圈0并不需要，所以要改变遍历范文 
//	for (int i = 0; i <= brim + 1; i++) {
//		for (int j = 0; j <= brim + 1; j++) {
	for (int i = 1; i <= brim; i++) {
		for (int j = 1; j <= brim; j++) {
			// cout << myMap[i][j] << ' ';
			// 为被染色的围墙外的元素 
			if (myMap[i][j] == -1) {
				cout << 0 << ' ';
				continue;
			}
			// 为未被染色的围墙内的元素 
			if (myMap[i][j] == 0) {
				cout << 2 << ' ';
				continue; 
			}
			// 为围墙元素 
			cout << myMap[i][j] << ' ';
		}
		cout << endl;
	}
	return 0;
}
