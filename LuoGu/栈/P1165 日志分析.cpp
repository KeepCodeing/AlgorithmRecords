#include <iostream>
#include <vector>
using namespace std;

// ͻȻ������ĿҪ�������һ�����ļ�װ���������
// ���Կ�����һ��ջģ���£�����ջ���ñ�����������vector 
// ֱ��ģ��ᳬʱ����Ҫ�ǲ�ѯ���ֵ�ⲿ�֣���������Ŀ����ֻҪ��������
// ֵ��������ʵ�����ֵС��ֵ��û��Ҫ�����������ջ������ʵ���Ǽ��ٳ�����
// ֻҪ��֤ջ��Ԫ����󼴿�ʡȥ���ҵĲ��� 

// ģ��һ��ջ������ֻ������ֵ 
int st[200001];
int main() {
	int n, cnt = 0;
	cin >> n;
	int code, x;
	// ջ��Ԫ�أ�����Сֵ����ջΪ��ʱ��СֵΪ0 
	st[0] = 0;
	for (int i = 0; i < n; i++) {
		cin >> code;
		switch(code) {
			case 0:
				cin >> x;
				cnt++;
				// ��ջ��������ֵ 
				st[cnt] = max(st[cnt - 1], x);
				break;
			case 1:
				// ����Ԫ�ظ��� 
				if (cnt != 0) cnt--;
				break;
			case 2:
				// ���ջ��Ԫ�أ������Ԫ�� 
				cout << st[cnt] << endl;
				break;
		}
	}
	return 0;
}
// ��ʱ����Ϊ����̫��ʱ���� 
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
//				// ������ѯ�����������Ϊ������ܻᵼ����������ĸı�
//				for (int i = 0; i < box.size(); i++) {
//					if (box[i] > maxWeight) maxWeight = box[i];
//				} 
//				cout << maxWeight << endl;
//				break;
//		}
//	}
//	return 0;
//}
