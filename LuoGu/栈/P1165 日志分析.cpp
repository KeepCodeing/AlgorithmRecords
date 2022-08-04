#include <iostream>
#include <vector>
using namespace std;

// 突然发现题目要的是最后一次入库的集装箱的重量，
// 所以可以用一个栈模拟下，但是栈不好遍历，所以用vector 
// 直接模拟会超时，主要是查询最大值这部分，考虑下题目，它只要求输出最大
// 值，所以其实比最大值小的值都没必要存放下来，出栈操作其实就是减少长度数
// 只要保证栈顶元素最大即可省去查找的操作 

// 模拟一个栈，但它只存放最大值 
int st[200001];
int main() {
	int n, cnt = 0;
	cin >> n;
	int code, x;
	// 栈底元素，即最小值，在栈为空时最小值为0 
	st[0] = 0;
	for (int i = 0; i < n; i++) {
		cin >> code;
		switch(code) {
			case 0:
				cin >> x;
				cnt++;
				// 在栈顶存放最大值 
				st[cnt] = max(st[cnt - 1], x);
				break;
			case 1:
				// 减少元素个数 
				if (cnt != 0) cnt--;
				break;
			case 2:
				// 输出栈顶元素，即最大元素 
				cout << st[cnt] << endl;
				break;
		}
	}
	return 0;
}
// 超时，因为查找太费时间了 
//vector<int > box;
//int main() {
//	int n, maxWeight = -1;
//	cin >> n;
//	int code, x;
//	for (int i = 0; i < n; i++) {
//		cin >> code;
//		if (code == 0) cin >> x;
//		switch(code) {
//			case 0:
//				box.push_back(x); 
//				break;
//			case 1:
//				if (!box.empty()) {
//					box.pop_back();
//				}
//				break;
//			case 2:
//				maxWeight = -1;
//				if (box.empty()) maxWeight = 0;
//				// 遍历查询最大重量，因为出库可能会导致最大重量的改变
//				for (int i = 0; i < box.size(); i++) {
//					if (box[i] > maxWeight) maxWeight = box[i];
//				} 
//				cout << maxWeight << endl;
//				break;
//		}
//	}
//	return 0;
//}
