#include <iostream>
using namespace std;

// ͬ���Ǽ�ǿ��01�������ɴ˿ɼ�01����������������N��Լ��������������С������һ����ֵѡ�Ҫ�����ֵ���⣨��Ȼ
// ��ֵѡ���ƺ�Ҳ�ǿɱ�ģ� 

// ˳��д���ˣ�����������ݹ��ˣ������ύȫ��RE... 

struct foods {
	int size, w, v;
	foods(int s1 = 0, int w1 = 0, int v1 = 0) {
		size = s1, w = w1, v = v1;
	}
};
int f[2000][2000];
int main() {
	int s, fs, n;
	cin >> s >> fs >> n;
	foods *fd = new foods[n + 1];
	for (int i = 1; i<= n; i++) {
		cin >> fd[i].size >> fd[i].w >> fd[i].v;
	}
	// ע�������˳�����⣬���ڲ��ѭ��һ���ǻ����ı�������Ĵ��ۣ�����������ʱ��ȵȣ� 
	// ������Ĵ���һ�㶼��Ӱ�챳����� 
	for (int i = 1; i <= n; i++) {
		for (int j = s; j >= fd[i].size; j--) {
			for (int k = fs; k >= fd[i].w; k--) {
				// ����֮ǰ�����ˣ�Ӧ�þ��Ƕ�Ӧ�ļ�ֵ��ȥ��Ӧ�Ĵ��� 
				f[j][k] = max(f[j][k], f[j - fd[i].size][k - fd[i].w] + fd[i].v);
			}
		}
	}
	cout << f[s][fs];
	delete[] fd;
	return 0;
}
