#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// ��ɢ��������������������⣬���������ǽ���Ҫ����ӳ�䵽������±���
// ��ֵ��ϴ�������ԭ����������ʱ�Ϳ���ʹ�á� 

// �����ɢ����������Ͱ�ţ��������±�ӳ����ֵͬ��Ԫ�أ���Ԫ��ֵ�����ʱ��
// ���ò����ˣ���ôΪʲôҪ��Ͱ���أ���ΪͰ�ŵ�Ч�ʸߣ���ѯֻ��Ҫȡ�±꼴��
// ����ɢ�������ڴ˻����Ͻ����˶��ֲ��ң���������ȥ�أ���ɢ�������Ͽ��Դ洢����
// ��С��Ԫ�ز���Ҳ�ܿ��ٲ��ҡ����ǿ��Խ�10ӳ�䵽�±�1,20��2,100��3,50000��4...
// �����ȥ�غ�ֻ��Ҫ�ôζ��־����ҵ���ӦԪ�ص��±꣬Ȼ��ִ�к������� 

// �����������Ԫ�� 
vector<int > alls;
// ���������Ӳ�����pair���Լ򵥵�ӳ������Ԫ�� 
vector<pair<int, int > > add, query; 
const int N = 300010;
int a[N], s[N];
int find(int x){
    int l = 0, r = alls.size() - 1;
    while (l < r){
        int mid = l + r >> 1;
        if (alls[mid] >= x) r = mid;
        else l = mid + 1;
    }
    return r + 1;
}
int main() {
	int n, m;
	cin >> n >> m;
	int x, c;
	while (n--) {
		cin >> x >> c;
		add.push_back({x, c}); 
		alls.push_back(x); 
	} 
	while (m--) {
		// �����ѯ����
		int l, r;
		cin >> l >> r;
		query.push_back({l, r});  
		// ����֮���԰Ѳ�ѯ�����ֵҲ��ӽ�ȥ�ˣ�����Ϊ��Ӳ��������䲻һ��������ȫ������
		// ��ѯ��������֣�������Ҫ���в�ѯ�͵����ٱ�֤Ҫ���������˵����� 
		alls.push_back(l);
		alls.push_back(r);  
	}
	// ���� 
	sort(alls.begin(), alls.end());
	// ȥ�أ�unique()��������αȥ�أ������Խ��ظ�Ԫ���Ƶ��������Ȼ��
	// ����һ����������ָ���һ���ظ�Ԫ�أ���ô����erase��������ɾ���ظ�Ԫ��
	alls.erase(unique(alls.begin(), alls.end()), alls.end());  
	// ������� 
	for (vector<pair<int, int > >::iterator it = add.begin(); it != add.end(); it++) {
		// �Ȳ�ѯ��Ҫ��ӵ�Ԫ�ض�ȥ�������ٽ�����Ӳ������������Ա����ظ� 
		// ��ɢ�����ֵ����ȥ 
		a[lower_bound(alls.begin(), alls.end(), it->first) - alls.begin() + 1] += it->second;
	}
	// ����ǰ׺��
	s[0] = 0;
	for (int i = 1; i <= alls.size(); i++) {
		s[i] = s[i - 1] + a[i];
	} 
	// ����ѯ��
	for (vector<pair<int, int > >::iterator it = query.begin(); it != query.end(); it++) {
		int l = lower_bound(alls.begin(), alls.end(), it->first) - alls.begin() + 1;
		int r = lower_bound(alls.begin(), alls.end(), it->second) - alls.begin() + 1;
		cout << s[r] - s[l - 1] << endl;
	} 
	return 0;
}
/*
3 3
1 2
3 6
7 5
1 3
4 6
7 8
���������
8
0
5
*/
