#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;

// �����Ŀ�ܿӵ����ӣ������������Ա�Ҳû˵������ʲô�Աȹ��򣬻���
// ����7~14λ���ֵĴ�С

// ���TLE��... 

struct date {
	string str;
	string birthday;
	date (string str, string birthday) : str(str), birthday(birthday) {};
	bool operator<(const date& d) {
		if (birthday != d.birthday) return birthday > d.birthday;
		return str < d.str;
	}
};
vector<date > vec;
int main() {
	int n;
	cin >> n;
	while (n--) {
		string card;
		// ��ʽ����׹�٣����ǽ�ȡ���� 
		// scanf("%.6s%.8s%.4s", &a, &b, &c);
		// ��scanf����C++�ַ�����Ҫ��resize�ռ��ٴӵ�1����ַ����..����ȻTLE�� 
		card.resize(19); 
		scanf("%s", &card[0]);
		// cout << card.substr(6, 8) << endl;
		// ����ʮ�������ŴβŽضԵĳ��� 
		vec.push_back((date){card, card.substr(6, 8)});
	}
	sort(vec.begin(), vec.end());
	int vLen = vec.size();
	for (int i = 0; i < vLen; i++) {
		cout << vec[i].str; 
		if (i != vLen - 1) cout << endl;
	}
	return 0;
}

/*
5 
466272 30750327 1156 
215856 47220709 7978 
234804 58040107 8365 
404475 72770003 4980 
710351 40880309 3165 
*/

/*
404475 72770003 4980
234804 58040107 8365
215856 47220709 7978
710351 40880309 3165
466272 30750327 1156
*/

/*
710351 40880309 3165
404475 72770003 4980
466272 30750327 1156
215856 47220709 7978
234804 58040107 8365
*/
