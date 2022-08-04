#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

// C语言网做过了w，不想再写直接水过去算了... 

const int N = 40, M = 10, K = 7;
int trick[M], bucket[N];
int res[M];
int main() {
    int n, t, cnt;
    scanf("%d", &n);
    for (int i = 1; i <= K; i++) scanf("%d", &trick[i]);
    for (int i = 1; i <= n; i++) {
        memset(bucket, 0, sizeof bucket);
        cnt = K + 1;
        for (int j = 1; j <= K; j++) {
            scanf("%d", &t);
            bucket[t]++;
        }
        // 遍历桶，然后统计出现了几个数字，这里用自减代替了下标，如果用自增结果会是倒着的.. 
        for (int j = 1; j <= K; j++) {
            if (bucket[trick[j]]) cnt--;
        }
        // 统计有多少个票.. 
        res[cnt]++;
    }
    for (int i = 1; i <= K; i++) cout << res[i] << ' ';
    return 0;
}
