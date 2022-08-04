#include <iostream>
#include <algorithm>
#include <vector> 
using namespace std;

// ���ݷ�Χ̫�󣬵����ı����϶��ᳬʱ��������������
// ̰�Ľ⣬�ҵ������бȵ�ǰԪ�ش�����ٵ�ֵ���ߵ��ڵ�ֵ����
// ����Ҫע�����Ҫ�ҵ�ֵ�������ֵӦ�������ֵ����С��ֵ

// ��Ҫ�õ���lower_bound(first, last, ele)�����������Է��رȵ�ǰԪ�ش�ĵ�һ��
// ֵ��λ�ã������ǰֵ�������ֵ�����᷵��last����lastʵ����Խ���
// �ԱȵĻ��Ա��ǵ�ǰԪ�ؼ���ǰһ��Ԫ��С�������һ��Ԫ�ؼ���С���� 

// ����ⷢ��û����ô�����У�ֻ���ж���Сֵ�����ֵ���� 

vector<int > arr;
int main() {
	int m, n, temp;
	cin >> m >> n;
	int res = 0;
	for (int i = 0; i < m; i++) cin >> temp, arr.push_back(temp);
	sort(arr.begin(), arr.end());
	for (int i = 0; i < n; i++) {
		cin >> temp;
		// ת�����±꣬������������Խ�� 
		int index = lower_bound(arr.begin(), arr.end(), temp) - arr.begin();
		if (temp == arr[index]) {
			res += 0;
		} else if (index == 0 && m >= 2) {
			// ������ֵ����Сֵ
			 res += arr[index] - temp; 
		} else if (index == m - 1 && m >= 2 && temp >= arr[index]) {
			// ������ֵ�����ֵ��������С��ֵ���� 
			res += temp - arr[index];
		} else if (m == 1) {
			res += temp > arr[0] ? temp - arr[0] : arr[0] - temp;
		} else {
			int left;
			// ����ֵ 
			left = index - 1;
			// �ȵ�ǰ�����ֵ-��ǰ��С���ǵ�ǰֵ-�ȵ�ǰֵС��ֵС��ע��������ܳ���Сֵ����ֵ�������
			// ������û�붮��index�ǵ�һ�����ڵ���temp���±꣬leftӦ�þ��Ǹո�С��temp���±� 
			res += min(abs(arr[index] - temp), abs(temp - arr[left]));
		}
	}
	cout << res;
	return 0;
}
