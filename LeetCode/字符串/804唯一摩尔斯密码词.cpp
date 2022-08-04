#include <iostream>
#include <vector>
#include <set>
using namespace std;
// 分析：可以利用字符的ascii码的特性作为下标在数组里查找，没必要用map
class Solution {
public:
    int uniqueMorseRepresentations(vector<string> & words) {
    	string temp;
    	set<string > s;
    	string arr[] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.",
			"...","-","..-","...-",".--","-..-","-.--","--.."};
        for (int i = 0; i < words.size(); i++) {
        	for (int j = 0;  j < words[i].size(); j++) {
        		// 通过字符的ASCII码相减获取对应摩斯密码 
        		temp += arr[words[i][j] - 'a'];
			}
			s.insert(temp); 
			temp.clear();
		}
		// 统计集合中有多少种不重复元素，而不是通过一个变量手动计数
		// 这样当元素为1时返回却为0 
		return s.size();
    }
}; 
int main() {
	return 0;
}
