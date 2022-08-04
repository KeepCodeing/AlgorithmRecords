#include <iostream>
using namespace std;

// ������ģ����ȴ����WA�����Σ����ܣ�
// ���һ�������һ����ѡ��j������ǰ����������ô���������ʹ��ǰj-1��Ԫ�صĺ��������
// ״̬ת�Ʒ��̾���f[i] = max{f[i - 1] + nums[i]}�������������״̬ת�Ʒ�����������ģ�����Ҫ��ǰj-1��Ԫ�غ����
// Ҳ����Ҫ��֤����nums[i]����ʹ���ܺ͸�С��Ҳ��������С��0����������ȷ��״̬ת�Ʒ���Ӧ����f[i] = max{nums[i], f[i - 1] + nums[i]}
// so...���ǱȽ���w����֮��󼸱������е��ŵ��ˣ����ǻ��ǲ����Լ��Ƴ���ȷ�ķ��̣�����д��������֮���...��Ҫ�ǳ�ʼ��
// ��״̬ת�Ʒ��̵�����... 

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int nLen = nums.size();
        if (nLen == 1) return nums[0];
        int f[nLen + 10], res = -0x3fffffff;
        f[0] = nums[0];
        for (int i = 1; i < nLen; i++) {
            f[i] = max(nums[i], f[i - 1] + nums[i]);
            res = max(res, f[i]);
        }
        // for (int i = 0; i < nLen; i++) res = max(res, f[i]);
        return res;
    }
};

int main() {
	return 0;
}
