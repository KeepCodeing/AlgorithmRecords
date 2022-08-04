#include <iostream>
#include <vector>
using namespace std;

// ��ʵ���Ǹ�ȫ���У����ǵ��ŷ���Ϊ3ʱ������Ϊ
// index1 != 1, index2 != 2, index3 != 3����Ҳ����˵
// ����������ȫ���к�ֻ��Ҫ�Ա��ǲ�����ĳ�����е����ֺ͸��±겻��ͬ����
// ���԰��ŷ��װ������ȫ���У�Ҫ��ͬ�����������ֶ�����ԭ��λ���� 

// ���Ѻ�������׹���ˣ�ֻ���ѵ�10���ң������ʵ���Ǹ�
// �������Ѿ�������f[0]~f[n-1],����f[n],������һ����n��
// �����Ҫ�Ŵ�λ����n-1����������������ķ���ÿ�ζ���f[n-1]
// ���������nռ��λ�õ���k����k����nλ�ã������ٶ��f[n-2]������� 

vector<int > vec;
bool visited[25];
long long cnt = 0;
void dfs(int level, int deepth) {
	if (level == deepth + 1) {
		bool flag = true;
		for (int i = 0; i < vec.size(); i++) {
			if (vec[i] == i + 1) {
				flag = false;
				break;
			}
		}
		if (flag) cnt++;
		return;
	}
	for (int i = 1; i <= deepth; i++) {
		if (!visited[i]) {
			visited[i] = true;
			vec.push_back(i);
			dfs(level + 1, deepth);
			vec.pop_back();  
			visited[i] = false;
		}
	}
}
long long result[25];
int main() {
	int n;
	cin >> n;
	// dfs(1, n);
	result[0] = 1, result[1] = 0;
	for (int i = 2; i <= n; i++) result[i] = (i - 1) * (result[i - 2] + result[i - 1]);
	cout << result[n];
	return 0;
} 
