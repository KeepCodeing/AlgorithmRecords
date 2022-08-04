#include <iostream>
#include <algorithm>
using namespace std;

// �þ�֮ǰ���ŵ��⣬��ʱ��д��̫�ѿ��ˣ��о���Ҫ���Ǵ���ǰ��0����� 

// ˫ָ�뽻�������Ч�� 
string reverseStr(string str) {
	int left = 0, right = str.size() - 1;
	while(left < right) swap(str[left++], str[right--]);
	return str;
}
// ȥ��ǰ��0������С������������ǲ�����0��ͷ�� 
string clearZero(string str) {
	bool flag = false;
	// ����ֻ�������С�����������⼸�����ֻҪ��ͷ����0���� 
	if (str[0] != '0') return str;
	int i;
	for (i = 0; i < str.size(); i++) {
		if (str[i] != '0') break;
	}
	// ������0
	if (i == str.size()) return "0";
	// �ӵ�һ����0���ֿ�ʼ��ȡ 
	return str.substr(i);
}
int main() {
	string num;
	cin >> num;
	// ������������ֱ���
	int index; 
	// �����ŵ���򵥵�������ٷ��� 
	if ((index = num.find("%")) != num.npos) {
		cout << clearZero(reverseStr(num.substr(0, index))) << "%";
	} else if ((index = num.find("/")) != num.npos) {
		// ������������������г������֣����ǿ��ܻ���0000/�������ݣ����Ե���clearZero�������ر����� 
		cout << clearZero(reverseStr(num.substr(0, index))) << '/' << clearZero(reverseStr(num.substr(index + 1)));
	} else if ((index = num.find(".")) != num.npos) {
		// ����С����Ҳ�Ƿֳ�������
		cout << clearZero(reverseStr(num.substr(0, index))) << '.';
		// ����С�����ǴӺ�ȥ0 
		string right = num.substr(index + 1);
		// �и��ӣ����С������ȫ��0����Ӧ�����xx.0 
		if (count(right.begin(), right.end(), '0') == right.size()) cout << "0";
		// ���С������xx.100���������ת�˾���xx.001����������ǺϷ��� 
		else if (right[0] != '0') cout << reverseStr(right);
		// ����.0001���������ת�˾���.10000,��ô�Ͱ�ȥǰ��0�Ĳ��������� ����ȥ0���ٷ�ת 
		else cout << reverseStr(clearZero(right));
	} else {
		// �����������
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
