// 以前做过的题，但是卡了很久w，中途打算看下以前的代码都没找到文件...
// 大概率也是颓废了，不过who care.... 

// 那么总结下思路，以前写的大概和这个不一样，不过也不太记得了，不然也不会卡这么久w..
// 首先想下什么是公共前缀，公共前缀应该指的是所有字符串开头n位字符相同，既然似乎所有
// 字符串，那么我们可以将其中任意一个字符串映射到trie里那么思考下这个Trie树长什么样子
// 可以简单的把它看成一个链表。那么怎么知道后面的字符串和Trie树里的字符串有多少位相同
// 呢？ 将其它字符串放到Trie树里查找就行，Trie树可以依次对比每一位字符，如果有不同返
// 回不同的是第几个字符就行，那么最后的最长前缀就由最短那个前缀的长度决定... 

const int N = 1e5 * 5 + 10;
class Solution {
public:
    int son[N][26], idx = 0;
    // 映射字符串，不用cnt，因为只用映射一个字符串进去 
    void add(string str) {
        int sLen = str.size(), p = 0, cur;
        for (int i = 0; i < sLen; i++) {
            cur = str[i] - 'a';
            if (!son[p][cur]) son[p][cur] = ++idx;
            // 写成了son[i][cur]
            p = son[p][cur];
        }
    }
    // 查找字符串，过程更像是比较“聪明”的暴力 
    int fd(string str) {
        int sLen = str.size(), p = 0, cur, pre = 0;
        for (int i = 0; i < sLen; i++) {
            cur = str[i] - 'a';
            // 当前字符串哪一位不在tire树里，它的前缀长度就是i（i从0开始） 
            if (!son[p][cur]) return i;
            p = son[p][cur];
        }
        // 全在Trie树里那公共长度就是字符串长度... 
        return sLen;
    }
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        if (strs.size() == 1) return strs[0];
        memset(son, 0, sizeof son);
        int sLen = strs.size();
        // 把第一个字符串映射到Trie里 
        add(strs[0]);
        int res = INT_MAX;
        for (int i = 1; i < sLen; i++) {
            if (strs[i] == "")  res = 0;
            // 必须加这个判断，不然会TLE，这个判断的作用就是当出现了空字符或者有字符串完全不同，就退出循环
			// 这两种情况都是一样的，即最长公共前缀为空... 
            if (!res) break;
            res = min(res, fd(strs[i]));
        }
        return strs[0].substr(0, res);
    }
};
