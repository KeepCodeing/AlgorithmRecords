#include <iostream>
#include <vector>
using namespace std;

// �����Լ��󲿷��������Ӧ�ö����ˣ����ڿ�ʼ��DP��˵�����������ô�ñ���Ҳ���Ǻ��ɵ����ӣ�ͼ�ۣ�����֮�����
// ����д��ģ��ͻ���...���뿼���Լ����ڻ��˶������㷨�������ͱ�five����������260����Ӧ���Ѿ�������...

// ������Ȼ˵��dp��ǩ������ʵ���Ͽ�����ǰ׺������... 

class NumArray {
public:
	vector<int > vec;
    NumArray(vector<int>& nums) {
    	int nLen = nums.size();
    	if (nums.empty()) return;
    	// resize()����ָ����С�⻹��Ҫָ����ʼֵ��������LeetCode��������ϻ�RE 
        vec.resize(nLen + 10, 0);
		vec[0] = 0;
		for (int i = 1; i <= nLen; i++) {
			vec[i] = vec[i - 1] + nums[i - 1];
		} 
    }
    int sumRange(int i, int j) {
    	// ǰ׺���±�һֱû�����.. 
		return vec[j + 1] - vec[i];
    }
};
int main() {
	return 0;
}
