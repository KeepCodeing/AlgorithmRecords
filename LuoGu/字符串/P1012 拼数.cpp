#include <iostream>
#include <algorithm>
using namespace std;

// ��������Ǹ����������⣬��Ҫ�ǶԱ�ASCII��Ȼ������ 

// �ṩ�����㷨 
bool cmp(string a, string b) {
	// �Զ�������������һ���ǳ��������a=321��b=32��a+b=32132��b+a=32321������
	// ��sort����������32>321�������32132>32321�����
	return a + b > b + a;
}

int main() {
	int n;
	string *arr;
	cin >> n;
	arr = new string[n];
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n, cmp);
	for (int i = 0; i < n; i++) cout << arr[i];
	delete[] arr;
	return 0;
}
