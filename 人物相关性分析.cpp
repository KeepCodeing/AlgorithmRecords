#include <iostream>
#include <map>
#define endl '\n'
using namespace std;

const int K = 1e6 + 10;

string strs[K];
int points[K][2];
int main() {
	string str;
	int sLen = 0, cnt = 0;
	int k;
	
	cin >> k;
	getchar();
	getline(cin, str);
	
	sLen = str.size();
	
	
	for (int i = 0; i < sLen; i++) {
		// 首先计算单词坐标，根据空格分隔 
		string temp = "";
		int l = i, r = i;
		while (str[r] != ' ' && r < sLen) temp += str[r++];
		i = r;
		// 接下来将单词与对应头尾坐标存起来 
		points[cnt][0] = l;
		points[cnt][1] = r - 1;
		strs[cnt++] = temp;

//		cout << strs[cnt - 1] << ' ' << points[cnt - 1][0] << ' ' << points[cnt - 1][1] << endl;
	}
	
	// 之后扫描[x, x + k]区间内的单词，看是否有Alice Bob存在
	for (int i = 0; i < sLen; i++) {
		if (i + k >= sLen) break;
		for (int j = i; j <= i + k; j++) {
			for (int t = 0; t < cnt; t++) {
				if (points[t][0] >= i && points[t][1] <= j) cout << strs[t] << endl;
			}
//			if (points[0] <= i && points[1] <= j) cout << strs
		}
	} 
	
	return 0;
}
// This is a story about Alice and Bob. Alice wants to send a private message to Bob.

/**
 * 
 #### 人物相关性分析
 
 [人物相关性分析 - 蓝桥云课 (lanqiao.cn)](https://www.lanqiao.cn/problems/198/learning/)
 
 思路：我们将题目的要求分成两部分，首先要求`Alice`和`Bob`两个单词出现，且区分大小写，可包括标点符号，必须是作为单词出现，不能作为一部分出现（`AliceMargatroid`不算`Alice`，但`Bob.`是合法的）；其次要求它们间隔的字符数量不超过`k`。
 
 与上一题串的处理一样，我们可以根据空格将一个字符串分为若干个单词，例如`A B C`可以分为`A，B，C`三个单词组成。但这一题与上一题的不同点在于它需要根据**两个单词间的字符个数确定它们的距离是否在k之内**，因此我们最好采用**一行读取**方式将空格也计算在内。
 
 处理好单词后，我们来考虑`k`在本题中的作用。首先可以确定，**字符间距超过`k`的单词无论如何都不是答案**。反过来说即答案一定存在于间距在`k`之内单词中。如果我们将这一行字符串看成坐标轴，那么就可以得出这样的结论：**答案只可能出现在`[x, x + k]`这个范围内**。
 **/
