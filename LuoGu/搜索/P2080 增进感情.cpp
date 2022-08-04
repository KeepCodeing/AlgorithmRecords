#include <iostream>
#include <cmath>
using namespace std;

// ����ı����⣬���ǻ����е��֦����
// ����������ԣ���֦���������Ѿ����������Ž⣨�⵱Ȼ�����б������ⶼҪ�ļ�֦w��������һ��ʼ��ĳ������Ž��
// �����ǵ���ǰ�øж�ֻ���Ѿ����ڴ�ʱ�����м�֦�����������Щ������ã���Щ�ⲻ���ã���Ϊ���ݵ������ԡ�
// ��֦���ǵø�����Ŀ�����������������������Ǹ��ݴ𰸽��м�֦ 

const int N = 35;
typedef pair<int, int > PII;
PII nums[N];
bool flag = false;
int n, v;
int getAbs(int a, int b) {
	return abs(a - b);
}
int res = 0x3fffffff;
void dfs(int level, int deepth, int va, int vb) {
	if (level == deepth) {
		int vi = getAbs(va, vb);
		if (va + vb >= v) flag = true, res = min(res, vi);
		return;
	}
	// һ��С��֦�����������TLE�������֦����˼�ǵ��øж�����Ѿ���С��ʱ�򣬾Ͳ����������� 
	if (!res) return;
	for (int i = level; i < deepth; i++) {
		dfs(i + 1, deepth, va + nums[i].first, vb + nums[i].second);
	}
}
int main() {
	cin >> n >> v;
	for (int i = 1; i <= n; i++) cin >> nums[i].first >> nums[i].second;
	dfs(1, n + 1, 0, 0);
	if (flag) cout << res;
	else cout << -1;
	return 0;
}
