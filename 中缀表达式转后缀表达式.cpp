#include <iostream>
#include <stack> 
#define endl '\n'
using namespace std;
stack<char > s1;
stack<string > s2;

bool isOperator(char op) {
	return op == '+' || op == '-' || op == '*' || op == '/';
} 

bool isKuohao(char op) {
	return op == '(' || op == ')';
}

bool isHigher(char op1, char op2) {
	return op1 > op2;
}

int str2num(string num) {
	int res = 0;
	for (int i = 0; i < num.size(); i++) {
		res = res * 10 + (num[i] - '0');
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	string str, numTemp;
	cin >> str;
	str += "$";
	for (int i = 0; i < str.size(); i++) {
		if (!isOperator(str[i])) {
			numTemp += str[i];
		} else {
			if (str[i] == '$') continue;
			s2.push(numTemp); 
			numTemp = "";
			if (isOperator(str[i])) {
				if (s1.empty() || str[i] == '(') s1.push(str[i]);
				else if (isHigher(str[i], s1.top())) s1.push(str[i]);
				else while(isHigher(str[i], s1.top())) s2.push(s1.top() + ""), s1.pop();
			} else if (isKuohao(str[i])) {
				
			}
		}
	}	
	return 0;
}

/*
��׺ת��׺����

1+((2+3)��4)-5

��ת��Ϊǰ׺���ʽ���ƣ���ѭ���²��裺
(1) ��ʼ������ջ�������ջS1�ʹ����м�����ջS2��
(2) ��������ɨ����׺���ʽ��


(3) ����������ʱ������ѹ��S2��


(4) ���������ʱ���Ƚ�����S1ջ������������ȼ���
(4-1) ���S1Ϊ�գ���ջ�������Ϊ�����š�(������ֱ�ӽ����������ջ��
(4-2) ��ջ���ߣ�Ҳ�������ѹ��S1         ��ע��ת��Ϊǰ׺���ʽʱ�����ȼ��ϸ߻���ͬ���������򲻰�����ͬ���������
(4-3) ��ջ���ͻ���ͬ����S1ջ���������������ѹ�뵽S2�У��ٴ�ת��(4-1)��S1���µ�ջ���������Ƚϣ�


(5) ��������ʱ��
(5-1) ����������š�(������ֱ��ѹ��S1��
(5-2) ����������š�)���������ε���S1ջ�������������ѹ��S2��ֱ������������Ϊֹ����ʱ����һ�����Ŷ�����

                                                                     ��������ɡ��������κ���������ߣ����������κ���������� ��


(6) �ظ�����(2)��(5)��ֱ�����ʽ�����ұߣ�


(7) ��S1��ʣ�����������ε�����ѹ��S2��


(8) ���ε���S2�е�Ԫ�ز���������������Ϊ��׺���ʽ��Ӧ�ĺ�׺���ʽ��ת��Ϊǰ׺���ʽʱ�������򣩡�
*/
