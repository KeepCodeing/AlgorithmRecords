#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 和上一个题一样，这里用BFS做下
// 单从编码难度来看BFS还是更加复杂些 
// 草，错把queue的front方法写成了back，然后总有点不能被染色到，就这样花了1个小时调试... 
// 另外不知道是不是其写的太烂了程序效率极低，由此看来还是DFS比较好 

class Solution {
public:
	int line, col;
	struct pos {
		int x, y;
		pos(int x, int y) : x(x), y(y) {};
	};
	vector<vector<int> > result;
	queue<pos > que;
	void bfs(int start_x, int start_y, int color, int target) {
		int nx_arr[] = {1, -1, 0, 0};
		int ny_arr[] = {0, 0, 1, -1};
		que.push((pos){start_x, start_y});
		// 更加简洁的做法是先不标记，直接用，然后再扩展其它点 
		// 对起始点进行染色，相当于标记vis 
		// result[start_x][start_y] = color;
		pos next(0, 0);
		int nx = 0, ny = 0;
		while(!que.empty()) {
			next = que.front();que.pop();
			result[next.x][next.y] = color;
			// 和DFS差不多，无非就是出界，不是原颜色判断等 
			for (int i = 0; i < 4; i++) {
				nx = next.x + nx_arr[i], ny = next.y + ny_arr[i];
				if (nx < 0 || nx >= line || ny < 0 || ny >= col) continue;
				if (result[nx][ny] != target) continue;
				// result[nx][ny] = color;
				que.push((pos){nx, ny});
			}
		}
	}
    vector<vector<int> > floodFill(vector<vector<int> >& image, int sr, int sc, int newColor) {
		int target = image[sr][sc];
		this->line = image.size(), col = image[0].size();
		this->result = image;
		if (newColor != target) bfs(sr, sc, newColor, target);
		return result;
    }
}; 

int main() {
	return 0;
}
