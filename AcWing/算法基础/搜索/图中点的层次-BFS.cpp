#include <iostream>
#include <queue>
using namespace std;

// ��Ȩ�����ڣ�Ϊ1�������Կ�����BFS�����· 

// �ݲݲݣ���һ�δ𰸶�������ȫȫ�������ã����Ĵ�����ȫ���� 
// ��Ҫ��û�б�Ƿ��ʹ�����չ�ĵ�д���˱ߵı�ţ����о�������
// ��ʼ��ͷ��� 

const int N = 100010, M = N * 2;
struct Node {
	int u, step;
	Node () {};
	Node (int u, int step) : u(u), step(step) {};
};
int head[N], e[M], ex[M], idx = 0;
// ���ĳ�������Ƿ񱻷��ʹ���֮ǰ��Ȼû������� 
bool visited[N];
int n, m; 
queue<Node > que;
void add(int k, int val) {
	e[idx] = val;
	ex[idx] = head[k];
	head[k] = idx;
	idx++;
}
void bfs() {
	que.push((Node){1, 0});
	Node now;
	while (!que.empty()) {
		now = que.front();que.pop();
		if (now.u == n) {
			cout << now.step;
			return;
		}
		// ��������˵����ֽ�ͼ��ʽ����ʵ��vector�ڽӱ���һ����
		// ��һ���ĵط�����������ģ�����ǲ�֪��ĳ�����㵽���ж�����
		// �ߣ�ֻ��ͨ��-1��������˵��û�бߣ�Ҳ����˵����ex[i]��ʵ��
		// ��ĵ�ǰ����ı�ָ����Ǹ�����ı�ţ�֮ǰ��Ȼ��������ָ���
		// �����ֵ.... 
		for (int i = head[now.u]; i != -1; i = ex[i]) {
			// ���������ܵ��Ķ���ȡ���� 
			int j = e[i];
			// �ж���������Ƿ񱻷��ʹ� 
			if (!visited[j]) {
				// �������㱻������ 
				visited[j] = true;
				// ������㿪ʼ������չ 
				que.push((Node){j, now.step + 1});
			}
		}
		/*
		���ԶԱ���vector�ڽӱ����ʽ������д����Dijkstra�����·��ģ�� 
		que.push((Node){...});
		Node x = que.top();que.pop;
		for (int i = 0; i < graph[x.u].size(); i++) {...}
		*/ 
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	// ǧ��Ҫ���˳�ʼ��ͷ����ֵ����Ȼ������ʱ��û�취
	// ͣ���� 
	fill(head, head + N + 10, -1);
	cin >> n >> m;
	int u, v; 
	while (m--) { 
		cin >> u >> v;
		// ����ͼ 
		add(u, v);
	} 
	bfs();
	return 0;
}
/*
��������
4 5
1 2
2 3
3 4
1 3
1 4

2 4

�������
1
*/
