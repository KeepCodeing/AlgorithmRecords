#include <iostream>
#include <cstring>
using namespace std;

// ��ν����ͼ��������ͼ������������ɫ��ʾ�������ǰ�ڵ����ɫΪ��ɫ����ô��������ֱ�������ĵ㶼�ñ�Ⱦ����ɫ��
// �෴����ǰ�ڵ�Ϊ��ɫ���������Ľڵ��Ҫ��Ⱦ�ɺ�ɫ���������κ�һ���ڵ��ֱ�������ĵ����ɫ�뵱ǰ����ͬ��
// ��ô���ǵ�˼·����ö������û��Ⱦɫ�ĵ㣬Ȼ�����DFS������ǰ�����ɫȾ��color���������������ɫȾ��-color��
// �Դ�����ֱ������ͼ����Ⱦɫ�˻����������������ɫ�����˳�ͻ������Ҫע�����ͼ��һ����ֻ��һ����ͨ�飬Ҳ
// �����Ǹ�ɭ�֣�����color�����������������ɫ��Ҳ�����������ֵ�ǰ��ͨ���еĵ��Ƿ�Ⱦɫ... 

const int N = 1e5 + 10, M = N * 2;
int head[N], e[M], ex[M], idx = 0;
int color[N];
void add(int ut, int vt) {
	e[idx] = vt, ex[idx] = head[ut], head[ut] = idx++;
}
bool dfs(int now, int c) {
	color[now] = c;
	for (int i = head[now]; i != -1; i = ex[i]) {
		int vt = e[i];
		if (color[vt] == color[now]) return false;
		// ������߼��������ǰ��û�б�Ⱦɫ��û�б����ʣ�������&&�����������ʣ�����ǰ����һ����Ⱦɫ�����ҵ�
		// ��ǰ��û��Ⱦɫ�����Ǵ�����ɫ��ͬ�ĵ�ʱ������false  
		if (!color[vt] && !dfs(vt, -c)) return false;
//		color[vt] = -c;
//		dfs(vt, -c);
	}
	// �������Ⱦɫ�˾ͷ���true 
	return true;
}
int main() {
	memset(head, -1, sizeof head);
	int m, ut, vt;
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> ut >> vt;
		add(ut, vt), add(vt, ut);
	}
	cout << dfs(1, 1);
	return 0;
} 
/*
7
1 2
1 4
2 1
2 3
3 2
3 4
4 1
4 3
true

9
1 2
1 3
1 4
2 1
2 3
3 1
3 2
3 4
4 1
4 3
false

*/
