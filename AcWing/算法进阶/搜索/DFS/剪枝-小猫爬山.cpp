#include <iostream>
#include <algorithm> 
using namespace std;

// ���ȿ�������˳�򣬸��ݼ�֦�����������ڵ�Խ�ٵ�·��Խ���ȱ���
// �������ݻ���һ���ģ���ôèԽ��������ķ�֧�ͻ�Խ�٣���������
// ˳���ǴӴ�С 

const int N = 20;
int cats[N];
bool cmp(int a, int b) {return a > b;}
int ans = N;
int n, w;
bool used[N];
void dfs(int level, int deepth, int sw) {
	cout << sw << endl;
	if (sw <= w && sw != 0) used[level] = true;
	if (sw > w) {
		ans++;
		used[level] = true;
		return;
	}
	for (int i = level; i < deepth; i++) {
		if (!used[i])
		dfs(i + 1, deepth, sw + cats[i]);
	}
} 
int main() {
	cin >> n >> w;
	for (int i = 0; i < n; i++) cin >> cats[i];
	// �Ӵ�С�����Ż�����˳�������̣���Ϊ�±��1��ʼ��������
	// Ҳ�ô�1��ʼ�ţ��Ƚ��鷳�����Ǵ�0��ʼ���� 
	sort(cats, cats + N, cmp);
	// for (int i = 0; i < n; i++) cout << cats[i] << ' ';
	dfs(0, n, 0);
	cout << ans;
	return 0;
} 
/*
5 1996
1
2
1994
12
29

2
*/
