#include <iostream>
#include <map>
using namespace std;

// ��Ҫ��map��Ӧ�𰸺����� 

map<string, string > ans;
int main() {
	int n, q;
	cin >> n >> q;
	string question, answer;
	for (int i = 0; i < n; i++) {
		cin >> question >> answer;
		ans[question] = answer;
	}
	for (int i = 0; i < q; i++) {
		char r = 'A';
		cin >> question;
		// �������һ��������𰸺�ѡ�������Ը���ֱ�� 
		for (int j = 0; j < 4; j++) {
			cin >> answer;
			if (ans[question] == answer) {
				cout << r << endl;
			}
			r++;
		}
	}
	return 0;
}
