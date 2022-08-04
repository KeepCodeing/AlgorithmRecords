#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

// ͬ���ṹ��+��ʽ�������� 

struct date {
	int mm, dd, yyyy;
	date(int mm, int dd, int yyyy) : mm(mm), dd(dd), yyyy(yyyy) {};
	bool operator<(const date& d) {
		if (yyyy != d.yyyy) return yyyy < d.yyyy;
		if (mm != d.mm) return mm < d.mm;
		return dd < d.dd;
	}
};
vector<date > vec;
int main() {
	int m, d, y;
	while(scanf("%2d/%2d/%4d", &m, &d, &y) != EOF) {
		vec.push_back((date){m, d, y});
	}
	sort(vec.begin(), vec.end());
	int vLen = vec.size();
	for (int i = 0; i < vLen; i++) {
		// ��Ϊ����������֣����Բ�����λ�Ĳ���Ҫ��0 
		date temp = vec[i];
		if (temp.mm < 10) cout << 0;
		cout << vec[i].mm << '/';
		if (temp.dd < 10) cout << 0;
		cout << vec[i].dd << '/' << vec[i].yyyy; 
		if (i != vLen - 1) cout << endl;
	}
	return 0;
} 
