#include <iostream>
#include <cmath>
using namespace std;
// �����㷨ʱ�临�Ӷ�����sqrt�㷨 ��Ȼ������û�п��Ǳ���ʱ�������£� 
int get_result(int num) {
	int flag, r1 = 0, r2;
	for (int n = 2; n <= num; n++) {
		flag = 1;
		for (int i = 2; i < n; i++) {
			if (n % i == 0) {
				flag = 0;
				break;
			}
		}
		if (flag) {
			if (num % n == 0) {
				r1 = n;
			}
			if (r1 != 0 && r1 * n == num) {
				r2 = n;
			}
		}
	}
	return max(r1, r2);
}
int get_result2(int num) {
	int r1 = 0, r2 = 0;
	for (int n = 2; n <= num; n++) {
		int k = (int)sqrt((double)n);
		int i;
		for (i = 2; i <= k; i++) {
			if (n % i == 0) break;	
		}
		if (i >= k + 1) {
			if (num % n == 0) r1 = n;
			if (r1 != 0 && r1 * n == num) r2 = n;
			
		}
	}
	return max(r1, r2);
}
// ���������㷨���޷�ͨ���������ϴ�Ĳ��ԣ�ֻ����ŷ��ɸ�ķ�ʽ��
bool *visited;
int prime_cnt = 0, *primes;

void ol(int num) {
	for (int i = 2; i <= num; i++) {
		if (visited[i] == false) primes[prime_cnt++] = i;
		for (int j = 0; j < prime_cnt; j++) {
			if (i * primes[j] > num) break;
			visited[i * primes[j]] = true;
			if (i % primes[j] == 0) break;
		}
	}
}

int ret_result(int num) {
	for (int i = 0; i < prime_cnt; i++) {
		if (num % primes[i] == 0) return max(primes[i], num / primes[i]);
	}
}

int main() {
	long long num;
	cin >> num;
	// ��ŷ��ɸҲ��׹�٣���Ϊ����̫��ʱ�������磬������Ŀ˵
	// ֻ���������������Կ����ȱ�������һ������������ԭ��ȥ������ 
	// 24331680983
	for (long long i = 2; i <= num; i++) {
		if (num % i == 0) {
			cout << num / i;
			return 0;
		}
	}
} 
