#include <iostream>
using namespace std;

// ˼·��������������������һ����ͬ���ȣ���ͬһ�����������˵��
// ���������������γɻ���Ҳ������Ϸ���������û�л�����˵����������
// Ҫ����ӵ�һ�������� 

const int N = 210, M = N * N;
struct unionFind {
	int bin[M];
	unionFind() {
		// ���鼯�±��0��ʼ 
		for (int i = 0; i <= M; i++) bin[i] = i;
	}
	int anc(int x) {
		// ������д�� 
		if (x != bin[x]) bin[x] = anc(bin[x]);
		return bin[x];
	}
	void uni(int x, int y) {
		bin[anc(x)] = anc(y);
	}
	bool ask(int x, int y) {
		return anc(x) == anc(y);
	}
};
unionFind u;
int n, m;
// ��Ϊ������Ƕ�ά���ݣ������鼯ֻ�ܴ���һά�����ݣ���������Ҫ����ά
// ����ת��Ϊһά���ݣ���ʽΪx * n + y��ֻҪ��֤��ά����ת��Ϊһά����
// Ψһ���� 
int getDot(int x, int y) {return x * n + y;}
int main() {
	cin >> n >> m;
	int res = 0;
	for (int i = 1; i <= m; i++) {
		int x, y;
		char op;
		cin >> x >> y >> op;
		// ���±��0��ʼ������������x * n + y�����ʽ��ͬ�������鼯���±�Ҳ�ô�0��ʼ 
		x--, y--;
		int dot, ndot;
		// ��ȡ��ǰ���Ӧ��һά��ʾ 
		ndot = getDot(x, y);
		// ��ȡ�����������߶�Ӧ��һά��ʾ 
		if (op == 'D') dot = getDot(x + 1, y);
		else dot = getDot(x, y + 1);
		// �ж��������Ƿ���һ����ͨͼ�����ڣ�˵�������������γɻ�������Ϸ���� 
		if (u.anc(ndot) == u.anc(dot)) {
			res = i;
			break;
		}
		// ��������㲻��һ����ͨͼ������Ǻϲ� 
		u.uni(dot, ndot); 
	}
	if (res) cout << res;
	else cout << "draw";
	return 0;
}

/*
����������
3 5
1 1 D
1 1 R
1 2 D
2 1 R
2 2 D
���������
4
*/
