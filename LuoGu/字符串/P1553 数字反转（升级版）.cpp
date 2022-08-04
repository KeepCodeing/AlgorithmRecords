#include <iostream>
#include <algorithm>
using namespace std;

// 好久之前卡着的题，那时候写的太难看了，感觉主要还是处理前导0的情况 

// 双指针交换，提高效率 
string reverseStr(string str) {
	int left = 0, right = str.size() - 1;
	while(left < right) swap(str[left++], str[right--]);
	return str;
}
// 去除前导0，除了小数情况其它都是不能以0开头的 
string clearZero(string str) {
	bool flag = false;
	// 暂且只处理除了小数外的情况，这几种情况只要开头不是0就行 
	if (str[0] != '0') return str;
	int i;
	for (i = 0; i < str.size(); i++) {
		if (str[i] != '0') break;
	}
	// 坑数据0
	if (i == str.size()) return "0";
	// 从第一个非0数字开始截取 
	return str.substr(i);
}
int main() {
	string num;
	cin >> num;
	// 分四种情况，分别处理
	int index; 
	// 带符号的最简单的情况：百分数 
	if ((index = num.find("%")) != num.npos) {
		cout << clearZero(reverseStr(num.substr(0, index))) << "%";
	} else if ((index = num.find("/")) != num.npos) {
		// 处理分数，基本就是切成两部分，但是可能会有0000/这种数据，所以得在clearZero函数里特别声明 
		cout << clearZero(reverseStr(num.substr(0, index))) << '/' << clearZero(reverseStr(num.substr(index + 1)));
	} else if ((index = num.find(".")) != num.npos) {
		// 处理小数，也是分成两部分
		cout << clearZero(reverseStr(num.substr(0, index))) << '.';
		// 处理小数就是从后去0 
		string right = num.substr(index + 1);
		// 有个坑，如果小数部分全是0，那应该输出xx.0 
		if (count(right.begin(), right.end(), '0') == right.size()) cout << "0";
		// 如果小数不是xx.100的情况，翻转了就是xx.001，这种情况是合法的 
		else if (right[0] != '0') cout << reverseStr(right);
		// 形如.0001的情况，翻转了就是.10000,那么就按去前导0的策略来就行 ，先去0，再翻转 
		else cout << reverseStr(clearZero(right));
	} else {
		// 处理整数情况
		cout << clearZero(reverseStr(num));
	}
	return 0;
}

/*
2019-11-30 15:32:55
#include <iostream>
#include <algorithm>
using namespace std;
void szfz() {
    string num;
    bool flag = true, pre_flag = true, next_flag = true;
    int index;
    int prv = 0, next = 0;
    cin >> num;
    if ((index = num.find('.')) != -1) {
        if (index != 1) reverse(num.begin(), num.end() - num.size() + index);
        reverse(num.begin() + index + 1, num.end());
    } else if ((index = num.find('%')) != -1) {
        if (index != 1) reverse(num.begin(), num.end() - 1);
        reverse(num.begin() + index + 1, num.end());
    } else if ((index = num.find('/')) != -1) {
        if (index != 1) reverse(num.begin(), num.end() - num.size() + index);
        reverse(num.begin() + index + 1, num.end());
    } else {
        if (index != 1) reverse(num.begin(), num.end());
        cout << num;
        return;
    }
    for (int i = 0; i < num.size(); ++i) {
        if (num[i] == '.' || num[i] == '/') {flag = false; continue;}
        prv += flag ? 1 : 0;
        next += flag ? 0 : 1;
    }
    if (prv != 1) {
        for (int j = 0; j < prv; ++j) {
            if (num[j] == '0') continue;
            pre_flag = false;
            cout << num[j];
        }
        if (pre_flag) cout << num[0];
    } else {
        cout << num[0];
    }
    cout << num[index];
    if (next != 1) {
        for (int j = index+1; j < num.size(); ++j) {
            if (num[j] == '0') continue;
            next_flag = false;
            cout << num[j];
        }
        if (next_flag) cout << num[index+1];
    } else {
        cout << num[index + 1];
    }
}
int main() {
    szfz();
    return 0;
}
*/
