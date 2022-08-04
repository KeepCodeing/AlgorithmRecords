#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// �������ƺ�����ao����ˣ�����������ûʲôӡ��..
// ���������һ�������һ����ѡ���Ԫ��һ����j���λ�õ�Ԫ�أ���ô���ֳ�����������ǵ�����ѡ��j��Ԫ��ʱ��
// j-1λ�õ�Ԫ��һ����С��/���ڵ�j��λ�õ�Ԫ�ء�
// ����������״̬ת�Ʒ��̣�������f(j)=ѡ��j��Ԫ�ص�������У���ôf(j) = max{f(j-1)+1}������f[j-1]��С��/
// ����f[j]��
// ��ʼֵ�ͱ߽��ѡ��������f[0] = 0����һ��Ԫ�ض���ѡ��������еĳ��Ⱦ�Ϊ0���߽粻���� 

// �����˼·����һЩ����
// �����Ǵ���/С����飬��һ��ʼ����������飬Ȼ��������ֱ����ת�������飬���������ǵ����������ǵ����½�����������
// f[i - 1] < f[i]���жϡ��������/С����ָ����5 4 3 2 1���������ݣ���������������еĻ�����Ͳ���ֱ����ģ���ˡ�
// ������Ƕ�̬ת�Ʒ����ˣ��仹������ģ������д�˸�max{f(i - 1) + 1, f(i)}�����ǿ����������˼��f[i]�ĳ��Ⱦ���f[i - 1] + 1
// ���о��ǳ�ʼֵ���趨�������˸�f[0] = 0����˼�ǲ�ѡԪ�����г�Ϊ0�����������ƺ���û��ʲô�á�����ÿ��Ԫ���Լ����
// �����������о���������������ȷ�ĳ�ʼֵ����Ӧ����f[i] = 1... 

// ��������w����ʵ��five��Ϊ��������û���⣬ֻ�����̳�û�����... 

class Solution {
public:
    /**
     * @param A: An array of Integer
     * @return: an integer
     */
    int cal(vector<int >& A) {
    	int res = -1, aLen = A.size();
    	int f[aLen + 10];
    	for (int i = 0; i < aLen; i++) {
    		// ÿ��Ԫ�صĳ�ʼ���Ⱦ������Լ� 
			f[i] = 1;
			// ״̬ת�Ʒ��� 
			if (i > 0 && A[i] >= A[i - 1]) f[i] = f[i - 1] + 1;
		}
	    for (int i = 0; i < aLen; i++) res = max(res, f[i]);
		return res;
	}
    int longestIncreasingContinuousSubsequence(vector<int> &A) {
        // write your code here
        int aLen = A.size();
        if (!aLen) return 0;
        // ������һ�飬������һ�飬�����Ϳ��԰��������������������ж��㵽 
		int t1 = cal(A), res = -1;
		reverseVec(A);
		res = max(t1, cal(A));
		return res;
    }
    void reverseVec(vector<int >& A) {
    	int l = 0, r = A.size() - 1;
    	while (l < r) swap(A[l++], A[r--]);
	}
};
/*
f[0] = 0;
int vLen = vec.size();
for (int i = 1; i < vLen; i++) {
for (int j = 1; j < i; j++ {
	f[j] = max(f[j], f[j - 1] + 1)
}
	if (vec[i - 1] < vec[i]) f[i] = max(f[i], f[i - 1] + 1);
}
*/
int main() {
	return 0;
}
