#include <iostream>
#include <vector>
using namespace std;

// 还是踩了点坑，但是一开始的思路居然是对的，就是把x，y坐标分离
// 来看，这样的话就可以用一个桶存x，y上的箭的数量，然后在走的过程
// 中去桶里减元素，到达终点后判断桶里的元素是否都为0即可

// 踩的坑：其x，y不是坐标轴上的x，y，只是觉得顺就这样用的，结果在
// 输入的时候没有考虑到顺序，导致变成了y，x，还有就是终点里其忽略了
// 这个位置的箭的数量，导致永远没有结果 

int graph[25][25];
int xCnt[25], yCnt[25]; 
vector<int > path;
int n;
void dfs(int x, int y) {
	if (x < 0 || x >= n || y < 0 || y >= n) return;
	if (graph[x][y] < 0) return;
	// 到达终点，判断是否所有元素使用完毕 
	if (x == n - 1 && y == n - 1) {
		// xCnt[n - 1]--, yCnt[n - 1]--;
		// 标记下是不是用完了 
		bool flag = false;
		for (int i = 0; i < n; i++) {
			// cout << xCnt[i] << ' ' << yCnt[i] << ' ';
			if (xCnt[i] || yCnt[i]) {
				flag = true;
				break;
			}
		}
		// cout << endl;
		// 用完了就输出结果 
		if (!flag) {
			int vLen = path.size();
			for (int i = 0; i < vLen; i++) {
				cout << path[i] << ' ';
				// if (i != vLen - 1) cout << ' ';
			}
			// 终点额外输出，因为再加到矢量里要恢复状态比较麻烦
			cout << graph[x][y];
		}
		return;
	}
	// 标记走过的点 
	int temp = graph[x][y];
	graph[x][y] = -1;
	// 放(x, y)坐标处的值 
	path.push_back(temp);
	// 箭靶元素减少 
	xCnt[x]--, yCnt[y]--;
	// 还以为可以这样剪下枝，不过不可行 
	// if (xCnt[x] < 0 || yCnt < 0) return;
	dfs(x + 1, y);
	dfs(x - 1, y);
	dfs(x, y + 1);
	dfs(x, y - 1);
	// 恢复状态 
	path.pop_back();
	xCnt[x]++, yCnt[y]++;
	graph[x][y] = temp;
}
int main() {
	cin >> n;
	// 因为其写的是x，y，但实际位置上x和y相反，所以交换下输入顺序 
	for (int i = 0; i < n; i++) cin >> yCnt[i];
	for (int i = 0; i < n; i++) cin >> xCnt[i];
	// 终点的箭靶数量特殊处理，因为其在到了终点后并不能再将终点的箭靶
	// 数减少然后恢复 
	yCnt[n - 1]--, xCnt[n - 1]--;
	int num = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			graph[i][j] = num++;
		}
	}
	dfs(0, 0);
	return 0;
} 
