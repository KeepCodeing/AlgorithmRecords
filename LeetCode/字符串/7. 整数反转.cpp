// ��ʵ�þ�֮ǰ�ʹ򿪹�����⣬����������...�������ַ�����ת���ַ�����Ȼ��ת��ת�����Աȣ���������long long
// �е㲻������ĿҪ��... 
class Solution {
public:
    string renum(string& str, int l) {
        int left = l, right = str.size() - 1;
        while (left < right) swap(str[left++], str[right--]);
        return str;
    }
    int reverse(int x) {
        stringstream ss;
        long long res;
        string temp;
        ss << x, ss >> temp, ss.clear();
        if (x < 0) renum(temp, 1);
        else renum(temp, 0);
        ss << temp, ss >> res;
        if (res > 2147483647 || res < -2147483648) return 0;
        return res;
    }
};
