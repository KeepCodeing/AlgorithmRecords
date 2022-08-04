#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// ���������������󣬶�������Ҫ��������٣�������ȫ���Ա����� 
class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
    	vector<int > result;
        for (int i = 1; i <= 9; i++) {
        	int num = i;
        	for (int j = i + 1; j <= 9; j++) {
        		// ����֮ǰд����num = i * 10 + j... 
        		num = num*10 + j;
        		if (num >= low && num <= high) result.push_back(num); 
			}
		}
		sort(result.begin(), result.end());
		return result;
    }
};

int main() {
	Solution s = Solution();
	s.sequentialDigits(100, 300); 
	return 0;
}
