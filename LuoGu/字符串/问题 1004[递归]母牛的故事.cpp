#include <iostream>
using namespace std;

// ����ҹ��ɽ���򵽵�һ��δ֪���ֵ����ˣ�������ʵҲ���Դ���֪�ı�����
// ��ֻ�Ǹ�fib�ı��ΰ��� 

long long nums[60];
int main() {
	nums[1] = 1, nums[2] = 2, nums[3] = 3, nums[4] = 4;
	for (int i = 5; i <= 55; i++) nums[i] = nums[i - 1] + nums[i - 3];
	int n;
	do {
		cin >> n;
		// û���ж�0ȫWA��������Ϊ0��������ģ����ܣ� 
		if (n) cout << nums[n] << endl;
	} while(n);
	return 0;
} 
