#include <iostream>
#include <vector>
using namespace std;

// wl到刷模拟了 

// 这里采用矢量做存储介质，因为其直接把一行命令/迷宫搞成字符串了 
// 坠毁，这样搞反而更麻烦了，主要是起点和终点的位置确定 
//vector<string > mz;
//vector<string > commands;
// 王道征途，字符数组系 
char maze[1005][1005];
int main() {
	int n;
	int mazeSize;
	int m;
	string comStr;
	int sx, sy, ex, ey; 
	cin >> n;
	while (n--) {
		cin >> mazeSize;
		for (int i = 0; i < mazeSize; i++) {
			for (int j = 0; j < mazeSize; j++) {
				cin >> maze[i][j];
				if (maze[i][j] == 'S') sx = i, sy = j;
				if (maze[i][j] == 'T') ex = i, ey = j;
			}
		}
		cin >> m;
		while (m--) {
			cin >> comStr;
			string res = "";
			// 谔谔，居然没想到把坐标恢复... 
			int tSx = sx, tSy = sy;
			for (int i = 0; i < comStr.size(); i++) {
				switch(comStr[i]) {
					// 总是把x的上下写反，在数组里上下可不是在坐标轴里上下
					case 'U':
						tSx -= 1;
						break;
					case 'D':
						tSx += 1;
						break;
					case 'L':
						tSy -= 1;
						break;
					case 'R':
						tSy += 1;
						break;
				}
				// 处理撞到障碍和走出边界的情况，这两种情况
				// 应该都是立即终止遍历，而没到终点和到了终点
				// 都是能正常执行完才会有的
				// 喜闻乐见的出界判断，而且是先判断是否出界，不然后面判断
				// 障碍就无法保证下标有效了 
				 if (tSx < 0 || tSy < 0 || tSx >= mazeSize || tSy >= mazeSize) {
				 	// 坑I  am  out!，这是直接复制给的，下面是样例输出的 
				 	res = "I am out!";
				 	break;
				 } 
				 if (maze[tSx][tSy] == '#') {
				 	res = "I am dizzy!";
				 	break;
				 }
				 // 另外题目中的数据表示到达了终点也要直接退出，所以这里直接退出，给外面处理
				 if (maze[tSx][tSy] == 'T') break; 
			}
			// 如果前两种情况触发了，就不能判断后两种情况
			if (res.size()) {
				cout << res << endl;
				continue;
			} 
			if (tSx == ex && tSy == ey) res = "I get there!";
			else res = "I have no idea!";
			cout << res << endl;
		}
	}
	return 0;
}
