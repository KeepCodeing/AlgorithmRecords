// ϲ���ּ���ͷ�ļ�����
#include <iostream>
#include <set>
using namespace std;
struct leaf {
    string type, color;
   // �X�m��ǰ����֪�������ֳ�ʼ����ʽ...��������ʼ���Ϳ���
   // �����ٴ���һ������Ȼ�����������
    leaf(string t, string c) : type(t), color(c) {};
   // ע�������ṩ������������const {...}
    bool operator<(const leaf& f) const {
      // ���ǲ�������set�ڲ�Ԫ�ص�����˳������ֻ��ʵ����
      // �Աȼ���
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
      // ����Ԫ�أ�set��������Զ�ȥ�����ϻ���
        s.insert((leaf){t, c}); 
    }
    // ���set��size���ǲ�ͬԪ�ظ���
    cout << s.size();
    return 0;
}
