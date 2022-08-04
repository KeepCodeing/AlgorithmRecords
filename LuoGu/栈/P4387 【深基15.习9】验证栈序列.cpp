#include <iostream>
#include <stack>
using namespace std;
stack<int > s;
int pu[100005], po[100005];
int main() {
	int q, n;
	int index = 0;
	cin >> q;
	for (int i = 0; i < q; i++) {
		cin >> n;
		// 老老实实都存起来 
		for (int j = 0; j < n; j++) cin >> pu[j];
		for (int k = 0; k < n; k++) cin >> po[k];
		for (int t = 0; t < n; t++) {
			s.push(pu[t]);
			while(!s.empty()) {
				// 大概的思路就是把pu都压到栈里，如果po的index个元素和pu最后入栈的元素相同
				// 则开始出栈对比，并统计相同元素的个数，如果个数等于n，说明全部相同，否则则有不同 
				if (s.top() == po[index]) {
					s.pop();
					index++;
				} else {
					break;
				}
			}
		}
		if (index >= n) cout << "Yes" << endl;
		else cout << "No" << endl;
		index = 0;
		// 清空栈 
		while (!s.empty()) s.pop(); 
	}
	return 0;
} 

// 奇妙，这样写WA了 
//#include <iostream>
//#include <vector>
//using namespace std;
//vector<int > st;
//int main() {
//	int q;
//	int n, t, pt;
//	bool flag = true;
//	cin >> q;
//	for (int i = 0; i < q; i++) {
//		flag = true;
//		cin >> n;
//		for (int j = 0; j < n; j++) {
//			cin >> t;
//			st.push_back(t); 
//		}
//		for (int k = 0; k < n; k++) {
//			cin >> t;
//			pt = st.back();
//			if (t != pt) {
//				flag = false;
//				st.clear();
//				break;
//			}
//			st.pop_back();
//		}
//		if (!flag) {
//			cout << "No" << endl;
//		} else {
//			cout << "Yes" << endl;
//		}
//	}
//	
//	return 0;
//}
