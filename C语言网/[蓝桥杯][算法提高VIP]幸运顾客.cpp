#include <iostream>
#include <cstdio>
#include <set>
using namespace std;
set<int > st;
int main() {
	int n, num;
	scanf("%d", &n);
	for (int i = 0, cnt = 0; i < n; i++) {
		scanf("%d", &num);
		if (num != -1) st.insert(num);
		else {
			set<int >::iterator it = st.begin();
			// ��������ˣ���ֱ��ѭ���ӵ��Ǹ�λ�� 
			if (cnt < st.size()) {
				for (int j = 0; j < cnt; j++) it++;
				printf("%d\n", *it);
			} 
			// ���ǰ��û����ô���ˣ���ֱ�����β����Ԫ�ؾ��У�ע��endֻ�Ǹ����... 
			else printf("%d\n", *(--st.end()));
			cnt++;
		}
	}
	return 0;
}
