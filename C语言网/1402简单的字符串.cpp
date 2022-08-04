#include <iostream>
using namespace std;

// 居然过了（喜），总结就是因为每次只用对比后一个字符，所以这样模拟就行，但是
// 要注意最后一个字符怎么输出，其方法是加一个无关字符，然后让计数器从0开始，
// 因为有最后一个无关字符，所以原字符串的最后一个字符也能被输出，另外还要注意+1，因为计数
// 从0开始，另外这个题或许也用到了所谓的“离线”？，总之没有把原字符另外加一个结果集输出算是
// 一大进步 

int main() {
	int n;
	cin >> n;
	while (n--) {
		string str;
		cin >> str;
		str += '*';
		int cnt = 0;
		for (int i = 0; i < str.size(); i++) {
			if (str[i] != str[i + 1]) {
				if (cnt) cout << cnt + 1;
				// 最后一个字符不输出 
				if (str[i] != '*') cout << str[i];
				// 重置计数器 
				cnt = 0;
			} else {
				cnt++;
			}
		}
		cout << endl;
	}
	return 0;
}
