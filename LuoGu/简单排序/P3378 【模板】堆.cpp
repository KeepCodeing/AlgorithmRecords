#include <iostream>
#include <queue>
using namespace std;

// ���ȶ��У�����̸�� 
// ���̣�TLEһ���㣬��O2���� 

priority_queue<int > que;
int main() {
	int n, code, x;
	cin >> n;
	while(n--) {
		cin >> code;
		if (code == 1) {
			cin >> x;
			// ת��С���ѣ�Ȼ��ԭ 
			que.push(-x); 
		} else if (code == 2) {
			cout << -que.top() << endl;
		} else {
			que.pop();
		}
	}
	return 0;
}
