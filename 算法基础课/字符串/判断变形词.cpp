#include <iostream>
using namespace std;
// ���������ַ�����:here you are��are you here ���ж������Ƿ��Ǳ��δʣ��ַ�������ͬ�����������ո� 
// ˼·��1. ����STL�����������ж��Ƿ���ȣ��������ܼ򵥣�����Ч�ʲ���
// 2. ����һ���������飬Ч�ʸ��� 
// ����˼���Ǽ��������˼�� 
int main() { 
	string a = "here you are";
	string b = "are you here";
	if (a.size() != b.size()) cout << "can not!" << endl;
	// ʹ���ַ���ASCII����Ϊ����������±꣬ע������ĳ�ʼ����ʽ 
	int *temp = new int[a.size()]();
	
	for (int i = 0; i < a.size(); i++) {
		if (a[i] == ' ') continue;
		temp[(int)a[i]] += 1;
	}
	
	for (int i = 0; i < b.size(); i++) {
		if (b[i] == ' ') continue;
		if (temp[(int)b[i]] < 0) {
			cout << "can not!" << endl;
			break;
		}
		temp[(int)b[i]] -= 1;
	}
	
	delete[] temp; 
	return 0;
}
