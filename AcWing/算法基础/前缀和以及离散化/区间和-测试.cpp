#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// ��򼸱����ӡ�� 

const int N = 300010;
int a[N], s[N];
vector<int > alls;
vector<pair<int, int > > add, query;
int find(int x) {
	// +1����Ϊ�����趨���±��Ǵ�1��ʼ�� 
	return lower_bound(alls.begin(), alls.end(), x) - alls.begin() + 1;
}
int main() {
	int n, m;
	cin >> n >> m;
	while (n--) {
		int x, c;
		cin >> x >> c;
		alls.push_back(x); 
		add.push_back({x, c}); 
	}
	while (m--) {
		int l, r;
		cin >> l >> r;
		// ���̣�֮ǰ�����ˣ�Ҫ����Щ��������������һ�����ᣬ��������������Ÿ��̶ֿ�
		// ����̶Ⱦ���l��r��x�������a�����������ͳ������͵�... 
		alls.push_back(l);
		alls.push_back(r);
		query.push_back({l, r});   
	}
	sort(alls.begin(), alls.end());
	alls.erase(unique(alls.begin(), alls.end()), alls.end());
	// �����£�����ӵĹ��̱���Ҫ��ȥ�غ���ɣ��������������ʱ��ֱ��������Ȼ������ظ� 
	for (vector<pair<int, int > >::iterator it = add.begin(); it != add.end(); it++) {
		// ��������ֵ������[1,3]��2,��6����Ӧִ�еĲ�������1 2
		// 3 6��ת����a����a[1]=2,a[2]=6��Ȼ������������ǰ׺��
		// ͳ������� 
		a[find(it->first)] += it->second;
	}
	s[0] = 0;
	// ǰ׺��ͳ������� 
	for (int i = 1; i <= alls.size(); i++) {
		s[i] = s[i - 1] + a[i];
	}
	for (vector<pair<int, int > >::iterator it = query.begin(); it != query.end(); it++) {
		int l = find(it->first), r = find(it->second);
		cout << s[r] - s[l - 1] << endl;
	}
	return 0;
}
