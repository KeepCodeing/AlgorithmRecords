#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

// Ȼ����û���뵽��nth_element()�����ǿ���������������... 

vector<int > vec;
int main() {
	int n, k, t;
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) scanf("%d", &t), vec.push_back(t);
	nth_element(vec.begin(), vec.begin() + k, vec.end());
	printf("%d", vec[k]); 
	return 0;
}
