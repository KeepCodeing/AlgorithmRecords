#include <iostream>
#include <cstdio>
using namespace std;

// ���ϵ�������Ϊ�����վ���ˣ�û�뵽ֻ�����Լ����ˣ����Ͷ��˴���..Ҳ������ûˮ���ˣ� ����������ˣ����ݱհ�w
// ��������ˢ����vjudge�ϵ��⣬��Щ����������ˢ�˲�֪����ȵ�����..�����˵û�������ô����w����֪���ǲ���ûʲô
// �ñȵģ�ָAC��֮���w��... 

const int N = 110;
int n, m, ut, vt;
int graph[N][N];
int main() {
	scanf("%d%d", &n, &m);
	while (m--) {
		scanf("%d%d", &ut, &vt);
		graph[ut][vt] = 1;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				// �ƺ������������Ͼ�����w������͵���ģ������... 
				if (graph[j][i] && graph[i][k]) graph[j][k] = 1;
			}
		}
	}
	int res = 0, cnt = 0;
	for (int i = 1; i <= n; i++) {
		cnt = 0;
		for (int j = 1; j <= n; j++) {
			if (graph[i][j] || graph[j][i]) cnt++;
		}
		if (cnt == n - 1) res++;
	}
	printf("%d", res);
	return 0;
}
