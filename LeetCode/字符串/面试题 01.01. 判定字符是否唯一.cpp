// ���������ݽṹ�����һ���뵽������...�ƺ��ǵ�һ���������ģ� ���������ɣ�������Ѿ�������������..�� 
class Solution {
public:
    bool isUnique(string astr) {
        if (astr.empty()) return true;
        sort(astr.begin(), astr.end());
        for (int i = 0; i < astr.size() - 1; i++) 
            if (astr[i] == astr[i + 1]) return false;
        return true;
    }
};
