#include <iostream>
#include <vector>
using namespace std;

// ��Ϊ����ֻ�����һ���״̬ת�Ʒ���
// ���ȿ������һ�������һ��ѡ���Ԫ��һ���ǵ�i��λ�õ�Ԫ�أ�����Ϊ����ѡ�����ڵ�Ԫ�أ�������������
// i - 2
// ��ô���ǵ�״̬ת�Ʒ��̾�Ӧ����f[i] = max{f[i - 2] + nums[i], f[i - 1]}���������û�������ѡ�������
// ��ô�жϣ���ѡ��������ǵ�ǰ�����������ϴε��������...
// ���������ĳ�ʼ����Ҳ�����⣬��������ֻ��һ��Ԫ�ص���������������������Ԫ�أ�������������Ԫ�ص����
// �������������������Ԫ�ص����ֵ���ɴˣ�f[0] = nums[0], f[1] = max(nums[0], nums[1])�������Ϳ��ԶԸ�
// ����˵�������..�����о����±꣬���ԣ���1��ʼ����0��ʼ���������... 

class Solution {
public:
    int massage(vector<int>& nums) {
		int nLen = nums.size();
		if (nLen == 0) return 0;
		if (nLen == 1) return nums[0];
		int f[nLen + 10];
		f[0] = nums[0];
		f[1] = max(nums[0], nums[1]);
		for (int i = 2; i < nLen; i++) 
			f[i] = max(f[i - 1], f[i - 2] + nums[i]);
		return f[nLen];
    } 
}; 

int main() {
	return 0;
}
