#include <iostream>
#include <vector>
using namespace std;

// wl��ˢģ���� 

// �������ʸ�����洢���ʣ���Ϊ��ֱ�Ӱ�һ������/�Թ�����ַ����� 
// ׹�٣������㷴�����鷳�ˣ���Ҫ�������յ��λ��ȷ�� 
//vector<string > mz;
//vector<string > commands;
// ������;���ַ�����ϵ 
char maze[1005][1005];
int main() {
	int n;
	int mazeSize;
	int m;
	string comStr;
	int sx, sy, ex, ey; 
	cin >> n;
	while (n--) {
		cin >> mazeSize;
		for (int i = 0; i < mazeSize; i++) {
			for (int j = 0; j < mazeSize; j++) {
				cin >> maze[i][j];
				if (maze[i][j] == 'S') sx = i, sy = j;
				if (maze[i][j] == 'T') ex = i, ey = j;
			}
		}
		cin >> m;
		while (m--) {
			cin >> comStr;
			string res = "";
			// ���̣���Ȼû�뵽������ָ�... 
			int tSx = sx, tSy = sy;
			for (int i = 0; i < comStr.size(); i++) {
				switch(comStr[i]) {
					// ���ǰ�x������д���������������¿ɲ�����������������
					case 'U':
						tSx -= 1;
						break;
					case 'D':
						tSx += 1;
						break;
					case 'L':
						tSy -= 1;
						break;
					case 'R':
						tSy += 1;
						break;
				}
				// ����ײ���ϰ����߳��߽����������������
				// Ӧ�ö���������ֹ��������û���յ�͵����յ�
				// ����������ִ����Ż��е�
				// ϲ���ּ��ĳ����жϣ����������ж��Ƿ���磬��Ȼ�����ж�
				// �ϰ����޷���֤�±���Ч�� 
				 if (tSx < 0 || tSy < 0 || tSx >= mazeSize || tSy >= mazeSize) {
				 	// ��I  am  out!������ֱ�Ӹ��Ƹ��ģ���������������� 
				 	res = "I am out!";
				 	break;
				 } 
				 if (maze[tSx][tSy] == '#') {
				 	res = "I am dizzy!";
				 	break;
				 }
				 // ������Ŀ�е����ݱ�ʾ�������յ�ҲҪֱ���˳�����������ֱ���˳��������洦��
				 if (maze[tSx][tSy] == 'T') break; 
			}
			// ���ǰ������������ˣ��Ͳ����жϺ��������
			if (res.size()) {
				cout << res << endl;
				continue;
			} 
			if (tSx == ex && tSy == ey) res = "I get there!";
			else res = "I have no idea!";
			cout << res << endl;
		}
	}
	return 0;
}
