#include <iostream>
using namespace std;

// �����������ƺ������Կ�������ö��.. 
// ׹�٣��������Ϊ��𰸶���һ�� 

char graph[105][105];
int main() {
	int r, c, k;
	cin >> r >> c >> k;
	// �±��Ȼ���Ǿ�����1��ʼ����Ϊk���Ǵ�0��ʼ�Ƶ� 
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			cin >> graph[i][j];
		}
	}
	int ans = 0;
	// ��ʼλ��Ҳ�㣬�������������Լ򵥵� 
	k--;
	// ��ÿ���㶼�ж����ܲ���վ
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			if (graph[i][j] != '#') {
				// ���ܴ��ڵ������������Ϊ������k�Լ��� 
				if (k <= 0) {
					ans++;
					continue;
				} 
				// �����ж�
				// if (i + k >= r || i - k < 0 || j + k >= c || j - k < 0) continue; 
				// ��  
				int up = i - k, down = i + k, left = j - k, right = j + k;
				int t;
				if (up >= 1) {
					for (t = i; t >= up; t--) {
						if (graph[t][j] != '.') break;
					}
					if (t < up) ans++;
					// cout << i << ' ' << j << endl;
				}
				// ��
				if (down <= r) {
					for (t = i; t <= down; t++) {
						if (graph[t][j] != '.') break;
					}
					if (t > down) ans++;
				} 
				// ��
				if (left >= 1) {
					for (t = j; t >= left; t--) {
						if (graph[i][t] != '.') break;
					}
					if (t < left) ans++;
				} 
				// �� 
				if (right <= c) {
					for (t = j; t <= right; t++) {
						if (graph[i][t] != '.') break;
					}
					if (t > right) ans++;
				}
			}
		}
	} 
	cout << ans / 2;
	/*
		.###.
		##.#.
		..#..
		#..#.
		#.###
	*/
	return 0;
}
