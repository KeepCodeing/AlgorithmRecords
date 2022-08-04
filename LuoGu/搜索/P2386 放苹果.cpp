#include <iostream>
#include <vector>
using namespace std;

// ���ѣ���ƻ�������ɿ����õ���������������һ�����ö��ٸ�������֮���Ǹ��򵥴������� 

// �ٳ�������Ŀ����m�����ӣ�ÿ�����ӿ��Է�1~n��ƻ��..�����У����ֿ����ظ�ʹ�ã�Ҳ����1..1..1..
// 1..1..2..֮������ 

// ����ͨ�Ĵ�������w��ֻ������Ŀ�����Ƚ�������� 

// ��Ȼ�����ļ򵥣�����������յ��ӵ�����ǲ���Ҫ�����жϵģ����ڿ�������֮ǰ��˼·������
// ֮ǰ�����Ĭ��ÿ�����Ӷ�������һ��ƻ�������ԾͲ��ܿ��ǵ��յ��ӵ����

// ��ʵ��������7��������3������������7 0 0��1 6 0�� 2 5 0��������￴���и�0����ʵ��˼����
// ѡ���������߸��ٵ������ܹ��ճ�Ŀ������...������ֻҪ��֤����������ѡ���ҵ�ǰû��ѡ������
// �Լ���������ѡ�����ǵ�ǰ�Ѿ�ѡ�����˵��������.. 

typedef long long LL;
LL ans = 0;
vector<int > path;
void dfs(int level, int deepth, int sn, int target, int used) {
	// ѡ���˾Ͳ���ѡ�ˣ���������û��һ����֦... 
	if (used < 0) return;
	if (sn == target) {
//		for (int i = 0; i < path.size(); i++) cout << path[i] << ' ';
//		cout << endl;
		ans ++;
		return;
	}
	// ��ѡ... 
	for (int i = level; i < deepth; i++) {
		path.push_back(i); 
		dfs(i, deepth, sn + i, target, used - 1);
		path.pop_back();
	}
}
int main() {
	int T;
	cin >> T;
	int m, n;
	while (T--) {
		cin >> m >> n;
		ans = 0;
		dfs(1, m + 1, 0, m, n);
		cout << ans << endl;
	} 
	return 0;
}
