#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;

// �����ڲ����￴�����㷨�ܲ���AC... 

// м�㷨��Ч�ʹ��ͣ�ֻ�ܹ�һ��ĵ㣬��O2��û��ww 

vector<int > vec;
int main() {
	int n, t, now, res = 0;
	scanf("%d", &n);
	// ��Ҫ��˼�����ģ��ð������Ĺ��� 
	for (int i = 1; i <= n; i++) {
		scanf("%d", &t);
		// �ҵ��ȵ�ǰ������� 
		now = upper_bound(vec.begin(), vec.end(), t) - vec.begin();
		// ��ǰ������һ���ȵ�ǰ���������ľ�����������������Եĸ���
		// ע�������-1����Ϊi�Ǵ�1��ʼ�ģ���vector��0��ʼ��now���ǵ�һ��
		// �ȵ�ǰ���������λ�ã����������������֮��Ҫģ�⽻��ֵ�Ĺ���
		// Ҳ���ǰѴ�ķ�ǰ�棬С�ķź���... 
		res += i - 1 - now, vec.insert(vec.begin() + now, t); 
	}
	printf("%d", res);
	return 0;
}

