#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Ŀǰ��˼·���ȼ�¼��ǰ׺�ͣ�Ȼ��������ɢ����������ֵ����Сֵ
// ���ȥ���������ֵ����Сֵ����ȡ������С/���ֵ��Ϊǰ׺����Ҫ��ȥ
// ��ֵ��Ȼ������ȥ�Ծ��� 

// �ݣ������߶������������Ŀ�����˲ŷ��ֲ�����������Сֵ... 
// �������Ե���ɨһ�飬ÿ�ζԱȵ�ǰԪ�غ�ǰ��Ԫ�صĴ�С�������ǰԪ�ظ�С����ô��Сֵ�������ֵ
// ���������һ��ֵ 

typedef long long LL;
const int N = 100010;
LL s[N];
vector<int > vec, nums;
int findNum(int x) {
	return lower_bound(vec.begin(), vec.end(), x) - vec.begin();
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); 
	int n, t;
	cin >> n;
	s[0] = 0;
	for (int i = 1; i <= n; i++) cin >> t, vec.push_back(t), s[i] = s[i - 1] + t;
	nums = vec;
	sort(vec.begin(), vec.end());
	vec.erase(unique(vec.begin(), vec.end()), vec.end());
	int vLen = vec.size();
	for (int i = 1; i <= n - 2; i++) {
		cout << s[n] - s[i] << endl;
		int now = nums[i - 1];
		// �����ǰȥ����ֵ����Сֵ�����������ֵ����� 
		if (findNum(now) == 0) {
			// ���ȥ��������Сֵ���Ǿ���ǰ׺��-ԭ���ֵ-����Сֵ�Դ��ֵ 
		} else {
			// ����Ȳ������ֵ��Ҳ������Сֵ��ֱ����ǰ׺��-ԭ���ֵ-��Сֵ��ƽ��ֵ���� 
			 
		}
	}
	// �����̣�ֻ��ȥ����Сֵ... 
	/* else if (findNum(now) == vLen - 1) {
			// ���ȥ���������ֵ���Ǿͼ�������С��ֵ 
		}*/
	return 0;
}
