#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void printPermutation(vector<int >& r) {
	for (int i = 0; i < r.size(); i++) cout << r[i] << ' ';
		cout << endl;
}
int main() {
	vector<int > r;
	r.push_back(1);
	r.push_back(2);
	r.push_back(3);
	// ʹ��bool next_permutation()�������԰��ֵ���һ������һ��ȫ���У����
	// ����ȫ���У��ͻ᷵��true�����򷵻�false�����Զ���Ҫ��ס���ɵ�˳��һ��
	// �Ǵ�С������Ҫ�������Ƚ���һ������ÿ������ú������Ὣ������µ�
	// ԭ���� 
	sort(r.begin(), r.end()); 
	// ������whileѭ����ֱ�ӽ�������������Ҫ�ύ���һ��ԭ���� 
	printPermutation(r);
	while(next_permutation(r.begin(), r.end())) {
		printPermutation(r);
	}
	return 0;
}
