#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int s, l;
	void dg(int k, int m) {
		if (k == 0) {
			if (m != 0) {
				
			} else {
				
			}
			return;
		}
		dg(k - 1, 0);
		//dg(k - 1, 1); 
	}
    vector<int> divingBoard(int shorter, int longer, int k) {
		this->s = shorter, this->l = longer;
		dg(k, 0);
    }
};

int main() {
	Solution s = Solution();
	s.divingBoard(1, 2, 3); 
	return 0;
}
