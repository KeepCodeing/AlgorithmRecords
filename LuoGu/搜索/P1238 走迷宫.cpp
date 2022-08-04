#include <iostream>
using namespace std;

// ԭ��Խ�粻����Ϊ�±꣬������Ϊ��û�жԷ��ʹ�Ԫ�ؽ��б�� 

struct point {
	int x, y;
	point(int x1 = 0, int y1 = 0) {
		x = x1, y = y1;
	}
};
int numMap[20][20];
int m, n;
// ��ʼλ�ã��յ� 
int start_x, start_y, end_x, end_y;
// �洢�߹��ĵ� 
point p;
point result[50000];
// ����Ƿ��н� 
bool flag = false;
// ����� 
void printResult(int deepth) {
	for (int i = 0; i < deepth; i++) {
		cout << "(" << result[i].x << "," << result[i].y << ")" << "->";
	}
	// �����յ�
	cout << "(" << end_x << "," << end_y << ")" << endl;
}
void dfs(int x, int y, int level) {
	if (x > m || x < 1 || y > n || y < 1) return;
	if (!numMap[x][y]) return;
	numMap[x][y] = 0;
	// ���·�� 
	p.x = x, p.y = y;
	// ���·�� 
	result[level] = p;
	if (x == end_x && y == end_y) {
		// ����н� 
		flag = true;
		printResult(level);
		 
	}
	// ��Ŀ��˳���������£����������һ�� 
	dfs(x, y - 1, level + 1);
	dfs(x - 1, y, level + 1);
	dfs(x, y + 1, level + 1);
	dfs(x + 1, y, level + 1);
	numMap[x][y] = 1;
}
int main() {
	cin >> m >> n;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> numMap[i][j];
		}
	}
	cin >> start_x >> start_y;
	cin >> end_x >> end_y;
	// �յ㲻���ߵ�����
	if (numMap[end_x][end_y] != 1) {
		cout << "-1";
		return 0;
	} 
	dfs(start_x, start_y, 0);
	if (!flag) cout << "-1";
	return 0;
}
