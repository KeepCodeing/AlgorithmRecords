// 头文件，据说万能头要花费更多时间编译
#include <iostream>
#include <vector>
// 使用了count()函数
#include <algorithm> 
using namespace std;
// 用new来造数组
string *strs;
vector<string > s;
string *result;
int main() {
    int n;
    cin >> n;
   // new数组，语法是：变量名 = new 变量数据类型[数组大小]
    strs = new string[n];
    result = new string[n];
    string temp;
   // 输入QAQ
    for (int i = 0; i < n; i++) {
        cin >> strs[i];
    }
   // 从0~index截取字符串
    int index = 1;
   // 下面写了个死循环，所以用这个变量统计答案个数，
   // 当答案全出来了就退出循环
    int cnt = 0;
    while (true) {
     // 开始对所有字符串进行截取 
        for (int j = 0; j < n; j++) {
        // substr方法可以从当前位置向后截取pos个字符
            temp = strs[j].substr(0, index);
        // 存放截取的子串
            s.push_back(temp);
        }
        for (int i = 0; i < n; i++) {
        // count函数可以用来统计元素个数
            if (count(s.begin(), s.end(), s[i]) == 1 && s[i] != "0") {
           // 这里i就是当前最短且唯一的子串出现的位置，因为
           //vector的长度和n是一致的
                result[i] = s[i];
           // 把用过的元素标记，说明其已经是最短的了
                strs[i] = "0";
           // 答案+1
                cnt++;
            }       
        }
        if (cnt == n) break;
     // 清空vector，不然上次截取的子串也会存放在其中
        s.clear();
        index++;
    }
   // 输出答案，注意换行（虽然洛谷的评测没有卡这个）
    for (int i = 0; i < n; i++) {
        cout << result[i];
        if (i != n - 1) cout << endl;
    }
   // 记得删除数组，不然可能内存泄漏（几率不大）
    delete[] strs, result;
    return 0;
}
