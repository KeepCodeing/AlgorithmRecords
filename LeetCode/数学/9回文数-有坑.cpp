#include <iostream>
#include <algorithm>
using namespace std;
// ������������ѧ���⣬�пӣ����縺�������������� 

class Solution {
public:
    bool isPalindrome(int x) {
    	// ��ֹ0�� 
    	if (x == 0) return true;
    	// �����������Ƕ����������Ը���һ������ 
    	if (x < 0) return false;
        // int r = 0, t = x;
        // ֱ�ӷ�ת���ܻ���ֳ���int���ݷ�Χ����� 
        // ��ת���ַ����Աȣ����ܣ� 
        int t = x;
        string r1, r2;
        while (t) {
        	r1 += (char)((t % 10) + '0');
        	t /= 10;
		}
		r2 = r1;
		reverse(r1.begin(), r1.end());
		return r1 == r2;
    }
};
int main() {
	Solution s = Solution();
	cout << s.isPalindrome(111); 
	return 0;
}
