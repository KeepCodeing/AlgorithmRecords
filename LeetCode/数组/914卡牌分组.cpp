#include <iostream>
#include <map>
#include <vector>
using namespace std;
// 分析：求每种元素出现个数的最大公约数即可，公约数大于等于2说明可以分组 
class Solution {
public:
	int gcd(int m, int n) {
		if (m % n == 0) return n;
		return gcd(n, m % n);
	}
    bool hasGroupsSizeX(vector<int>& deck) {
    	map<int, int > m;
        for (int i = 0; i < deck.size(); i++) {
        	// 统计元素个数 
        	m[deck[i]]++;
		}
		int gcd = -1;
		for (map<int, int >::iterator it = m.begin(); it != m.end(); it++) {
			// 计算公约数 
			gcd = gcd == -1 ? it->second : this->gcd(gcd, it->second);
		}
		return gcd >= 2;
    }
};
int main() {
	return 0;
}
