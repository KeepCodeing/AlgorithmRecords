#include <iostream>
#include <bitset>
#include <cmath>
#include <map>
#include <set>
using namespace std;

// �뵽�˸���nt�ı����ⷨ���������ݷ�Χ�ǿ��Թ���...
// ���������b�Ƕ��٣�Ҳ����ö�ٵķ�Χ��[0, 2^b]����Ϊ�ǵ�������ģ����Կ�����������Ȼ��������Χ���ʮ������ת��Ϊ
// ����������������n^2��ö�ٶԱ�d��Ȼ��ͳ�ƴ�w... 
// ����ʮ����ת������Ӧ�ò����Լ�д��ֱ��bitset���У�ע��ת����ֻ����bλ... 
// ����Ҫע��ĵط���bitset����ֱ�ӳ�ʼ����ʱ��ָ�����֣�Ҳ����ͨ��=��ֵ�ķ�ʽָ�����֣�Ȼ�������������һ��������ָ��
// λ���������ø���������ô�Ϳ���д��ѭ����Ȼ��i == bʱ��һ��������Ȼ����������������Χ����������w���ɴ�ֱ�Ӹ�ֵ��
// һ��������Ȼ������Ҳ���У�����ֱ�Ӹ�8λ���ˣ�.. 

map<int, set<int > > mp;
const int N = 300;
string strs[N];
int main() {
	int n, b, d, t;
	cin >> n >> b >> d;
	t = pow(2, b);
	bitset<8 > s;
	for (int i = 0; i < t; i++) {
		s = i;
		// ��ͷ�����ȡ 
		strs[i] = s.to_string().substr(8 - b);
	}
	
	for (int i = 0; i < t; i ++) {
		bool flag = false;
		for (int j = 0; j < t; j++) {
			if (i != j) {
				int dt = 0;
				for (int k = 0; k < b; k++) {
					if (strs[i][k] != strs[j][k]) dt++;
				}
				if (dt >= d) {
					mp[i].insert(j);
//					cout << j << endl;
//					cout << strs[i] << ' ' << strs[j] << endl;
//					flag = true;
//					break;
				}
			}
		}
//		break;
//		if (!flag) cout << i << endl;
	}
	set<int > tres, res;
	for (int i = 1; i < t; i++) {
		if (mp[0].count(i)) tres.insert(i); 
		if (mp[i].count(0)) tres.insert(0); 
	}
	for (int i = 2; i < t; i++) {
		if (tres.count(mp[i])) res.insert(i); 
		if (mp[i].count(0)) res.insert(0); 
	}
//	for (set<int >::iterator it = res.begin(); it != res.end(); ++it) cout << *it << endl;
//	for (int i = 0; i < t; i++) {
//		bool flag = true;
//		for (int j = i + 1; j < t; j++) {
//			if (i != j) {
//				if (mp[i].count(j)) res.insert(j); 
//				if (mp[j].count(i)) res.insert(i); 
//			}
//		}
//		for (set<int >::iterator it = res.begin(); it != res.end(); ++it) cout << *it << endl;
//		break;
//		if (flag) cout << i << endl;
//	}
//	for (map<int, set<int > >::iterator it = mp.begin(); it != mp.end(); ++it) {
//		cout << it->first << ' ' << it->second << endl;
//	}
	return 0;
}
