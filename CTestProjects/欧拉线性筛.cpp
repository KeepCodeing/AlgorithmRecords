#include <iostream>
using namespace std;

// �����ڰ���ɸ��ŷ��ɸ��Ч�ʽӽ���O(n)�����ǰ���ɸ�Ļ��������±���Ԫ���Ƿ�������

// ���̣���ʵŷ��ɸ�ı������Ҳ������������Ч��������һ��result��ʵ��������е�����
// ���������Ļ�û�취��������Ч������Ϊ�������±�ȡ�� 

int main() {
	// cnt������������ 
	int n, cnt = 0;
	int *result, *visited;
	cin >> n;
	result = new int[n + 1]();
	visited = new int[n + 1]();
	// visited������ǵ�ǰ���Ƿ������� 
	for (int i = 2; i <= n; i++) {
		if (!visited[i]) {
			result[cnt++] = i;
		}
		for (int j = 0; j < cnt; j++) {
			// ��ֹ��ǳ��磬��Ϊĳ�����ı������ܴ���n 
			if (i * result[j] > n) break;
			// �����ǰ����i�ı�����˵����������������Ϊ���� 
			visited[i * result[j]] = true;
			// �����ǰ����������ĳ��������ͬ��˵��������Ϊ������������
			// ʡȥ���ظ����ʵ�ѡ�� 
			if (i % result[j] == 0) break;
		}
	}
	for (int i = 0; i < n; i++) {
		if (!visited[i]) cout << i << endl;
	}
	delete[] visited;
	delete[] result;
	return 0;
}
