#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
string *strs;
vector<string > result;
// ��Ŀ��û�����ֱ�ӿ�ʼд����Ŀ��˵��ƥ���ַ�������д��ƥ���ַ��ˣ����ܣ� 
int main() {
	int n;
	string c;
	cin >> n;
	strs = new string[n];
	for (int i = 0; i < n; i++) cin >> strs[i];
	cin >> c;
	// ����ط�û��ʲô���壬��ȫ�����Ƚ����������������˱����Ĺ����б��жϱ���� 
	for (int i = 0; i < n; i++) {
		// cout << strs[i].find(c) << endl;
		if (strs[i].find(c) != 0) continue;
		result.push_back(strs[i]);
	}
	sort(result.begin(), result.end());
	for (int i = 0; i < result.size(); i++) {
		cout << result[i];
		if (i != result.size() - 1) cout << endl;
	}
	delete[] strs;
	return 0;
}
