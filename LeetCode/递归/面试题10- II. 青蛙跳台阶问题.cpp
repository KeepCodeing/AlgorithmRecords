#include <iostream>
using namespace std;

class Solution {
public:
	int result[110];
    int numWays(int n) {
    	if (n <= 1) return 1;
    	if (n == 2) return 2;
    	if (result[n]) return result[n];
    	result[n] = (numWays(n - 1) + numWays(n - 2)) % 1000000007;
    	return result[n];
    }
};

int main() {
	int n;
	cin >> n;
	Solution s = Solution();
	cout << s.numWays(n); 
	return 0;
}
