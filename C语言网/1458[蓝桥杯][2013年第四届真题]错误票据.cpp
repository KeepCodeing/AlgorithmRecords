#include <iostream>
#include <map>
using namespace std;

// ͻȻ�뵽������map��������Ϊȥ�غ��ж��Ƿ����������䶼�������
// ��setֻ�����ȥ�� 

// ������Ŀ�����Ķ���ո��ƺ����ڰ�ʾ���ַ�����ȡ���������ݷ�Χû��
// ���⣬���ض��һ�� 

// �����о������Ҳ����������� 

// ��������ʾ����Ĭ��������ˣ�����ֻ�öԱ�ǰһ������
// ��һ�����Ĳ�ֵ���� 
map<int, int > mp;
int main() {
	int n;
	cin >> n;
	int t;
	while(cin >> t) {
		mp[t]++;
	} 
	int br, un;
	// ��ȡ����һ�����������ǲ����ظ��ˣ�������Ŀ˵��
	// ���ź���С�Ų����ظ�������������ʵ�����ж� 
	map<int, int >::iterator it = mp.begin();
	int last = it->first;
	if (mp[last] > 1) un = last;
	it++;
	// �����ζԱ�ǰһ�����ǲ��ǱȺ�һ����С1 
	while(it != mp.end()) {
		if (it->first - 1 != last) {
			br = last;
		}
		if (it->second > 1) {
			un = it->first;
		}
		last = it->first;
		it++;
	}
	// ���Ҫ�Ѷϵ��ļ���ȫ 
	cout << br + 1 << ' ' << un;
	return 0;
}
