#include <iostream>
#include <map>
#include <cstdio>
using namespace std;

// ��map��Ͱ��Ȼ�����B-C��������û�����key���еĻ��������ͼ������Ԫ�س��ֵĴ���������������ȥ�أ�
// Ҳ�ܽ��ж���ͳ�Ʒ����� 
// ֻ����һ���㣬���ˣ�˯��... 

map<int, int > mp;
int main() {
	int n, c, t;
	scanf("%d%d", &n, &c);
	while (n--) scanf("%d", &t), mp[t]++;
	int res = 0;
	for (map<int, int >::iterator it = mp.begin(); it != mp.end(); ++it) {
		//printf("%d\n", mp.lower_bound(c + it->first)->first == c + it->first);
		if (mp.lower_bound(it->first - c)->first == c + it->first) {
			res += mp[it->first];
		}
	}
	printf("%d", res);
	return 0;
}
