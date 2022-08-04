#include <iostream>
#include <vector>
using namespace std;
// ���������ǿ�������󷵻�arr.size()/2����Ԫ�أ���Ԫ��һ������������������Ч��̫�͡�
// ͬ�������ǿ�����HashTable��������������Ҫ����ռ䡣���׷�����Ч�ʵĻ������Ǿ���Ҫ
// �õ�Boyer-Moore ͶƱ�㷨�����㷨�ĺ���˼�������һ���������жϵ�ǰԪ�صĳ��ִ���
// ������ͬԪ�ؼ�����-1����֮+1�����������Ϊ0�ˣ�˵����ǰԪ�ز�����������ʱ���ǿ���
// "����"֮ǰ����������һ���µ���������Ϊ������ȥ����ͬ�����ķ����������������ԶԽ��
// ��������Ӱ��
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0, result;
        int nLen = nums.size();
        for (int i = 0; i < nLen; i++) {
        	// ���µ�ǰ���� 
        	if (cnt == 0) result = nums[i];
        	// ���¼����� 
			cnt += nums[i] == result ? 1 : -1;
		}
		return result;
    }
}; 
int main() {
	return 0;
}
