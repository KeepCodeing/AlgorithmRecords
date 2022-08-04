// 区分于优化版埃氏筛，朴素筛法虽然慢一点，但是可以在筛的过程里统计素数数量... 

class Solution {
public:
    int getprime(int n) {
        int cnt = 0;
        bool primes[n + 10];
        memset(primes, 0, sizeof primes);
        primes[0] = primes[1] = true;
        // 注意题目要求的是<n的质数的数量 
        for (int i = 2; i < n; i++) {
            if (primes[i]) continue;
            cnt++;
            for (int j = i * 2; j < n; j += i) primes[j] = true;
        }
        return cnt;
    }
    int countPrimes(int n) {
        return getprime(n);
    }
};
