#include <iostream>
#include <sstream>
#include <cstdio>
#include <map>
using namespace std;

// ����֮ǰ�Ĵ��룬��������Ļ�����࣬������ʱ���ƺ�û��ע�⵽��һ�п����ж���ַ�����Ҳ���ǵ�����
// cinֻ������һ���ַ���..�ĳ�getlineӦ�þͿ�����.. ��̫��û�����������������������w..�� 

map<string, int > vote;
int max_cnt = 0;
int main() {
	int n;
	cin >> n;
	// ע��getline���̻���... 
	getchar();
	string str, temp;
	stringstream ss;
	while (n--) {
		getline(cin, str);
		ss << str;
		while (ss >> temp) vote[temp]++, max_cnt = max(vote[temp], max_cnt);
		ss.clear(); 
	}
	for (map<string, int >::iterator it = vote.begin(); it != vote.end(); ++it) {
		if (it->second == max_cnt) cout << it->first << endl;
	}
	return 0;
}
