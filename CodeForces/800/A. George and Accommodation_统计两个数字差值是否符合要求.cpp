#include <iostream>
using namespace std;

// ����������18��ˮ���ˣ�ˢ������...��֮����û��һ��ʼ��ô���Կ�����...ˢ��20��
// Ӧ�ÿ�����ս�¸��ѵ�����...�������Ǹ��������磬��ɢ���ԣ�������ûʲô�׵�������w... 

int main() {
	int n, a, b, cnt = 0;
	cin >> n;
	while (n--) {
		cin >> a >> b;
		if (b - a >= 2) cnt++;
	}
	cout << cnt << endl;
	return 0;
}
