#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

// ao������д�˸�������ˮ�������..��������Ѿ�����...

// ��Ŀ����˼�Ǹ�9������Ҫȥ��������ʹ���к�Ϊ100��˼·�����ö��֣�����Ԫ��-100-��ǰ���ǲ������ҵ���һ����
// ������ҵ�����˵����������Ҫ����ȥ����¼��������ԭ����λ�ã��������.. 

const int N = 9;
typedef map<int, int >::iterator mit;
map<int, int > nums;
int ns[N];
int main() {
	int sn = 0;
	for (int i = 0; i < N; i++) cin >> ns[i], nums[ns[i]] = i, sn += ns[i];
	mit n1, n2, mt;
	for (mit it = nums.begin(); it != nums.end(); ++it) {
		// �������160��Ҫ��ȥ20��40����������ҵ���20��Ҳ����160 - 100 - 20���õ��ľ���40����˵�����������Ƕ���� 
		mt = nums.lower_bound(sn - 100 - it->first);
		// ��Ȼ�����Ҳ�����һ�������صĵ��������Ǹ�����ģ��������ﻹҪ��֤�����������ǲ�����Ķ�����... 
		if (mt->first + it->first + 100 == sn) {
			n1 = it, n2 = mt;
			break;
		}
	}
	for (int i = 0; i < N; i++) {
		if (i == n1->second || i == n2->second) continue;
		cout << ns[i] << endl;
	}
	return 0;
}
