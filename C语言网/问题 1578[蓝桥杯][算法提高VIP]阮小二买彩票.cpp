#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// ��������ǰ�û���д�ģ�pre���������һ��dfs�ڵı�����������һ��
// ����...�������˰�... 

vector<int > vec;
int main() {
	int num;
	cin >> num;
	while (num) {
		vec.push_back(num % 10);
		num /= 10; 
	}
	sort(vec.begin(), vec.end());
	do {
		for (int i = 0; i < vec.size(); i++) cout << vec[i];
		cout << endl;
		// next_permutation()�����������ɺϷ������ظ�Ԫ�ص�ȫ���� 
	} while(next_permutation(vec.begin(), vec.end()));
	return 0;
}
