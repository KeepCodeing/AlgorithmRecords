#include <iostream>
#include <vector>
using namespace std;
// ��������Ŀ���������ݷ�Χ������ֱ���ж������Ƿ���ż��λ��Χ�ڼ��� 
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
