#include <iostream>
#include <cstdio>
#include <map>
using namespace std;
typedef long LL;
// getchar本机上运行不带cstdio头文件可以通过，但是评测机上不行... 
LL qread(){
    LL w=1,c,ret;
    while((c=getchar())> '9'||c< '0')
    w=(c=='-'?-1:1); ret=c-'0';
    while((c=getchar())>='0'&&c<='9')
    ret=ret*10+c-'0';
    return ret*w;
}
map<LL, LL > mp;
int main() {
	LL n, k, temp;
	cin >> n >> k;
	LL res = 0;
	while (n--) {
		temp = qread();
		if (k % 2 != 0) {
			if (!(res ^ temp)) {
				cout << temp;
				return 0;
			} else {
				res ^= temp;
			}
		} else {
			res ^= temp;
		}
//		mp[temp]++;
//		if (!(mp[temp] % k)) mp.erase(temp); 
	}
	cout << res;
//	for (map<LL, LL >::iterator it = mp.begin(); it != mp.end(); it++) {
//		if (it->second % k != 0) {
//			cout << it->first;
//			break;
//		}
//	}
	return 0;
}
