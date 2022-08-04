#include <iostream>
#include <vector>
using namespace std;

// ���ǲ��˵�ӣ�����һ��ʼ��˼·��Ȼ�ǶԵģ����ǰ�x��y�������
// �����������Ļ��Ϳ�����һ��Ͱ��x��y�ϵļ���������Ȼ�����ߵĹ���
// ��ȥͰ���Ԫ�أ������յ���ж�Ͱ���Ԫ���Ƿ�Ϊ0����

// �ȵĿӣ���x��y�����������ϵ�x��y��ֻ�Ǿ���˳�������õģ������
// �����ʱ��û�п��ǵ�˳�򣬵��±����y��x�����о����յ����������
// ���λ�õļ���������������Զû�н�� 

int graph[25][25];
int xCnt[25], yCnt[25]; 
vector<int > path;
int n;
void dfs(int x, int y) {
	if (x < 0 || x >= n || y < 0 || y >= n) return;
	if (graph[x][y] < 0) return;
	// �����յ㣬�ж��Ƿ�����Ԫ��ʹ����� 
	if (x == n - 1 && y == n - 1) {
		// xCnt[n - 1]--, yCnt[n - 1]--;
		// ������ǲ��������� 
		bool flag = false;
		for (int i = 0; i < n; i++) {
			// cout << xCnt[i] << ' ' << yCnt[i] << ' ';
			if (xCnt[i] || yCnt[i]) {
				flag = true;
				break;
			}
		}
		// cout << endl;
		// �����˾������� 
		if (!flag) {
			int vLen = path.size();
			for (int i = 0; i < vLen; i++) {
				cout << path[i] << ' ';
				// if (i != vLen - 1) cout << ' ';
			}
			// �յ�����������Ϊ�ټӵ�ʸ����Ҫ�ָ�״̬�Ƚ��鷳
			cout << graph[x][y];
		}
		return;
	}
	// ����߹��ĵ� 
	int temp = graph[x][y];
	graph[x][y] = -1;
	// ��(x, y)���괦��ֵ 
	path.push_back(temp);
	// ����Ԫ�ؼ��� 
	xCnt[x]--, yCnt[y]--;
	// ����Ϊ������������֦������������ 
	// if (xCnt[x] < 0 || yCnt < 0) return;
	dfs(x + 1, y);
	dfs(x - 1, y);
	dfs(x, y + 1);
	dfs(x, y - 1);
	// �ָ�״̬ 
	path.pop_back();
	xCnt[x]++, yCnt[y]++;
	graph[x][y] = temp;
}
int main() {
	cin >> n;
	// ��Ϊ��д����x��y����ʵ��λ����x��y�෴�����Խ���������˳�� 
	for (int i = 0; i < n; i++) cin >> yCnt[i];
	for (int i = 0; i < n; i++) cin >> xCnt[i];
	// �յ�ļ����������⴦����Ϊ���ڵ����յ�󲢲����ٽ��յ�ļ���
	// ������Ȼ��ָ� 
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
