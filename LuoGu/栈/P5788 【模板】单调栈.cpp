#include <iostream>
using namespace std;

// ����̫���ӣ���Ϊ��ֻ���öԱ����Ԫ�صĵ���ջ��������Ա��Ҳ�Ԫ�صĵ���ջ�����Ի��˺ܳ�ʱ���
// ģ�壬�����޹������������뵽���԰����뷴�����������Ϳ�����ģ���ˣ���������ֳ������⣬��Ϊ
// ���뵹�����ģ��������ҲҪ��������������ֻ���˷���Ҫ��������û�Ĳ�����Ҫ�����������һֱ
// ���ڶ���һ��0����... 

const int N = 3 * 1000010;
typedef pair<int, int > PII;
PII nums[N], stk[N];
int res[N];
int n;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	int tt = 0;
	int cnt = 0;
	for (int i = n; i >= 1; i--) {
		cin >> nums[i].first;
		nums[i].second = n - i + 1;
	}
	for (int i = 1; i <= n; i++) {
		while (tt && stk[tt].first <= nums[i].first) tt--;
		if (tt) res[++cnt] = stk[tt].second; 
		else res[++cnt] = 0;
		tt++;
		stk[tt].second = nums[i].second, stk[tt].first = nums[i].first;
		
	}
	for (int i = cnt; i >= 1; i--) {
		cout << res[i];
		if (i != 0) cout << ' ';
	}
	return 0;
}
