#include <iostream>
using namespace std;

// ������ŷ��ɸ�Ͱ���ɸ��Ч�����⣺��n = 10^6ʱ������ɸ����࣬����ɸ����
// ��n = 10^7ʱ��ŷ��ɸ���ԱȰ���ɸ��һ������ 

int main() {
	// 1 1 2 3 5 8 13 21
	int n;
	cin >> n;
	bool flag = false;
	cout << n << '=';
	// �Ż�i <= n / i�����Ż�����n�����������԰�ʱ�临�ӶȽ���logn������n�������޷���ѭ���������������������
	// ��Ҫ�ж�������Ƿ񱻳����� 
	for (int i = 2; i <= n / i; i++) {
		while (!(n % i)) {
			if (!flag) cout << i;
			else cout << '*' << i;
			n /= i;
			flag = true;
		}
	}
	// ����������һ���ϴ�������� 
	if (n > 1) cout << n; 
	return 0;
}

//#include <iostream>
//using namespace std;
//
//// �ǵø���ˢC�������ʱ��ˢ�������⣬����ȫȫ�Ĳ�������ˣ����ܣ���
//// ���ڲ�֪����ν�����Ӿ���ָĳһ�����������������ɸ������ĳ˻����
//// ����8 = 2*2*2... 
//
//// ����дһ������ɸ�汾�ģ��������˼�ģ�������������...
//
//const int N = 1000010;
//
//int head = -1, idx = 0, e[N], ex[N];
//void add_to_head(int x) {
//	e[idx] = x;
//	ex[idx] = head;
//	head = idx++;
//}
//// ���õĺ�����ֻ��Ϊ�����Լ�fuxi�µ�˫�������� 
//void add(int k, int x) {
//	e[idx] = x;
//	ex[idx] = ex[k];
//	ex[k] = idx++;
//}
////void add2(int k, int x) {
////	e[idx] = x;
////	l[e] = k;
////	r[e] = r[k];
////	l[r[k]] = idx;
////	r[k] = idx;
////}
//
////bool primes[N];
////void getPrimes() {
////	primes[0] = primes[1] = true;
////	for (int i = 2; i <= 1000010; i++) {
////		if (primes[i]) continue;
////		add_to_head(i);
////		for (int j = i * 2; j <= 1000010; j += i) {
////			primes[j] = true;
////		}
////	}
////}
//
//int main() {
//	// getPrimes();
//	int n;
//	ios::sync_with_stdio(false);
//	cin.tie(0); 
//	
//	
//// �����̣�ͷ��ӵ������Ȼ�Ƿ������ģ����ӣ�����������ʵʵ������ 
////	int cnt = 0;
//
////	while (head != -1) {
////		cout << e[head] << endl;
////		head = ex[head];
////		if (cnt > 20) break;
////		cnt++;
////	}
//	return 0;
//} 
