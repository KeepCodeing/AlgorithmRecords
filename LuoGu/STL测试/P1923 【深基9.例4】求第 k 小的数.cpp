#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

// 然而并没有想到用nth_element()，还是看了题解才想起来的... 

vector<int > vec;
int main() {
	int n, k, t;
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) scanf("%d", &t), vec.push_back(t);
	nth_element(vec.begin(), vec.begin() + k, vec.end());
	printf("%d", vec[k]); 
	return 0;
}
