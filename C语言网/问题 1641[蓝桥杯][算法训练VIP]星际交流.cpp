#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// ���̣�������Ϊ�������в�һ���ǵ�һ���ģ����ǿ���������Ǹ��ĵ�һ�� 

vector<int > vec;
int main() {
	int n, m;
	cin >> n >> m;
	int temp;
	while (n--) cin >> temp, vec.push_back(temp);
	do {
		if (m <= 0) break;
		m--;
	} while (next_permutation(vec.begin(), vec.end()));
	int vLen = vec.size();
	for (int i = 0; i < vLen; i++) {
		cout << vec[i];
		if (i != vLen - 1) cout << ' ';
	}
	return 0;
}
