#include <iostream>
#include <set>
using namespace std;

// 第一次团队赛的题...，题解方法挺多，记得那时候做坠毁在去重上了
// 虽然知道其它语言有去重的数据结构，但是那时用的是C呢（苦笑） 

// 谔谔，还是错了，借鉴了下题解 

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
	// 获取头指针，然后向后偏移，这样就不用在for里计数了 
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
