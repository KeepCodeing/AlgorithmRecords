#include <iostream>
#include <map>
using namespace std;
// ˼·��ÿ��������϶��������ұ��д�����ַ������������ǿ��������������ַ�ʱ
// �ж����ұߵ��ַ��� 

// �Լ���������ٷ������ܹ� 
class Solution {
public:
    int romanToInt(string s) {
        int res = 0;
        for (int i = 0; i < s.size(); i++) {
        	if (s[i] == 'I') {
                if (s[i + 1] == 'V') {res += 4;i++;}
                else if (s[i + 1] == 'X') {res += 9;i++;}
                else res += 1;
            } else if (s[i] == 'X') {
                if (s[i + 1] == 'L') {res += 40;i++;}
                else if (s[i + 1] == 'C') {res += 90;i++;}
                else res += 10;
            } else if (s[i] == 'C') {
                if (s[i + 1] == 'D') {res += 400;i++;}
                else if (s[i + 1] == 'M') {res += 900;i++;}
                else res += 100;
            } else if (s[i] == 'L') {
            	res += 50;
			} else if (s[i] == 'D') {
				res += 500;
			} else if (s[i] == 'V') {
				res += 5;
			} else if (s[i] == 'M') {
				res += 1000;
			}
		}
        return res;
    }
};
// ��������˼·���ȰѸ��ֿ��ܵ��������ִ���һ��map���Ϊ���п��ܽ�
// ������λ�������ڱ���ʱ�����ȴӵ�ǰ�ַ���ʼ���ȡһ���ַ���Ȼ����map
// �������û�ж�Ӧ�ļ�������У�˵����ǰ�ַ���Ϊ�������֣�����˵����ǰ
// �ַ�����Ϊ�������֣��Ͳ����ȡһλ��ֱ����map���Ҹ��ַ���Ӧ��ֵ



int solve(string s) {
	map<string, int > m;
	// �о��������ֵĽ�� 
	m["I"] = 1;
	m["IV"] =  4;
    m["V"] =  5;
    m["IX"] =  9;
    m["X"]  = 10;
    m["XL"]  = 40;
    m["L"]  = 50;
    m["XC"]  = 90;
    m["C"]  = 100;
    m["CD"] =  400;
    m["D"]  = 500;
    m["CM"] =  900;
    m["M"] =  1000;
    int res = 0;
	for (int i = 0; i < s.size(); i++) {
		// ��ʼ�ӵ�ǰλ���ȡ���ַ��� 
		//������������֣�������ֵ 
		cout << s.substr(i, 2)<< endl;
		if (m.count(s.substr(i, 2)) && i != s.size() - 1) {
			res += m[s.substr(i, 2)];
			// ע����������������������ظ�ʹ��ĳ���ַ������ 
			i++;
		} else {
			// ��������������֣����Լ���ֵ 
			// ��Ϊ����ֱ��ȡ��õ���һ���ַ���������key��Ҫ������
			// ��ȡ���ַ����ķ�ʽȡ 
			// cout << s.substr(i, 1)<< endl;
			res += m[s.substr(i, 1)];
		}
	}
	return res;
}
 
int main() {
	Solution s  = Solution();
	string t;
	cin >> t;
	cout << solve(t);
	return 0;
}
