#include <iostream>
#include <algorithm>
using namespace std;

// ��һ����Ϊ��01����ww��Ȼ������n����������ֻ��ѡk������ͺ�01������һ���ˣ�01�����Ǵ�n������ѡ���ɸ�w
// ��������֪���Ǹ�������Ϊ����ӿ��Ե���׬Ǯ�����Լ۸�ԽС׬��Խ��...

// ����˵�����Ŀ�Ǵ�n������ѡ���ɸ�����Ȼ�������Ž⣬�ǿ�����Dp����ָ�������������ѡk�������Ǿ;��Բ���Dp 

const int N = 110;
int nums[N];
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> nums[i];
	// ע������Χ 
	sort(nums + 1, nums + n + 1);
	int res = 0;
	for (int i = 1; i <= m; i++) {
		// ֻѡ����׬Ǯ���߲���Ǯ�ĵ��� 
		if (nums[i] <= 0) res += -nums[i];
	}
	cout << res;
	return 0;
}
