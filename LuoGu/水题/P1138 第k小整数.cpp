#include <iostream>
#include <set>
using namespace std;

// ��һ���Ŷ�������...����ⷽ��ͦ�࣬�ǵ���ʱ����׹����ȥ������
// ��Ȼ֪������������ȥ�ص����ݽṹ��������ʱ�õ���C�أ���Ц�� 

// ���̣����Ǵ��ˣ����������� 

set<int > s;
int main() {
	int n, k, t;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		 cin >> t;
		 s.insert(t); 
	}
	if (s.size() < k) {
		cout << "NO RESULT";
		return 0;
	}
	// ��ȡͷָ�룬Ȼ�����ƫ�ƣ������Ͳ�����for������� 
	set<int >::iterator it = s.begin();
	for (int i = 0; i < k - 1; i++) {
		it++;
	}
	cout << *it;
	return 0;
}

/*
#include <stdio.h>
#include <stdlib.h>
#define N 10000
int cmp (const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}
int main() {
    int n, k, num, index = 0, flag = 1;
    int array[N];
    scanf("%d%d", &n, &k);
    if (k > n) {
        printf("NO RESULT");
        return 0;
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &num);
        if (i == 0) {
            array[index++] = num;
        } else {
            for (int j = 0; j < index; ++j) {
                if (array[j] == num) {
                    flag = 0;
                    break;
                }
                flag = 1;
            }
            if (flag) {
                array[index++] = num;
            }
        }
    }
    qsort(array, index, sizeof(int), cmp);
    printf("%d", array[k - 1]);
    return 0;
}
*/
