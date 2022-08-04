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
	// 集合添加元素使用的是insert方法 
	for (int i = 1; i <= 10; i++) st.insert(i);
	
	for (int i = 1; i <= 10; i++) st.insert(i);

	// 可以通过count()方法判断某个元素出现的次数，
	// 当然集合是无重复的，因此只有出现0次和1次两种情况
	cout << "10是否出现：" << st.count(10) << endl;
	
	// 无法直接遍历集合，需要使用迭代器（固定写法）
	for (set<int >::iterator it = st.begin(); it != st.end(); ++it) {
		cout << *it << endl;
	}
	
	cout << endl;
	
	// 对自定义数据类型，例如结构体进行去重，需要指定排序规则
	// 因为set需要根据排序规则来进行排序
	set<Node > nset;
	for (int i = 1; i <= 10; i++) nset.insert(Node(i));
	
	for (set<Node >::iterator it = nset.begin(); it != nset.end(); ++it) {
		cout << (*it).x << endl;
	}
	return 0;
}
