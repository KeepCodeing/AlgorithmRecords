#include <iostream>
#include <map>
#include <cstdio>
using namespace std;

// ˮ��ڶ�ʮһ��...Ȼ��������ˢˮ��ҲҪ�Ұ�����Ŀ��������... 

typedef pair<int, int > PII;
map<PII, int > mp;
int main() {
	int n, res = 0;
	PII nums;
	scanf("%d", &n);
	while (n--) {
		scanf("%d%d", &nums.first, &nums.second);
		mp[nums]++;
	}
	for (map<PII, int >::iterator it = mp.begin(); it != mp.end(); it++) res = max(res, it->second);
	printf("%d\n", res);
	return 0;
}
