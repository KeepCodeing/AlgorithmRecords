#include <iostream>
using namespace std;
// 分析：将数字每位分离即可 
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
