#include <iostream>
#include <algorithm>
using namespace std;
// ��Ŀ����������ֻ��6����9���滻��һ��6�õ��ľ��������ֵ�����û��6��˵�������滻

// �����̣�ת��תȥ̫�鷳��copy��һ�����
/*
static int n=[](){std::ios::sync_with_stdio(false);std::cin.tie(nullptr);return 0;}();

class Solution {
public:
    int maximum69Number(int num) {
        int rs = num;
        int n = num;
        int t = 1;
        while (n) {
            int temp = n % 10; //�õ����һλ��
            if(temp == 6){
                rs = num + t * 3;
            }
            n /= 10;
            t *= 10;
        }
        return rs;
    }
};
*/ 
class Solution {
public:
	string num2str(int num) {
		bool flag = false;
		string str;
		int temp;
		while (num) {
			temp = num % 10;
			str += temp + '0';
			num /= 10;
			if (temp == 6) flag = true;
		}
		
		if (flag) {
			reverse(str.begin(), str.end());
			return str;
		}
		return "";
	}
    int maximum69Number (int num) {
        string str = num2str(num);
        if (str.empty()) return num;
        cout << str << endl;
        return 0;
    }
};
int main() {
	Solution s = Solution();
	return 0;
}
