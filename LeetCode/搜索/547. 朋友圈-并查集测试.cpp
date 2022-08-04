#include <iostream>
#include <vector>
using namespace std;

// ��������ò��鼯��������Ϊ�±�ʹ����ϵ 
// �ݣ������ʵ�ʾ�������ͨ�飬����ȷʵ�����ò��鼯��������̫five
// ����û�п�������������˼����������������зų��ӣ����˸�˵��
// ��û������������ͨ��������...

// ��ô������������ͨ�������������xx��xx�С���ϵ�����ʲ�ͬ��ϵ����
// �м��֣��������ݿ�������ͼ�й�ϵ��Ȼ�����ж����ַ�����...
// Ҳ����˵��������ͨ�����Ŀ��һ������ʲô���죬ˮ�ӣ��ϰ��ȣ����������ǲ�̫����.. 

class Solution {
public:
	struct unionFind {
		int *bin;
		unionFind(int len) {
			bin = new int[len + 1];
			// ��������i j���Ǵ�0��ʼ�� 
			for (int i = 0; i < len; i++) bin[i] = i;
		} 
		int anc(int x) {
			if (bin[x] == x) return x;
			bin[x] = anc(bin[x]);
			return bin[x];
		}
		void uni(int x, int y) {
			bin[anc(x)] = bin[anc(y)];
		}
		bool ask(int x, int y) {
			// �����ǱȽ������Ƿ���ͬ�������ǱȽ�bin[x] == bin[y] 
			return anc(x) == anc(y);
		}
		~ unionFind() {
			delete[] bin;
		}
	};
    int findCircleNum(vector<vector<int> >& M) {
		// n * n��С�����û��Ҫ��ȡһ���С 
		int mSize = M.size();
		unionFind u(mSize);
		int ans = mSize;
		for (int i = 0; i < mSize; i++) {
			for (int j = 0; j < mSize; j++) {
				// �Լ����Լ��������ѣ����������ж� 
				if (i != j && M[i][j]) {
					// ���鼯����ͨͼ�����ĺ��ģ�����һ����ɫ��Ԫ��
					// �ͽ�����ͨ��ϵ�����Ҷ������Լ� 
					if (!u.ask(i, j)) u.uni(i, j), ans--;  
				}
			}
		}
		return ans;
    }
};

int main() {
	return 0;
} 
