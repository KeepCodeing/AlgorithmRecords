// ��ϰ��w�����ڸ�ϰ�ߴ�����ʵ������Ԥϰww������LeetCode�ϵļ򵥴��������w��ǰ���������ʵ��ûд�㷨�⣬��������ȫ��
// ���ڸ�繤����֮��Ķ���...Ҳ�������Լ������ǰ���ύ����naive�����Ƿ�����˵�Լ������Ѿ�ѧ�˰����㷨�ɣ��ƺ����Ǻ�����
// ����... 
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        long long temp = 0, t = x;
        while (x) {
            temp = temp * 10 + x % 10;
            x /= 10;
        }
        return temp == t;
        // stringstream ss;
        // string str;
        // ss << x, ss >> str, ss.clear();
        // int left = 0, right = str.size() - 1;
        // while (left < right) {
        //     if (str[left++] != str[right--]) return false;
        // }
        // return true;
    }
};
