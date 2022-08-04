#include <iostream>
using namespace std;
int map[6][6], visited[6][6], counter = 0;
int N, M;
void init_map(int N, int M) {
	for (int i = 1; i <= N; i++) {
		for (int n = 1; n <= M; n++) {
			map[i][n] = 1;
		}
	}
}
void dfs(int start_x, int start_y, int end_x, int end_y) {
	// ����ֹ����д��ǰ�棬������ʹ�յ����ϰ���Ҳ�����bug 
	// �����ʹ��������ϰ��� 
	if (visited[start_x][start_y] || !map[start_x][start_y]) return;
	// ���� 
	if (start_x > N || start_x < 1 || start_y > M || start_y < 1) return;
	if (start_x == end_x && start_y == end_y) {
		counter++;
		return;
	}
	visited[start_x][start_y] = 1;
	dfs(start_x + 1, start_y, end_x, end_y);
	dfs(start_x - 1, start_y, end_x, end_y);
	dfs(start_x, start_y + 1, end_x, end_y);
	dfs(start_x, start_y - 1, end_x, end_y);
	visited[start_x][start_y] = 0;
}
int main() {
	int T;
	int s_x, s_y, e_x, e_y;
	int hurdle_x, hurdle_y;
	cin >> N >> M >> T;
	cin >> s_x >> s_y >> e_x >> e_y;
	init_map(N, M);
	for (int i = 1; i <= T; i++) {
		cin >> hurdle_x >> hurdle_y;
		/*if (hurdle_x == e_x && hurdle_y == e_y) {
			// ��Ŀ��֤����㲻Ϊ�ϰ����û˵�յ㲻Ϊ�ϰ��
			// ����յ�Ϊ�ϰ�����޽� 
			cout << 0 << endl;
			return 0;
		}*/
		map[hurdle_x][hurdle_y] = 0;
	}
	dfs(s_x, s_y, e_x, e_y);
	cout << counter << endl;
	return 0;
} 
