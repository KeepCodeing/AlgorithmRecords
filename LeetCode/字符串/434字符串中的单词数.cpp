#include <iostream>
using namespace std;
// 分析：判断当前字符不为空格代表当前是个单词，判断下一个字符为空格代表单词已经完了 
class Solution {
public:
    int countSegments(string s) {
       	int cnt = 0;
       	// 加个空格是为了防止漏掉最后一个单词 
       	s += ' ';
        for (int i = 0; i < s.size() - 1; i++) {
       		if (s[i] != ' ' && s[i + 1] == ' ') cnt++;
	   	}
        return cnt;
    }
};
int main() {
	string s = "Hello, my name is John";

	return 0;
}
