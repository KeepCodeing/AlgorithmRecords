#include <iostream>
#include <vector>
using namespace std;
// ���������԰����ֿ����ַ�����ÿ�εݹ鶼��һλ��Ȼ���ڵݹ�Ĺ����м�֦���ж��Ƿ����ַ��ظ���
// ����ͳ�������ַ����ĸ�������n�������ȥ�����ַ����ĸ������ǲ��ظ��ַ����ĸ���

class Solution {
public:
	// ����׹��... 
//	vector<char > temp;
//	void dfs(int level, int deepth, string str) {
//		if (level == deepth) {
//			for (int i = 0; i < temp.size(); i++) {
//				cout << temp[i];
//			}
//			cout << endl;
//			return;
//		}
//		for (char i = '1'; i <= '9'; i++) {
//			// str.push_back(i); 
//			temp.push_back(i);
//			dfs(level + 1, deepth, str);
//			// str.erase(str.end()); 
//			// cout << str << endl;
//			temp.pop_back();
//		}
//	}
/*n=1: res=10

n=2: res=9*9+10=91 # ��λ����һλֻ��Ϊ1-9���ڶ�λֻ��Ϊ�ǵ�һλ����������һλ�������н��

n=3: res=9 * 9 * 8+91=739 # ��λ����һλֻ��Ϊ1-9���ڶ�λֻ��Ϊ�ǵ�һλ����������λֻ��Ϊ��ǰ��λ������������λ�������н��

n=4: res=9 * 9 * 8 * 7+739=5275 # ͬ���Ʒ�*/
    int countNumbersWithUniqueDigits(int n) {
    	if(n <= 1) return 1; 
    	int result = 10, Mysum = 9;
        for (int i = 1; i < min(n, 10); i++) {
        	Mysum *= 10 - i;
            result += Mysum;
        }
		return 0;
    }
}; 
int main() {
	Solution s = Solution();
	s.countNumbersWithUniqueDigits(2); 
	return 0;
}
