// 喜闻乐见的头文件导入
#include <iostream>
#include <set>
using namespace std;
struct leaf {
    string type, color;
   // 蒟蒻以前还不知道有这种初始化方式...，这样初始化就可以
   // 不用再创建一个变量然后填充数据了
    leaf(string t, string c) : type(t), color(c) {};
   // 注意这里提供的排序函数，是const {...}
    bool operator<(const leaf& f) const {
      // 我们并不关心set内部元素的排序顺序，所以只用实现下
      // 对比即可
        if (type != f.type) return type > f.type;
        return color > f.color;
    } 
}; 

set<leaf > s;
int main() {
    int n;
    cin >> n;
    string t, c;
    for (int i = 0; i < n; i++) {
        cin >> t >> c;
      // 插入元素，set会帮我们自动去除（废话）
        s.insert((leaf){t, c}); 
    }
    // 最后set的size即是不同元素个数
    cout << s.size();
    return 0;
}
