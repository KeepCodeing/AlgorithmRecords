#include <iostream>
#include <vector>
using namespace std;
// �����ٶ��������ռ䷭ת�ַ�����ֻ����O(1)�Ķ���ռ䣬������STL����������˫ָ�뷭ת 

// ˫ָ�뷭ת����һ���м�������һ��ֵ��Ȼ��������ָ�뿿£��ֱ����ײ 
class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0, right = s.size() - 1;
        while (left < right) {
        	char temp;
        	temp = s[left];
        	s[left] = s[right];
        	s[right] = temp;
        	left++;
        	right--;
		}
    }
}; 
int main() {
	Solution s = Solution();
	vector<char > v;
	char c;
	while (cin >> c) v.push_back(c); 
	s.reverseString(v);
	for (int i = 0; i < v.size(); i++) cout << v[i] << ' ';
	return 0;
}
