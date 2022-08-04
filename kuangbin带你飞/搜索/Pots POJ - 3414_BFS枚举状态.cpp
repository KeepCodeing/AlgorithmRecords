#include <iostream>
using namespace std;

// ������Ŀ��Ȼ���뵽BFS������ȴ��ȫû��ͷ����...����BFSҲ���һ������˼·��ͨ��BFSö������״̬�����Ҽ�¼·��...
// ������Ŀ����������������װ��Ͱ�����Ͱ����һ��Ͱ��ˮ������һ��Ͱ��ȥ...��ôÿ��״̬�������������װ��aͰ��װ��
// bͰ�����aͰ�����bͰ����aͰ��ˮ����bͰ����bͰ��ˮ����aͰ���ܹ�����״̬������д��BFSҲ����ö��������״̬���ͺ�
// ֮ǰд�ġ�����·�����Ǹ���һ��...

const int N = 110;
// aͰ�Ĵ�С��bͰ�Ĵ�С��Ҫ���ֵ�ˮ������
int a, b, c;
struct Node {
	// aͰ���ˮ��bͰ���ˮ������������ǰ�ڵ����һ���ڵ㣨�������·�������������ٲ���
	int x, y, op, last, step;
	Node(int x, int y, int op, int last, int step) : x(x), y(y), op(op), last(last), step(step) {};
	Node() {};
} que[N * N + 10];
// �������aͰװ�˶���ˮ��bͰװ�˶���ˮ..
bool visited[N][N];
// ��ӡ���.. 
void print(int op) { 
	if(op == 1) cout << "FILL(1)" << endl;
	else if (op == 2) cout << "FILL(2)" << endl;
	else if (op == 3) cout << "POUR(2,1)" << endl;
	else if (op == 4) cout << "POUR(1,2)" << endl;
	else if (op == 5) cout << "DROP(1)" << endl;
	else cout << "DROP(2)" << endl;
}
// �����������ΪҪ������������� 
void printPath(int last) {
	if (que[last].last == 0) {
		print(que[last].op);
		return;
	}
	printPath(que[last].last);
	print(que[last].op);
}
void bfs() {
	int qtop = 0, qback = 0;
	// ��ʼ��abͰ��ˮ������
	que[qtop] = Node(0, 0, 0, 0, 0);
	int at, bt;
	while (qtop <= qback) {
		Node now = que[qtop++];
		// ����ҵ��˴����������·����ע��������һ������������� 
		if (now.x == c || now.y == c) {
			cout << now.step << endl;
			printPath(qtop - 1);
			return;
		}
		// ö����6�ֲ�����Ӧ�����
		for (int i = 1; i <= 6; i++) {
			// ��aͰװ���������aͰ��ˮ�������ݻ���bͰ��ˮ����
			if (i == 1) at = a, bt = now.y;
			// ��bͰװ���������ͬaͰ
			else if (i == 2) at = now.x, bt = b;
			// ��bͰ��ˮ����aͰ�������ҪôaͰ�������ˣ�Ҫû��������û����aͰ��ˮ����ԭ����ˮ��bͰ��ˮ��
			// bͰ��ˮҪô�����ˣ�Ҫôû�У�û�е����bͰ��ˮ����ԭ����ˮ��ȥaͰ������װ����ˮ...
			else if (i == 3) at = min(a, now.x + now.y), bt = max(0, now.y - (a - now.x));
			// ��aͰ��ˮ����bͰ��ͬ��
			else if (i == 4) bt = min(b, now.x + now.y), at = max(0, now.x - (b - now.y));
			// ���aͰ��bͰˮ���ı�
			else if (i == 5) at = 0, bt = now.y;
			// ���bͰ��aͰˮ���ı�
			else at = now.x, bt = 0;
			// �ж��µ�ǰö�ٵ�״̬�Ƿ�ʹ�ù��ˣ���ӵ�ǰö�ٵ�״̬
			if (!visited[at][bt]) {
				visited[at][bt] = true;
				// ע�������¼��һ��״̬�ķ�ʽ����ͨ����ͷ���±����ģ���ǰ������״̬���Ǹ��ݶ�ͷԪ������
				// ����ͷ��ȡԪ�ص�ʱ����������������Ҫ����ȥ..
				que[++qback] = Node(at, bt, i, qtop - 1, now.step + 1);
			}

		}
	}
	// �����ܴճ�������� 
	cout << "impossible" << endl;
}
int main() {
	cin >> a >> b >> c;
	bfs();
	return 0;
}
