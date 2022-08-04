#include <iostream>
#include <vector>
using namespace std;

// ���鼯���ж��������յ��ڲ���һ����ͨ������У�Ҳ�����ж��������Ƿ���й�������

// ���׹���ˣ�����... 
// �ݣ����鼯��ʵֻ���ж�����ͼ�����Ƿ���ͨ���������ж�����ͼ�����Ƿ���ͨ.... 

class Solution {
public:
	struct unionFind {
		int *bin;
		unionFind (int n) {
			bin = new int[n + 10];
			for (int i = 0; i < n + 10; i++) bin[i] = i;
		}
		int anc(int x) {
			if (x != bin[x]) bin[x] = anc(bin[x]);
			return bin[x];
		}
		void uni(int x, int y) {
			bin[anc(x)] = anc(y);
		}
		bool ask(int x, int y) {
			return anc(x) == anc(y);
		}
		~ unionFind() {
			delete[] bin;
		}
	};
    bool findWhetherExistsPath(int n, vector<vector<int> >& graph, int start, int target) {
		if (!n) return false;
		unionFind u(n);
		for (int i = 0; i < n; i++) u.uni(graph[i][0], graph[i][1]);
		return u.ask(start, target);
    }
}; 

int main() {
	return 0;
}
