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
			// 如果还有人，就直接循环加到那个位置 
			if (cnt < st.size()) {
				for (int j = 0; j < cnt; j++) it++;
				printf("%d\n", *it);
			} 
			// 如果前面没有那么多人，就直接输出尾部的元素就行，注意end只是个标记... 
			else printf("%d\n", *(--st.end()));
			cnt++;
		}
	}
	return 0;
}
