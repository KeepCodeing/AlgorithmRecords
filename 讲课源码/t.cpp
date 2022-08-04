#include <iostream>
// sort函数被包含在此头文件中
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <map>
using namespace std;

bool cmp(int a, int b) { return a < b; }

struct Node {
	int x;
    // 重载排序操作符
	bool operator< (Node n) const {
		return n.x < x;
	}
};

int arr[10];

int main() {
	
    priority_queue<int > que;
    que.push(1);
    que.push(3);
    que.push(2);
    que.push(1);
    
    
    
	return 0;
}
