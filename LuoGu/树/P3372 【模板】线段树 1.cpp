#include <iostream>
using namespace std;

// �߶����ڶ�����Ϊʲô��һ������ģ������..�����û����... 
// ���̣�ͻȻ�����������޸ģ�Ҳ������Ҫ����ǣ�������ʱ�ŷ������... 

const int N = 1e5 + 10, M = N * 4 + 10;
long long arr[N], root[M];
void build(int now, int left, int right) {
	int mid = (left + right) / 2;
	int l_node = now * 2 + 1, r_node = now * 2 + 2;
	build(l_node, left, mid);
	build(r_node, mid + 1, right);
	
}
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> arr[i];
	while (m--) {
		
	}
	return 0;
}
