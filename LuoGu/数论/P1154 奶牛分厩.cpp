#include <iostream>
#include <cstdio>
#include <set>
using namespace std;

// ��Ŀ����˼Ӧ���Ǹ�һ�����ݣ����һ��kʹ����������ģk�Ľ��Ψһ
// Ҳ���Ǻ���Լ���෴ 

// �����ƺ���Լ��û�й�ϵ����ȻҲ�ͱ�five�Ʋ������й�ϵw��Ŀǰ����
// ��д��������ö��k��Ȼ���ǲ������ظ�... 
// ������ȻTLEw�����˼���������40...���˸�С�Ż����ɹ��õ�50w 

 
 
set<int > nset;
const int N = 5010;
int nums[N];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &nums[i]);
	}
	for (int i = 1;; i++) {
		nset.clear();
		for (int j = 1; j <= n; j++) {
			if (nset.count(nums[j] % i)) break;
			nset.insert(nums[j] % i); 
		} 
		if (nset.size() == n) {
			cout << i;
			break;
		} 
	}
//	while (n--) {
//		scanf("%d", &num);
//		for (int i = 2; i <= num / i; i++) {
//			if (!(num % i)) {
//				nset.insert(i);
//				if (i != num / i) nset.insert(num / i);  
//			}
//		}
//	}
//	for (set<int >::iterator it = nset.begin(); it != nset.end(); it++) {
//		cout << *it << ' ';
//	}
	return 0;
}
