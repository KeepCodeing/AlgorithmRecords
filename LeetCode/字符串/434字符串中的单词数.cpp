#include <iostream>
using namespace std;
// �������жϵ�ǰ�ַ���Ϊ�ո����ǰ�Ǹ����ʣ��ж���һ���ַ�Ϊ�ո�������Ѿ����� 
class Solution {
public:
    int countSegments(string s) {
       	int cnt = 0;
       	// �Ӹ��ո���Ϊ�˷�ֹ©�����һ������ 
       	s += ' ';
        for (int i = 0; i < s.size() - 1; i++) {
       		if (s[i] != ' ' && s[i + 1] == ' ') cnt++;
	   	}
        return cnt;
    }
};
int main() {
	string s = "Hello, my name is John";

	return 0;
}
