#include <iostream>
#include <cstdio>
using namespace std;

// ջ��Ӧ�� 
// �ݣ���Ŀ��������ַ���string��ȡ���ܣ����������ĽⷨҲ�ȽϺ� 
// RE������ԭ��ջΪ�յ���Ȼ�Ƿ���ȡ��ɾ�� 
/*else if (c == ')') {
			if (!s.empty() && s.size() > 0) {
				if (s.top() != '(') {
					flag = false;
					break;
				}
			}
			if (!s.empty() && s.size() > 0) s.pop();
		}*/
		
// �������أ����� 
int main() {
	char c;
	// ���ü��� 
	int left = 0, right = 0;
	while ((c = getchar()) != '@') {
		if (c == '(') {
			left++; 
		} else if (c == ')') {
			right++;
		}
		if (right > left) {
			cout << "NO";
			return 0;
		} 
	}
	// ���ж���һ�㣬��������Ŷ��������ţ����о���
	// û�������ŵ���� 
	cout << (left == right ? "YES" : "NO");
	return 0;
}
