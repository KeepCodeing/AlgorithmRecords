#include <iostream>
#include <map>
#include <vector>
using namespace std;

// ׹��w����mapֻ��ͳ�Ʒ���ʼ��Ϊ���������Ҳ����˵�����ǰ������
// �Ǹ�Ԫ�ر������ˣ���������ǲ�����µģ����Ҫ������Ҫ�����統ǰ
// �ӷ��Ƿ�Ϊ������ǰ���µ������ǲ��Ǵ����ֵȵȣ�Ȼ������������Ҳ�ᵼ��
// �𰸸��£����������²�ûʲô�ã���Ϊ���ܼ��ϸ���֮�������ֵķ־�
// ������... 

vector<string > names;
map<string, int > scores;
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	string nm;
	int sc;
	int res = -0x3fffffff;
	string rname;
	while (n--) {
		cin >> nm >> sc;
		// if (!scores.count(nm)) names.push_back(nm);
		if (sc < 0) {
			if (rname == nm)
		}
		scores[nm] += sc; 
		if (scores[nm] > res) res = scores[nm], rname = nm;
	} 
//	int nLen = names.size();
//	int res = -0x3fffffff;
//	string rname;
//	for (int i = 0; i < nLen; i++) {
//		if (scores[names[i]] > res) res = scores[names[i]], rname = names[i];
//	}
	cout << rname << endl;
	return 0;
}
