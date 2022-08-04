#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

// �������ʵ��������BFS�����·���ԣ������Ǵ���ֱ��ö�����п��ܣ���������û�취��¼���·���Ƕ���...
// ��ô���·��������ʵ����ʹ�ò��������٣����������Ǹ�BFS������BFS�����û��д��...������˼·���ȴ��
// ������Ȼ����Ϊÿ��λ�õ����ֶ�ֻ����0~9֮��任������Ҫ��任��Ҳ����������˿���ֱ��ö����Щ���֣�
// Ȼ�������У�����BFS�����·���ԣ���һ�γ��ֵ�Ŀ�����־��ǲ�����̵�������... 

// էһ����ũ�⣬ʵ���Ϻܶ��ظ�����... 

// ������¼�����͵�ǰԪ�ص�pair 
typedef pair<int, int > PII;
const int N = 10000 + 10, M = 1e6 * 5;
bool primes[N], visited[N];
// ���������������ж��²����������Ƿ�������.. 
void getPrimes() {
	primes[0] = primes[1] = true;
	for (int i = 2; i < sqrt(N); i++) {
		if (primes[i]) continue;
		for (int j = i * i; j < N; j += i) {
			primes[j] = true;
		}
	}
}
// ��֪���ж�������������Զ������Կ��ķǳ���.. 
PII que[M];
int bfs(int x, int y) {
	int qtop = 0, qback = 0;
	que[qtop] = PII(x, 0);
	while (qtop <= qback) {
		PII now = que[qtop++];
		if (now.first == y) return now.second;
		// ö�ٸ�λ�ϵ����ֵĿ��ܣ�ע�⽻�����ܲ����ظ�����Ҳ����DFS�����������⣬����Ҫ�ø�visited�����
		for (int i = 0; i <= 9; i++) {
			// ��λ�ϵ�����ֻ������0~9����ô���ǿ����ȰѸ�λ������ȥ���������㣩��Ȼ�����0~9�����־�����
			int temp = now.first;
			// ȥ��ԭ���ĸ�λ���֣������µĸ�λ���� 
			temp = temp - temp % 10 + i; 
			// ����²���������û�б�ʹ�ù���������������ô������־��Ǹ��Ϸ����֣�������Ӽ�����չ... 
			if (!visited[temp] && !primes[temp]) {
				visited[temp] = true;
				que[++qback] = PII(temp, now.second + 1);
			} 
		} 
		// ö��ʮλ���֣�ʵ�ֺ͸�λ��ͬ������Ҳ���
		for (int i = 0; i <= 9; i++) {
			int temp = now.first;
			// ע��ֻ�ܸı�ʮλ�����֣���λ����Ҫ��ԭ 
			temp = temp - temp % 100 + temp % 10 + i * 10;
			if (!visited[temp] && !primes[temp]) {
				visited[temp] = true;
				que[++qback] = PII(temp, now.second + 1);
			}
		} 
		// ö�ٰ�λ������ 
		for (int i = 0; i <= 9; i++) {
			int temp = now.first;
			temp = temp - temp % 1000 + temp % 100 + i * 100;
			if (!visited[temp] && !primes[temp]) {
				visited[temp] = true;
				que[++qback] = PII(temp, now.second + 1);
			}
		}
		// ö��ǧλ�����֣�ע��ǧλ�����ֲ��ܴ�0��ʼ 
		for (int i = 1; i <= 9; i++) {
			int temp = now.first;
			temp = i * 1000 + temp % 1000;
			if (!visited[temp] && !primes[temp]) {
				visited[temp] = true;
				que[++qback] = PII(temp, now.second + 1);
			}
		} 
	}
	return -1;
}
int main() {
	getPrimes();
	int T, x, y, res;
	cin >> T;
	while (T--) {
		cin >> x >> y;
		// ע�����÷�������... 
		memset(visited, 0, sizeof visited);
		res = bfs(x, y);
		if (res == -1) cout << "Impossible" << endl;
		else cout << res << endl;
	}
	return 0;
} 
