#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 应该可以用个小顶堆来做，超时坠毁ww 

//struct words {
//	int cnt;
//	string w;
//	words(int c = 0, string ww = "") {
//		cnt = c, w = ww;
//	}
//	bool operator>(const words& w1) const {
//		if (cnt != w1.cnt) return cnt > w1.cnt;
//		return w > w1.w;
//	}
//};
//priority_queue<words, vector<words >, greater<words> > q; 
//vector<words > ws1;
//int main() {
//	int k, n;
//	char c;
//	cin >> k >> n;
//	words w, temp;
//	while (k--) {
//		cin >> w.w;
//		q.push(w); 
//	}
//	while (n--) {
//		cin >> c;
//		while (!q.empty()) {
//			temp = q.top();
//			if (temp.w[0] != c) {
//				ws1.push_back(temp);
//				q.pop(); 
//			} else {
//				cout << temp.w << endl;
//				temp.cnt++;
//				q.pop();
//				q.push(temp);
//				for (int i = 0; i < ws1.size(); i++) q.push(ws1[i]);
//				ws1.clear();  
//				break;
//			}
//		}
//	}
//	return 0;
//}
