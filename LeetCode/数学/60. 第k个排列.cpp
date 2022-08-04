// 水的最后一题...一看数据范围很小直接暴力了w，正解应该是康托展开...另外要注意虽然写成res = res + num的形式不会出现res += num
// 的乱码，但是数字还是要强转一下... 
class Solution {
public:
    vector<int > vec;
    string getPermutation(int n, int k) {
        for (int i = 1; i <= n; i++) vec.push_back(i);
        string res = "";
        do {
            if (!(--k)) {
                for (auto& i : vec) res = res + (char)(i + '0');
                break;
            }
        } while (next_permutation(vec.begin(), vec.end()));
        return res;
    }
};
