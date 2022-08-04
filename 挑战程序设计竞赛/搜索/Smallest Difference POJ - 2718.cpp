#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

// �ƺ���������������Ƶ��⣿��֮���ǰ�ÿ��״̬��ö�ٵ�������...
// �����и����黮��������⣬�Ǹ�����ǰ׺��ö��.... 
// �����󲿷������ȫ�������ģ���fiveд��DFS����... 

// ��������ⲻ�Ǽ򵥵���Ŀ����Ӽ����⣬���ǿ���ѡ����һ���Ӽ���ʱ�򣬻�Ҫͨ��ĳ�ַ�����ȡ����Ӽ��Ĳ���...
// ��������ȫ��������w 

// ȫ���е�˼·�ǽ��ַ�����Ϊ�������֣����������־����������ǰ��0�����������ַǷ����������ڵڶ�������
// �����������01����λ��ǰ��0�ַ�������Ϊ��Ҳ�ǺϷ��ģ����ǲ������������0111���ַ������������ֳ������־��ǷǷ��� 

// CE�����Σ���һ��ѡ����������C++����ʾû��getline()���ڶ���ѡ���G++����ʾû��getchar()������ͷ�ļ��ͺ���... 

const int N = 15, INF = 0x3fffffff;
int nums[N];
int n;
int myabs(int a) {
	return a < 0 ? -a : a;
}
int getNum(int st, int ed) {
	int res = 0;
	for (int i = st; i < ed; i++) res = res * 10 + nums[i];
	return res;
}
int main() {
	int idx = 0, temp, res;
	string str;
	cin >> n;
	getchar();
	while (n--) {
		idx = 0, res = INF;
		getline(cin, str);
		for (int i = 0; i < str.size(); i++) {
			if (str[i] != ' ') nums[idx++] = str[i] - '0';
		}
		do {
			// �����벿�ֵ��ַ���������ǰ��0�����Ұ벿���ַ���������ǰ��0�����ַ������ȴ���2�����Գƣ���
			// ����Ϊ���ö���ǷǷ��� 
			if (nums[0] == 0 || (nums[idx / 2] == 0 && idx > 2)) continue;
			temp = myabs(getNum(0, idx / 2) - getNum(idx / 2, idx));
			res = min(res, temp);
		} while (next_permutation(nums, nums + idx));
		cout << res << endl;
	}
	return 0;
}
