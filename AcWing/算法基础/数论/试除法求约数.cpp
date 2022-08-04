#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// ���������ӵ���һ����ͬ���������Գ����Ż� 

// n % i == 0����Ϊһ��Լ��������������� n / iҲ������һ��Լ��
// Ҳ����˵һ������������Լ�����Եõ����������һ��Լ������Ȼ���ܻ���ͬ������Ҫ�ж��³����ǲ���
// ��Լ��һ�� 

vector<int > solve(int n) {
	vector<int > res;
	// �Գ��������⻹Ҫ�ж�һ��������������ǵ�n = i��ʱ�����ǵõ��ľ���1
	for (int i = 1; i <= n / i; i++) {
		if (!(n % i)) {
			// ���Ȱ�n������Լ����ӽ��⼯�� 
			res.push_back(i); 
			// �ٰѺ�벿�ֿ��ܵ�Լ����ӵ��⼯�����Ҫ�ж���i�ǲ��ǲ�����n / i��Ҳ����
			// 1�����  
			if (i != n / i) res.push_back(n / i); 
		}
	} 
	sort(res.begin(), res.end());
	return res;
}

int main() {
	int n;
	cin >> n;
	while (n--) {
		int x;
		cin >> x;
		vector<int > res = solve(x);
		for (int i = 0; i < res.size(); i++) cout << res[i] << ' ';
		cout << endl;
	} 
	return 0;
}
/*
��������
2
6
8

�������
1 2 3 6 
1 2 4 8 
*/ 
