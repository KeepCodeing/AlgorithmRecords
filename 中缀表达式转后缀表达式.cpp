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
中缀转后缀过程

1+((2+3)×4)-5

与转换为前缀表达式相似，遵循以下步骤：
(1) 初始化两个栈：运算符栈S1和储存中间结果的栈S2；
(2) 从左至右扫描中缀表达式；


(3) 遇到操作数时，将其压入S2；


(4) 遇到运算符时，比较其与S1栈顶运算符的优先级：
(4-1) 如果S1为空，或栈顶运算符为左括号“(”，则直接将此运算符入栈；
(4-2) 比栈顶高，也将运算符压入S1         （注意转换为前缀表达式时是优先级较高或相同，而这里则不包括相同的情况）；
(4-3) 比栈顶低或相同，将S1栈顶的运算符弹出并压入到S2中，再次转到(4-1)与S1中新的栈顶运算符相比较；


(5) 遇到括号时：
(5-1) 如果是左括号“(”，则直接压入S1；
(5-2) 如果是右括号“)”，则依次弹出S1栈顶的运算符，并压入S2，直到遇到左括号为止，此时将这一对括号丢弃；

                                                                     可以想象成“（”比任何运算符都高，“）”比任何运算符都低 。


(6) 重复步骤(2)至(5)，直到表达式的最右边；


(7) 将S1中剩余的运算符依次弹出并压入S2；


(8) 依次弹出S2中的元素并输出，结果的逆序即为中缀表达式对应的后缀表达式（转换为前缀表达式时不用逆序）。
*/
