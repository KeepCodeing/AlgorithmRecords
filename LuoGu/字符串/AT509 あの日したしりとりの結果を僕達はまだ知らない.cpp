#include <iostream>
#include <set>
using namespace std;
set<string > sset;
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); 
	int T;
	cin >> T;
	string pre = "1919810";
	string now;
	int cnt = 1;
	while (T--) {
		cin >> now;
		// ���ȣ����ڵ�һ���ַ���Ҫ�������У���Ϊ��֮ǰ��û�б���ַ����ˣ���Σ����ĳ���ַ���
		// �����˶�Σ���ô�����Ƿ��ǺϷ��ģ���˵���������� 
		if (now[0] != pre[pre.size() - 1] && pre != "1919810" || sset.count(now)) {
			cout << (cnt % 2 ? "LOSE" : "WIN") << endl;
			return 0;
		}
		// �����ַ������ϡ�ǰһ�����ʡ��غ��� 
		sset.insert(now), pre = now, cnt++;
	}
	cout << "DRAW" << endl;
	return 0;
}
