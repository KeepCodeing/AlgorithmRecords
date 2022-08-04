#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, int > PII;
vector<PII > vec;

// 感觉下面的代码存在很大的缺陷，比如其无法特判字符串末尾的两个字符，思考了下发现可以记录WUB的区间
// 既然最后两个字符在字符串不是以WUB结尾的时候会被跳过，那么就说明这段区间没被覆盖，否则就是被覆盖了.. 
  
int main() {
	string str, temp;
	cin >> str;
	int sLen = str.size();
	for (int i = 0; i < sLen - 2; i++) {
		if (str[i] == 'W' && str[i + 1] == 'U' && str[i + 2] == 'B') vec.push_back(PII(i, i + 2)), i += 2;  
	}
	for (int i = 0; i < vec.size(); i++) {
		int l = vec[i].first, m = vec[i].first + 1, r = vec[i].second;
		str[l] = str[m] = str[r] = ' ';
	}
	string res;
	bool flag = false;
	for (int i = 0; i < sLen; i++) {
		if (str[i] == ' ') {
			if (flag) {
				res += ' ';
				flag = !flag;
			}
		} else {
			res += str[i];
			flag = true;
		}
	}
	int rLen = res.size();
	if (res[rLen - 1] == ' ') res = res.substr(0, rLen - 1); 
	cout << res << endl;
	return 0;
}
//#include <iostream>
//#include <vector>
//using namespace std;
//vector<string > vec;
//int main() {
//	string str, temp;
//	cin >> str;
//	str += '*';
//	int sLen = str.size();
//	for (int i = 0; i < sLen - 2; i++) {
//		// 如果当前字符串为基准加上后面的字符为WUB就跳过，这样做下次的基准字符一定是WUB或者不是WUB
//		// 如果不是WUB，则会进入到下面的分支，将其存起来 
//		if (str[i] == 'W' && str[i + 1] == 'U' && str[i + 2] == 'B') {
//			i += 2;
//			if (temp.size()) {
//				vec.push_back(temp); 
//				temp = "";
//			}
//			continue;
//		} else {
//			// 如果不是，就将其存起来... 
//			temp += str[i];
//		}
//	}
//	for (int i = 0; i < vec.size(); i++) {
//		if (i != 0) cout << ' ';
//		cout << vec[i];
//	} 
//	return 0;
//}
