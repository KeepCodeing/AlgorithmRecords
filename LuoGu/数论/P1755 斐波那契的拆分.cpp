#include <iostream>
#include <stack>
using namespace std;

// �����Ӧ�þ��ǵ��ű������е���֮ǰ��������ֵ��� 
// ��Ҫע��ĵط������ȷ��쳲��������еķ�Χ���Լ���α�֤ÿ�μ��ٵĶ������ֵ 

long long int fib[100] = {1, 1};
stack<long long int > result;
int main() {
	long long int t, x;
	cin >> t;
	// ��ʼ��쳲��������У���Ϊ����ܻᱬint�����Է�ΧҪ�Ƚ�С 
	for (int i = 2; i <= 45; i++) {
		fib[i] = fib[i - 1] + fib[i - 2];
	}
	while(t--) {
		cin >> x;
		cout << x << '=';
		// �Ӻ���ǰѡ 
		for (int i = 45; i >= 1; i--) {
			// ��ĿҪ���������ģ�����һ�������ܻᱻѡ��Σ����������whileҲ�����
			// �����Ա�֤ÿ�μ��ٵĶ�������ֵ 
			while(x >= fib[i]) result.push(fib[i]), x -= fib[i];
			if (x == 0) break; 
		}
		// ������ 
		while (!result.empty()) {
			// ���һ��Ԫ�غ�û�мӺ� 
			if (result.size() == 1) {
				cout << result.top() << endl;
				result.pop();
				break;
			}
			cout << result.top() << '+';
			result.pop();
		}
		
	}
	return 0;
}
