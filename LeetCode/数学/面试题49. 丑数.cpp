#include <iostream>
using namespace std;

// �������ݷ�Χ��С������ö�پ�������... 

// ��ʱ��...������ܹ�ǰ300����... 

class Solution {
public:
	bool checker(int i) {
		return i != 2 && i != 3 && i != 5;
	}
    int nthUglyNumber(int n) {
    	int cnt = 1, num;
    	bool flag;
    	for (num = 2; cnt < n; num++) {
    		int t = num;
    		flag = true;
			for (int i = 2; i <= t / i; i++) {
				// ������д����if��ʵ�����Գ�����Լ�������������������������... 
				while (!(t % i)) {
					if (checker(i)) {
						flag = false;
						break;
					}
					t /= i;
				}
			} 
			if (t > 1 && checker(t)) flag = false; 
			if (flag) cnt++;
		}
		return num - 1;
    }
};
int main() {
	int n;
	cin >> n;
	Solution s = Solution();
	cout << s.nthUglyNumber(n);  
	// �Գ�����Լ�������Ӷ�O(logn) 
//	for (int i = 2; i <= n / i; i++) {
//		if (!(n % i)) {
//			cout << i << endl;
//			if (n / i != i) cout << n / i << endl;
//		}
//	}
	// if (n > 1) cout << n;
	// �۲����ݺ�����ν��������ʵ��������...������8����������2*2*2����������2*4���������...
	// �Գ�����������
//	for (int i = 2; i <= n / i; i++) {
//		while (!(n % i)) {
//			cout << i << ' ';
//			n /= i;
//		}
//	} 
//	if (n > 1) cout << n << endl;
	return 0;
}
