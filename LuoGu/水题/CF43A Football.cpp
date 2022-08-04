#include<iostream>
#include<map>
using namespace std;

// 水就完了 

map<string,int> s;
int main() {
	int n, maxCnt = -114514;
	string ans, str;
    cin >> n;
    while(n--) {
        cin >> str;
		s[str]++;
        if(s[str] > maxCnt) {
			maxCnt = s[str];
			ans = str;
		}
     }
    cout << ans;
}
