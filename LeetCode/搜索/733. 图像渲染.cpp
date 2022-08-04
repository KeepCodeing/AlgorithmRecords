#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// ����һ����һ����������BFS����
// ���ӱ����Ѷ�����BFS���Ǹ��Ӹ���Щ 
// �ݣ����queue��front����д����back��Ȼ�����е㲻�ܱ�Ⱦɫ��������������1��Сʱ����... 
// ���ⲻ֪���ǲ�����д��̫���˳���Ч�ʼ��ͣ��ɴ˿�������DFS�ȽϺ� 

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
		// ���Ӽ����������Ȳ���ǣ�ֱ���ã�Ȼ������չ������ 
		// ����ʼ�����Ⱦɫ���൱�ڱ��vis 
		// result[start_x][start_y] = color;
		pos next(0, 0);
		int nx = 0, ny = 0;
		while(!que.empty()) {
			next = que.front();que.pop();
			result[next.x][next.y] = color;
			// ��DFS��࣬�޷Ǿ��ǳ��磬����ԭ��ɫ�жϵ� 
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
