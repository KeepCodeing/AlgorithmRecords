// ˮ�����һ��...һ�����ݷ�Χ��Сֱ�ӱ�����w������Ӧ���ǿ���չ��...����Ҫע����Ȼд��res = res + num����ʽ�������res += num
// �����룬�������ֻ���Ҫǿתһ��... 
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
