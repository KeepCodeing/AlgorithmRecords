#include <iostream>
#include <vector>
using namespace std;
// 分析：题目给出了数据范围，所以直接判断数字是否处于偶数位范围内即可 
class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count=0;
        for(int i=0;i<nums.size();++i){
            if((nums[i]>=10&&nums[i]<100)||(nums[i]>=1000&&nums[i]<10000))
                count++;
        }
        return count; 
    }
};
int main() {
	return 0;
}
