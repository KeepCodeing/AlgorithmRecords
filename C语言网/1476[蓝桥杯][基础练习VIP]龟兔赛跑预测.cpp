#include <iostream>
using namespace std;

// ��Ŀ�����˸���ʾ��˵·���������ٶȵĹ�����������
// ������ȡ�����Ӳ���˯��ʱ����������ڹ��������Ȼ��������ӻ�˯����
// ����ģ���� 

// ������������Ĥ���ǳ�
 
int main() {
	int v1, v2, t, s, l;
	cin >> v1 >> v2 >> t >> s >> l;
	// �������ܳ��ֵĿ� 
	if (l <= 0) {
		cout << "D" << endl << 0;
		return 0;
	}
	// ����������ȵ��ǲ�˯����ֱ�����˭�ߵĿ켴�� 
	if (s == 0) {
		if (l / v1 > l / v2) {
			cout << "T" << endl << l / v2;
		} else if (l / v1 < l / v2){
			cout << "R" << endl << l / v1;
		} else {
			cout << "D" << endl << l / v2;
		}
		return 0;
	}
	// ��������߲����������ڹ��ߵĶ����ڹ��Ӯ 
	if (v1 <= 0 && v2 > 0) {
		cout << "T" << endl << l / v2;
		return 0;
	}
	// ����ڹ��߲��������Ų����ܣ���������Ҳ�߲��������ǿ���
	// ����һ�����ܵ��յ㣬��û��˯��������� 
	if (v2 <= 0 && v1 > 0 && v1 >= l) {
		cout << "R" << endl << 1;
		return 0;
	}
	// ��ȡ���ǵĻ������� 
	int tuCnt = l / v1, guiCnt = l / v2;
	int l1 = 0, l2 = 0;
	int vt = v1, st = s;
	int sCnt = 0;
	bool flag = false;
	while (l1 < l || l2 < 1) {
		l2 += v2;
		l1 += vt;
		// ������������ˣ�����˯�� 
		if (l1 - l2 >= t) {
			vt = 0;
			flag = true;
			// ������Ϊһ��������Լ��ˣ�����Ҫ��1 
			st = s + 1;
			// ����˯���������� 
			sCnt++;
		}
		// ����˯st�� 
		if (flag) st--;
		// ˯���˻ָ��ж��� 
		if (st <= 0) vt = v1, flag = false;
	}
	tuCnt += sCnt * s;
	// ���������ʱ����ͬ���ڹ���죬���Ӹ��� 
	if (tuCnt == guiCnt) cout << "D" << endl << tuCnt;
	else if (tuCnt > guiCnt) cout << "T" << endl << guiCnt;
	else cout << "R" << endl << tuCnt;
	return 0;
} 
