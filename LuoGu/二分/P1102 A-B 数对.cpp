#include <iostream>
#include <map>
#include <cstdio>
using namespace std;

// 用map做桶，然后二分B-C，看下有没有这个key，有的话方案数就加上这个元素出现的次数，这样既起到了去重，
// 也能进行二分统计方案数 
// 只过了一个点，瑞了，睡觉... 

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
