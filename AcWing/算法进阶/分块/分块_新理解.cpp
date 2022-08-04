#include <iostream>
#include <cmath>
#define endl '\n'
using namespace std;
typedef long long LL;
const int N = 1e5 + 10;
LL nums[N], sum[N], add[N];
int L[N], R[N], pos[N];
void change(int l, int r, LL d) {
	int p = pos[l], q = pos[r];
	if (p == q) {
		for (int i = l; i <= r; i++) nums[i] += d;
		sum[p] += (r - l + 1) * d;
	} else {
		// ��p, q֮���ÿһ�飨Ҳ����p, q��Ϊ����������ֱ�Ӽ��㣩����������� 
		for (int i = p + 1; i <= q - 1; i++) add[i] += d;
		// ���p, q������ 
		for (int i = l; i <= R[p]; i++) nums[i] += d;
		sum[p] += (R[p] - l + 1) * d;
		for (int i = L[q]; i <= r; i++) nums[i] += d;
		sum[q] += (r - L[q] + 1) * d;
	}
}
LL ask(int l, int r) {
	int p = pos[l], q = pos[r];
	LL ans = 0;
	if (p == q) {
		for (int i = l; i <= r; i++) ans += nums[i];
		ans += add[p] * (r - l + 1);
	} else {
		// ֱ�����p, q֮������ɿ�ĺͣ�����p, q֮ǰ�����ɿ�һ������������һ�����еģ�����ֱ����sum[i]�����
		// �����еĺͣ��ټ��������Χ�ڵ����� 
		for (int i = p + 1; i <= q - 1; i++) ans += sum[i] + (R[i] - L[i] + 1) * add[i];
		// ���p, q������ĺͣ�ע�������и�ϸ����û��sum����Ϊsum�����һ����ĺͣ���p, q����ֻ�в������ 
		for (int i = l; i <= R[p]; i++) ans += nums[i];
		// ע����������䷶Χ������r - l + 1������R[p] - l + 1������ͬ��������Ϊ���ﵥ����p, q��������д�����������
		// ��С������������Ҷ˵���� 
		ans += add[p] * (R[p] - l + 1);
		for (int i = L[q]; i <= r; i++) ans += nums[i];
		ans += add[q] * (r - L[q] + 1);
	}
	return ans;
}
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, m, l, r, d;
	char op;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> nums[i];
	// ע�������и�ǿת�������еı�������sqrt����������int�����ӿ���CE... 
	int t = sqrt((float)n);
	for (int i = 1; i <= t; i++) {
		L[i] = (i - 1) * t + 1;
		R[i] = t * i;
	}
	// ע����仰��λ�ã���������ڳ�ʼ��ÿ��ڵ�֮���������ܱ�֤�ֵĿ��ܰ��������а���������ע��L[t] = R[t - 1] + 1��
	// �����+1������ֹ�¼ӵ���һ����������֮ǰ��һ����������غ� 
	if (R[t] < n) t++, L[t] = R[t - 1] + 1, R[t] = n;
	for (int i = 1; i <= t; i++) {
		for (int j = L[i]; j <= R[i]; j++) {
			pos[j] = i;
			sum[i] += nums[j];
		}
	}
	while (m--) {
		cin >> op >> l >> r;
		if (op == 'C') cin >> d, change(l ,r, d);
		else cout << ask(l, r) << endl;
	}
	return 0;
}
