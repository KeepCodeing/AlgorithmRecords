#include <iostream>
using namespace std;
// ������������ÿλ���뼴�� 
class Solution {
public:
    int subtractProductAndSum(int n) {
    	int nSum = 0, nCen = 1;    
    	int temp;
    	while (n) {
    		temp = n % 10;
    		nSum += temp, nCen *= temp;
    		n /= 10;
		}
		return nCen - nSum;
    }
};

int main() {
	return 0;
}
