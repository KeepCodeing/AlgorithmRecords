#include <iostream>
#include <map>
#include <vector>
using namespace std;

// 这个题看起来很像并查集，因为存在一个找祖宗的过程，不知道是不是对的 
// 花了下图确实是个并查集，另外要注意下怎么判断一共有多少干员。从图里
// 看的话图最低部就是一个单独节点，也就是说如果某个干员的初始名字只出现过
// 一次，那这个名字就是干员的初始名字 

// 这里考虑用一个map映射干员名和id

// 突然觉得可以用map无限映射... 

// 测试的数组链表，不知道可不可行，但是写法上应该是没问题的（虚心） 
// 坠毁，图论方面也忘得差不多了，不过不常写而且写起来比较麻烦也没办法（无能） 
const int M = 1000;
struct Node {
	string str;
	int id;
	Node(string str, int id) : str(str), id(id) {};
	//Node () {};
	Node (int i = -1) {
		id = i;
	}
};
Node head[M], e[M], ex[M];
int idx = 0;
void head_add(int id, string str) {
	e[idx] = Node(str, id), ex[idx] = head[id], head[id] = Node("114514", idx), idx++;
}
vector<string > vec;
map<string, string > mp;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0); 
	int n;
	string a, b;
	cin >> n;
	while (n--) {
		cin >> a >> b;	
		// 如果这个字符串还没有子节点，那么这个字符串就肯定是头结点，将其保存起来方便遍历 
		// map优势，key->val，就这样可以一直循环下去，只要不出现环之类的东西，所以只用存头结点，把key，val
		// 映射下就能搞到若干个链表，不知道这样效率如何，应该是非常低的 
		if (mp[a] == "") vec.push_back(a); 
		// 将b添加到节点尾部 
		mp[a] = b;
		// 因为我们的map是字符串到字符串的映射，所以这里标记链表尾也用的字符串 
		mp[b] = "114514";
	}
	string res;
	int vLen = vec.size();
	cout << vLen << endl;
	for (int i = 0; i < vLen; i++) {
		cout << vec[i] << ' ';
		// 遍历当前链表，最后尾部的字符串就是干员现在的名字 
		while (mp[vec[i]] != "114514") res = mp[vec[i]], vec[i] = mp[vec[i]];
		cout << res << endl;
	}
	// 这里之前写了一个循环，对所有key都进行了查找尾节点的操作，那时候还没有想到链表
	// 的思路，在发现对每个节点都进行遍历不行之后又花了下图，大概是发现只能对头结点进行
	// 遍历所以才有了上面的代码，其实也有点碰运气的感觉，因为在写题解的时候才有链表的思路 
	return 0;
}
