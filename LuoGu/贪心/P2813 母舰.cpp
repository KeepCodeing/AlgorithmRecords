#include <iostream>
#include <algorithm>
using namespace std;

// ��Ŀ����˼����Ҫ�󽫶Է�ĸ���ķ���ϵͳȫ��
// �Ƶ����Ƶ�����ϵͳ�Ĺ����Ǽ������������ڵ���
// �ط����������߳����˺����㣬�ط�����ϵͳû��
// ��������˺�

// ���Կ��ǵ�̰�Ĳ������øոմ��ڻ��ߵ��ڵз�
// ĸ���������Ĺ��������� 

// �ƺ���Ҫ���ڲ��� 

// ��Ҫ��û���ǵ�0���Լ�����ѭ������̫��Ч�� 

int *enemy, *me; 
int main() {
	int m, n;
	cin >> m >> n;
	enemy = new int[m];
	me = new int[n];
	for (int i = 0; i < m; i++) cin >> enemy[i];
	for (int i = 0; i < n; i++) cin >> me[i];
	// ���򣬷����޷����ֲ��� 
	sort(enemy, enemy + m);
	sort(me, me + n);
	// ���̣�����ı���ö�ٿ����Ż�����Ȼ����TLE�����о���û���ǵ�0����� 
	int index = 0;
	for (int i = 0; i < n; i++) {
		// Ϊ0˵��û�з����������ֱ����ȥ�����˷��˹����� 
		if (enemy[index] == 0) {
			index++;
			continue;
		}
		if (me[i] > enemy[index]) me[i] = 0, index++; 
	}
//	for (int i = 0; i < m; i++) {
//		// ���ֲ���Ӧ�øպ÷�����ĿҪ�󣬴��ڻ��ߵ��ڵ�ֵ�����У�
//		// ��Ŀ˵���Ǵ���...������ж�����ھͻ�׹�٣� 
//		// index = lower_bound(enemy, enemy + m, enemy[i]) - enemy;
//		// ֱ�ӱ����� 
//		for (int j = 0; j < n; j++) {
//			if (enemy[i] < me[j]) {
//				me[j] = 0;
//				break;
//			}
//		}
//	}
	int ans = 0;
	// ����һ�£��������
	if (index < m) {
		cout << 0;
	} else {
		for (int i = 0; i < n; i++) ans += me[i];
		cout << ans;
	}
	delete[] enemy, me;
	return 0;
}
