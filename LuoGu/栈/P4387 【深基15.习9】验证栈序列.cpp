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
		// ����ʵʵ�������� 
		for (int j = 0; j < n; j++) cin >> pu[j];
		for (int k = 0; k < n; k++) cin >> po[k];
		for (int t = 0; t < n; t++) {
			s.push(pu[t]);
			while(!s.empty()) {
				// ��ŵ�˼·���ǰ�pu��ѹ��ջ����po��index��Ԫ�غ�pu�����ջ��Ԫ����ͬ
				// ��ʼ��ջ�Աȣ���ͳ����ͬԪ�صĸ����������������n��˵��ȫ����ͬ���������в�ͬ 
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
		// ���ջ 
		while (!s.empty()) s.pop(); 
	}
	return 0;
} 

// �������дWA�� 
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
