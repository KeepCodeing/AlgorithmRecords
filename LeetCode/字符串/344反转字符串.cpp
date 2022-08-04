#include <iostream>
#include <vector>
using namespace std;
// 不开辟额外的数组空间翻转字符串，只能用O(1)的额外空间，不能用STL，可以利用双指针翻转 

// 双指针翻转：用一个中间变量存放一个值，然后让左右指针靠拢，直到相撞 
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
