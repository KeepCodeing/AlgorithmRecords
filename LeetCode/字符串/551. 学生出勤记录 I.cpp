#include <iostream>
#include <algorithm>
using namespace std;

// ������ͳ����A�ĸ������������1��˵�����ܻ�,����������Ľⷨ���ж�LLL�Ƿ���ֹ���
// ��Ŀ˵LL���㣬��ôLLL��LLLL���㣬�⼸��L����һ��һ��������������� 

class Solution {
public:
    bool checkRecord(string s) {
        if (s.size() == 0 || s.empty()) return fasle;
        if (count(s.begin(), s.end(), 'A') > 1) return false;
        if (s.find("LLL") != s.npos) return false;
        return true;
    }
};

int main() {
	return 0;
}
