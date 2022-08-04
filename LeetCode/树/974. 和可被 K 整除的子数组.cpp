#include <iostream>
using namespace std;

// ����Ҫ�����ͬ�ඨ�������ж�(A - B) % K == 0����д�� A % K == B % K����ô�������õ����������
// һ�ۿ��Կ�������ǰ׺�ͣ�����ö���������Ǹ�O(n^2)�Ĳ��������ǻص��˱����ϣ��������ַ����ǲ����еġ�
// ��������Ķ��������赱ǰǰ׺��ΪA��������ĺ�ΪB���������A % K == B % K����˵�����������ĺ�
// �ǿ�������K�ģ���������B��δ֪�������Ե��ø�HashTable����¼֮ǰ����ǰ׺�͵�ģ��������Ҫע�⽫HashTable
// ��0�������Ԫ����Ϊ0�������е�ǰ�����ǰ׺�Ϳ�������K�� 

class Solution {
public:
    map<int, int > rec;
    int subarraysDivByK(vector<int>& A, int K) {
        int preSum = 0, res = 0;
        // ��ʼ����ǰ�����ǰ׺�Ϳ�������K����� 
        rec[0] = 1;
        for (auto& i : A) {
        	// ����ǰ׺�� 
            preSum += i;
            // ע��C++ȡģ������õ���������������ü���K���� 
            int mod = (preSum % K + K) % K; // ���� A % K������
			// �������B % K��������A % K��������ȣ������ж��ٸ����������� 
            if (rec.count(mod)) {
                res += rec[mod];
            }
            // ���B % K������ 
            rec[mod]++;
        }
        return res;
    }
};

int main() {

	return 0;
}
