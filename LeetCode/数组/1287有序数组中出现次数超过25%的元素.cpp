#include <iostream>
#include <vector>
using namespace std;
// ��������Ŀ˵��һ�������ֵĴ��������������25%��Ҳ���������������������ִ���
// �����������ǿ��Բ���Ħ��ͶƱ��ͳ������Ԫ�ظ��� 
class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
    	// ע����Ŀ���������鳤�ȷ�Χ 
        if (arr.size() == 1) return arr[0];
        int vo = 0, num, aLen = arr.size();
        // ��ʼͶƱ 
        for (int i = 0; i < aLen; i++) {
        	// ���µ�ǰԪ�� 
        	if (vo == 0) {
        		num = arr[i];
			}
			// ����Ʊ�� 
			vo += arr[i] == num ? 1 : -1;
			// �����ǰԪ�ص�Ʊ���Ѿ����������ܳ����ˣ�˵����ǰԪ�ؾ�������Ԫ�� 
			if (vo > aLen * 0.25) break;
		}
		return num;
    }
};
int main() {
	return 0;
}
