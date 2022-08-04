#include <iostream>
#include <cstdio>
using namespace std;

// ��һ�ν�д��n��m�ˣ�ʵ����m��n����ȻֻWA��һ����w��̫������...
// ���Ǹ��̵�̺�������ƣ������Ͻ����½ǵ�������������ж��µ�ǰ���ڲ����������... 

const int M = 2010;
struct Node {
	int x1, y1, x2, y2;
	Node (int x1, int y1, int x2, int y2) : x1(x1), y1(y1), x2(x2), y2(y2) {};
	Node () {};
};
Node pos[M];
int main() {
	int n, m;
	// n��mд���ˣ�ֻ���������Լ�ϰ������Ȼ���У����ǵð���Ŀ����˳����������m==n���Ӳ��Ե�����ֻ��һ���㲻������w�� 
	scanf("%d%d", &m, &n);
	for (int i = 1; i <= m; i++) scanf("%d%d%d%d", &pos[i].x1, &pos[i].y1, &pos[i].x2, &pos[i].y2);
	int x, y, cnt, pre;
	while (n--) {
		scanf("%d%d", &x, &y), cnt = 0, pre = 0;
		for (int i = 1; i <= m; i++) {
			// ������ˣ��ҵ��߽���ϲ���... 
			if (pos[i].x1 < x && pos[i].y1 < y && pos[i].x2 > x && pos[i].y2 > y) cnt++, pre = i;
		}
		if (cnt) printf("YES %d %d\n", cnt, pre);
		else printf("NO\n");
	}
	return 0;
}
