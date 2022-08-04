// �������Ż��氣��ɸ������ɸ����Ȼ��һ�㣬���ǿ�����ɸ�Ĺ�����ͳ����������... 

class Solution {
public:
    int getprime(int n) {
        int cnt = 0;
        bool primes[n + 10];
        memset(primes, 0, sizeof primes);
        primes[0] = primes[1] = true;
        // ע����ĿҪ�����<n������������ 
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
