// ��ǰ�������⣬���ǿ��˺ܾ�w����;���㿴����ǰ�Ĵ��붼û�ҵ��ļ�...
// �����Ҳ���Ƿ��ˣ�����who care.... 

// ��ô�ܽ���˼·����ǰд�Ĵ�ź������һ��������Ҳ��̫�ǵ��ˣ���ȻҲ���Ῠ��ô��w..
// ��������ʲô�ǹ���ǰ׺������ǰ׺Ӧ��ָ���������ַ�����ͷnλ�ַ���ͬ����Ȼ�ƺ�����
// �ַ�������ô���ǿ��Խ���������һ���ַ���ӳ�䵽trie����ô˼�������Trie����ʲô����
// ���Լ򵥵İ�������һ��������ô��ô֪��������ַ�����Trie������ַ����ж���λ��ͬ
// �أ� �������ַ����ŵ�Trie������Ҿ��У�Trie���������ζԱ�ÿһλ�ַ�������в�ͬ��
// �ز�ͬ���ǵڼ����ַ����У���ô�����ǰ׺��������Ǹ�ǰ׺�ĳ��Ⱦ���... 

const int N = 1e5 * 5 + 10;
class Solution {
public:
    int son[N][26], idx = 0;
    // ӳ���ַ���������cnt����Ϊֻ��ӳ��һ���ַ�����ȥ 
    void add(string str) {
        int sLen = str.size(), p = 0, cur;
        for (int i = 0; i < sLen; i++) {
            cur = str[i] - 'a';
            if (!son[p][cur]) son[p][cur] = ++idx;
            // д����son[i][cur]
            p = son[p][cur];
        }
    }
    // �����ַ��������̸����ǱȽϡ��������ı��� 
    int fd(string str) {
        int sLen = str.size(), p = 0, cur, pre = 0;
        for (int i = 0; i < sLen; i++) {
            cur = str[i] - 'a';
            // ��ǰ�ַ�����һλ����tire�������ǰ׺���Ⱦ���i��i��0��ʼ�� 
            if (!son[p][cur]) return i;
            p = son[p][cur];
        }
        // ȫ��Trie�����ǹ������Ⱦ����ַ�������... 
        return sLen;
    }
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        if (strs.size() == 1) return strs[0];
        memset(son, 0, sizeof son);
        int sLen = strs.size();
        // �ѵ�һ���ַ���ӳ�䵽Trie�� 
        add(strs[0]);
        int res = INT_MAX;
        for (int i = 1; i < sLen; i++) {
            if (strs[i] == "")  res = 0;
            // ���������жϣ���Ȼ��TLE������жϵ����þ��ǵ������˿��ַ��������ַ�����ȫ��ͬ�����˳�ѭ��
			// �������������һ���ģ��������ǰ׺Ϊ��... 
            if (!res) break;
            res = min(res, fd(strs[i]));
        }
        return strs[0].substr(0, res);
    }
};
