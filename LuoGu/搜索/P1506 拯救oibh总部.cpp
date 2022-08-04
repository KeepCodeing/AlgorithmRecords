#include <iostream>
using namespace std;

// һ�����������⣬������ͼ������ģ���Ȼ���ᳬʱ 
// Ϊ�˷�ֹ©�㣬Ӧ�ÿ���������һȦ 

// ԭ��DFSֻ�����Թ���ʱ����Ҫ���ݽ���ǵĵ�ȡ����ǣ���Ⱦɫ��ʱ����Բ���ȡ����� 

int height, weight;
// ת�������ֵ�ͼ�����ж� 
int m[550][550];
void dfs(int x, int y) {
	// <0��+1����Ϊ�ٶ������ĺ�� 
	if (x < 0 || x > height + 1 || y < 0 || y > weight + 1) return;
	if (m[x][y] != 0) return;
	// ��Ƿ��ʹ���0 
	m[x][y] = 1;
	dfs(x + 1, y);
	dfs(x - 1, y);
	dfs(x, y + 1);
	dfs(x, y - 1);
	// ��ԭ�ƺ����Ǳ���ģ�����Ͼ������ڻ��˵���� 
	// m[x][y] = 1;
	
}
int main() {
	char temp;
	cin >> height >> weight;
	for (int i = 1; i <= height; i++) {
		for (int j = 1; j <= weight; j++) {
			cin >> temp;
			if (temp == '*') m[i][j] = 1;
			else m[i][j] = 0;
		}
	}
	dfs(0, 0);
	int cnt = 0;
	for (int i = 1; i <= height; i++) {
		for (int j = 1; j <= weight; j++) {
			if (m[i][j] != 1) cnt++;
		}
	}
	cout << cnt;
	return 0;
}
