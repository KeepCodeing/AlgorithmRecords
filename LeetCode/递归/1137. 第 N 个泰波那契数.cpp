#include <iostream>
using namespace std;

// ����쳲���������... 

class Solution {
public:
    int tribonacci(int n) {
        int num[40];
        num[0] = 0, num[1] = num[2] = 1;
        for (int i = 3; i <= n; i++) {
        	num[i] = num[i - 3] + num[i - 2] + num[i - 1];
		}
		// LeetCodeֱ��new����ᱨ������ɾ����Ҳ���У����������ø�
		// �������� 
		return num[n];
    }
};
int main() {
	int n;
	cin >> n;
	Solution s = Solution();
	cout << s.tribonacci(n); 
	return 0;
}
