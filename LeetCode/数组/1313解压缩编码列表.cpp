#include <iostream>
#include <vector>
using namespace std;
// ��������Ŀ����˼�ǵ�n�������ֵĴ����ɵ�n+1�����������������黹ԭ 
class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int > result;
        int nLen = nums.size();
        int temp, cnt;
        for (int i = 0; i <= nLen - 2; i += 2) {
        	cnt = nums[i], temp = nums[i + 1];
        	for (int j = 0; j < cnt; j++) result.push_back(temp);
		}
		return result;
    }
};

int main() {
	return 0;
}
