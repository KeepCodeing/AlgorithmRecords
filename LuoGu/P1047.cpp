#include <iostream>
using namespace std;
int *road;
int main() {
	// ��0��ʼ���� 
	int len, cnt, result = 0;
	cin >> len >> cnt;
	road = new int[len + 1]();
	int start, end;
	for (int i = 1; i <= cnt; i++) {
		cin >> start >> end;
		for(int j = start; j <= end; j++) {
			// ��ֹ�ظ����
			if (road[j] == 0) road[j] = 1;
		}
	}
	// ��Ҫ��bug���ǰ���㵱��1�ˣ����ⲻ��ϸ 
	for (int i = 0; i <= len; i++) {
		if (road[i] == 1) continue;
		result += 1;
	}
	cout << result;
}
