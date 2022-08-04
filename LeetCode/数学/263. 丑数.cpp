// bool checker(int n) {
//     return n != 2 && n != 3 && n != 5;
// }
// class Solution {
// public:
//     bool isUgly(int num) {
//         for (int i = 2; i <= num / i; i++) {
//             while (!(num % i)) {
//                 if (checker(i)) return false;
//                 num /= i;
//             }
//         }
//         if(num > 1 && checker(num)) return false;
//         return true;
//     }
// };
// 用试除法坠毁了w，可能是因为有负数的原因，不过还是过了很多样例ww，真正的最后一道题... 
class Solution {
public:
    bool isUgly(int num) {
        if(num<=0) return false;
        while(num%2==0)
            num/=2;
        while(num%3==0)
            num/=3;
        while(num%5==0)
            num/=5;
        return num==1;
    }
};

