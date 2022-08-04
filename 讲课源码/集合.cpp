#include <iostream>
#include <set>
using namespace std;

struct Node {
	int x;
	bool operator< (const Node& n) const {
		return x < n.x;
	}
	Node(int xv) : x(xv) {};
};

int main() {
	set<int > st;
	// �������Ԫ��ʹ�õ���insert���� 
	for (int i = 1; i <= 10; i++) st.insert(i);
	
	for (int i = 1; i <= 10; i++) st.insert(i);

	// ����ͨ��count()�����ж�ĳ��Ԫ�س��ֵĴ�����
	// ��Ȼ���������ظ��ģ����ֻ�г���0�κ�1���������
	cout << "10�Ƿ���֣�" << st.count(10) << endl;
	
	// �޷�ֱ�ӱ������ϣ���Ҫʹ�õ��������̶�д����
	for (set<int >::iterator it = st.begin(); it != st.end(); ++it) {
		cout << *it << endl;
	}
	
	cout << endl;
	
	// ���Զ����������ͣ�����ṹ�����ȥ�أ���Ҫָ���������
	// ��Ϊset��Ҫ���������������������
	set<Node > nset;
	for (int i = 1; i <= 10; i++) nset.insert(Node(i));
	
	for (set<Node >::iterator it = nset.begin(); it != nset.end(); ++it) {
		cout << (*it).x << endl;
	}
	return 0;
}
