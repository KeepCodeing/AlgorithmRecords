#include <iostream>
#include <vector>
using namespace std;
// ����һ�����飬��[1, 2, 3 ,4, 5],����һ��Ԫ��ֵ��Ҫ��ȥ�������еĸ�Ԫ�ز�
// ����������ĳ��� 
int removeElement(vector<int > arr, int ele) {
	for (vector<int >::iterator it = arr.begin(); it != arr.end(); it++) {
		if (*it == ele) {
			// ȥ����Ԫ�ص�ͬʱ�����鳤��Ҳ��仯���������滹Ҫ��������Լ�����
			// ��ֹԽ�� 
			it = arr.erase(it);
			--it;
		}
	}
	return arr.size();
} 
int main() {
	return 0;
}
