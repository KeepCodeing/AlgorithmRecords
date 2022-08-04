#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 排序水题，虽然排名非常低，但是这个是今天第一个一次AC的题...
// 思路就是把组数和下标存起来，然后既然存在解，可以模拟分组的过程，将原数组按照组数排序后，
// 将相连的cnt个元素的下标存起来，跑完就分组完了 

class Solution {
typedef pair<int, int > PII;
public:
	vector<vector<int> > res;
    vector<vector<int> > groupThePeople(vector<int>& groupSizes) {
        int gLen = groupSizes.size();
        vector<PII > temp;
		vector<int > rtemp;
		// 按组数排序，然后把cnt个相同组数的人分组，因为一定存在解，所以这是可行的w 
        for (int i = 0; i < gLen; i++) temp.push_back(PII(groupSizes[i], i));
        sort(temp.begin(), temp.end());
		int cnt, tLen = temp.size();
		for (int i = 0; i < tLen; i++) {
			cnt = temp[i].first;
			while (cnt--) {
				rtemp.push_back(temp[i].second);
				i++; 
			}
			// 注意这里的i--，是为了循环里的i++，因为while里已经做了for里的i++了 
            i--;
			res.push_back(rtemp); 
            rtemp.clear();
		}
		return res;
    }
};


int main() {
	return 0;
}
