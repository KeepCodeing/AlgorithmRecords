#include <iostream>
using namespace std;

// һ�ۿ�������ȫ��Ԫ�ؼ���x��Ϊ������е��Ѷȣ���ת��һ��ȫ������xҲ����ζ�Ų���
// ĳ���������x����ô��ʵ���൱�ڵ������x��Ҳ���������ʱ������²������ۼ���x���� 

// �������ⷭ���ƺ��е����⣬����һ���Ǽ򵥵ĸ�ֵ�������������ֵ��ȥ���ӵ�ֵ

// ��ǰˮ��� 

// cin,cout�ر�ͬ��ao���������ݻ�������C����C���� 

typedef long L;
const int N = 1e5 + 10;
L arr[N];
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m; 
	for (int i = 1; i <= n; i++) cin >> arr[i];
	int op, x, tot = 0, ti;
	while (m--) {
		cin >> op >> x;
		if (op == 3) cout << arr[x] + tot << endl;
		else if (op == 2) tot += x;
		else cin >> ti, arr[x] = ti - tot;
	}
	return 0;
}
