// 试除法nlogn超时了...
// 简单点的方式是先筛出来2亿以内的素数，然后二分枚举... 
/* C的正确，不想管了... 
int GetBit(int x) {
	int i = 0;
	if (x == 0)
		return 1;

	while (x) {
		x = (x - (x % 10)) / 10;
		i++;
	}
	return i;
}

int reverseInt(int x, int nbit) {
	long long rev = x % 10;
	long long res = x / 10;

	while (res != 0) {
		rev = rev * 10 + res % 10;
		res = res / 10;
	}

	return (int)rev % ((int)pow(10, nbit));
}

int formatNextPalindrome(int base, int nbit)
{
	int hf = nbit / 2;
	int hfM = nbit - hf;
	int hf10 = (int)pow(10, hf);
	int hfM10 = (int)pow(10, hfM);
	int hight;
	int low;
	if ((base == 9) || (base == 10))
		return 11;

    if (nbit%2==0)
        return (int)pow(10, nbit) + 1;
	if (hf == 0) {
		return base + 1;
	}

	hight = base / hf10;
	low = reverseInt(hight, hf);
	if (low > base% hf10) {		
		return hight * hf10 + low;
	}

	hight++;
	low = reverseInt(hight, hf);
	return hight * hf10 + low;
}


bool isPrime(int num) {
	if (num <= 3) {
		return num > 1;
	}
	if (num % 6 != 1 && num % 6 != 5) {
		return false;
	}
	int sqrtX = (int)sqrt(num);
	for (int i = 5; i <= sqrtX; i += 6) {
		if (num % i == 0 || num % (i + 2) == 0) {
			return false;
		}
	}
	return true;
}

int primePalindrome(int N) {
	N--;
	while (1) {
		N = formatNextPalindrome(N, GetBit(N));
		if (isPrime(N)) {
			break;
		}
	}
	return N;
}
*/ 
class Solution {
public:
    bool checker(string str) {
        int left = 0, right = str.size() - 1;
        while (left < right) {
            if (str[left++] != str[right--]) return false;
        }
        return true;
    }
    bool primes(int n) {
        bool flag = false;
        for (int i = 2; i <= n / i; i++) {
            while (!(n % i)) {
                flag = true;
                n /= i;
            }
        }
        if (n > 1 && !flag) return true;
        return false;
    }
    int primePalindrome(int N) {
        stringstream ss;
        string temp;
        for (int i = N;; i++) {
            if (primes(i)) {
                ss << i, ss >> temp;
                if (checker(temp)) return i;
                ss.clear();
            }
        }
        return 0;
    }
};
