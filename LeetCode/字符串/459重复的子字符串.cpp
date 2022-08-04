#include <iostream>
using namespace std;
/*
首先一个字符串t重复N次后得到重复字符串s， 那么s = N * t，那么这样的重复字符串截取t后得到的字符串也是重复字符串。
然后得到s1 = s+s，现在的s1 = 2N * t，有2N个t组成。
现在把s1的前后减去一个字符，那么前后的两个t就不再作为重复子字符串而存在了，此时s1相当于(2N-2)*t，如果此时s1中依然能够找到s，说明s完全由t组成。
举例:
s = abc|abc; // 2abc
s+s = abc|abc|abc|abc; // 4abc
s1 = a|bcabcabcab|c = bcabcabcab; // bc + 2*abc + ab
因为一个重复子字符串删除一个子字符串后依然是重复子字符串。
*/
/*
如果一个字符串可以由多个重复子串构成，即具有循环节 设最小循环节用a来表示，他代表通过子串a重复多次可以构成s 即s换成a来表示就是aa···aaa，由多少个最小循环节a构成s，那么就有几个a
找循环节一个一个对比比较麻烦，最简单方法就是s+s就可以直接增加多一倍的循环节
假设原来s=aaaa，那ss=s+s=aaaa aaaa 因为是不断重复的循环节，可以通过简单的屏蔽的第一个字符，然后再在ss中寻找s 因为屏蔽第一个字符，即第一个最小循环节被破坏，所以找到的s应该是从第二个循环节开始
但倘若不是由一个子串重复构成 即s=abcd，那ss=abcd abcd=s+s 屏蔽掉第一个字符，又因不匹配，所以在ss中寻找s，一定是对应着新增s的位置，即s.size()处
*/
// 类似字符串旋转那个题，这里同样是二倍的字符串，不过要掐头去尾 
// 复制的C++解并没有这样，可见查找子字符串的题很可能就是这种接法 
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        return (s + s).find(s, 1) != s.size();
    }
};
int main() {
	return 0;
}
