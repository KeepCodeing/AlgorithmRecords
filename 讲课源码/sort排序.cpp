#include <iostream>
// sort�����������ڴ�ͷ�ļ���
#include <algorithm>
using namespace std;

bool cmp(int a, int b) { return a > b; }

struct Node {
	int x;
	bool operator< (Node n) const {
		return n.x < x;
	}
};

int main() {
	int arr[6] = { 4, 24, 1, 6, 5, 13 };
	Node ns[3];
	for (int i = 0; i < 3; i++) ns[i].x = i;
    // ������ʼ��ĩβ���ã��Ὣ��������ڵ�����������
	sort(arr, arr + 6);
	for (int i = 0; i < 6; i++) cout << arr[i] << ' ';
	cout << endl;
	
	// �Զ���������򣬽������� 
	sort(arr, arr + 6, cmp);
    for (int i = 0; i < 6; i++) cout << arr[i] << ' ';
    cout << endl;
    
    // ����ṹ�壬��Ҫ������������� 
    sort(ns, ns + 3);
    
	return 0;
}
