#include <iostream>
#include <cstring>
#include <sstream>
using namespace std;

// ��������������Ǹ�floyd������...�����Ѷ�w������Ҳ�Ƚ�����w���������һ�������Ǿ���Ȼ��ÿһ�б�ʾ��
// ��ʵ��һ�����ݱ�����������ӣ�һ��ʼû����w����ʵ�����ڻ��ǱȽ��ɻ�����������w 
/*
��Ϊ��������Ǹ��ԳƵģ�������Ŀ������ʵ��0�Խ������������... 
0 1 1 1
1 0 1 1
1 1 0 1
1 1 1 0
*/ 

const int N = 110;
int graph[N][N];
int main() {
	int n, temp;
	string w;
	stringstream ss;
	cin >> n;
	// �Ƚ������ĳ�ʼ���ڽӾ���ķ�ʽ
	memset(graph, 0x3f, sizeof graph);
	for (int i = 1; i <= n; i++) graph[i][i] = 0;
	// ��ʼ���룬��Ϊ��һ��û�����ݣ�����ֱ�Ӵӵڶ������ߣ���˫���
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= i -1; j++) {
			cin >> w;
			// ע������Ҫ��������ת������һ��ʼ����Ϊ����char���㣬���Ǻ��������ֲ�����ֻ��һλw������ֱ������
			// ����Ϊ��ʼ����ʱ��ÿ���㶼�ǲ������ģ���˿���ֱ������ 
			if (w == "x") continue;
			// �ַ���ת����... 
			ss << w, ss >> temp, ss.clear();
			graph[i][j] = graph[j][i] = temp;
		}
	} 
	// �װ��� 
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				graph[j][k] = min(graph[j][k], graph[j][i] + graph[i][k]);
			}
		}
	}
	int ans = 0;
	// ����1��������ľ��룬��ĿҪ����ȴ�ʱ�䣬��ʵ������1������������... 
	for (int i = 2; i <= n; i++) {
		if (graph[1][i] != 0x3f3f3f3f) {
			ans = max(ans, graph[1][i]);
		}
	}
	cout << ans;
	return 0;
}
