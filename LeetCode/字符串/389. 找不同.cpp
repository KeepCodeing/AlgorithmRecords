// �������Ǹ�ˮ�⣬�ù�ϣ���У���ʵҲ���м����Ե�
// �����õ��ľ�����ASCII�����Ͳ�ķ�������Ϊt�и�������ַ���������t��ASCII��ĺͼ�ȥs��ASCII���
// ���ܵõ�������Ǹ��ַ���ASCII��... 
class Solution {
public:
    char findTheDifference(string s, string t) {
        int sum = 0;
        for (auto i : t) sum += i;
        for (auto i : s) sum -= i;
        return sum;
    }
};
