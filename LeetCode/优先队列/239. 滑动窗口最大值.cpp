#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int >& nums, int k) {
    	vector<int > res;
		if (nums.empty()) return res;
		int nLen = nums.size();
		priority_queue<int > que;
		for (int i = 0; i < nLen; i++) {
			que.push(nums[i]);
			if (que.size() >= k) {
				cout << que.top();
				
			} 
		}
    }
};

int main() {
	return 0;
}
