// ͷ�ļ�����˵����ͷҪ���Ѹ���ʱ�����
#include <iostream>
#include <vector>
// ʹ����count()����
#include <algorithm> 
using namespace std;
// ��new��������
string *strs;
vector<string > s;
string *result;
int main() {
    int n;
    cin >> n;
   // new���飬�﷨�ǣ������� = new ������������[�����С]
    strs = new string[n];
    result = new string[n];
    string temp;
   // ����QAQ
    for (int i = 0; i < n; i++) {
        cin >> strs[i];
    }
   // ��0~index��ȡ�ַ���
    int index = 1;
   // ����д�˸���ѭ�����������������ͳ�ƴ𰸸�����
   // ����ȫ�����˾��˳�ѭ��
    int cnt = 0;
    while (true) {
     // ��ʼ�������ַ������н�ȡ 
        for (int j = 0; j < n; j++) {
        // substr�������Դӵ�ǰλ������ȡpos���ַ�
            temp = strs[j].substr(0, index);
        // ��Ž�ȡ���Ӵ�
            s.push_back(temp);
        }
        for (int i = 0; i < n; i++) {
        // count������������ͳ��Ԫ�ظ���
            if (count(s.begin(), s.end(), s[i]) == 1 && s[i] != "0") {
           // ����i���ǵ�ǰ�����Ψһ���Ӵ����ֵ�λ�ã���Ϊ
           //vector�ĳ��Ⱥ�n��һ�µ�
                result[i] = s[i];
           // ���ù���Ԫ�ر�ǣ�˵�����Ѿ�����̵���
                strs[i] = "0";
           // ��+1
                cnt++;
            }       
        }
        if (cnt == n) break;
     // ���vector����Ȼ�ϴν�ȡ���Ӵ�Ҳ����������
        s.clear();
        index++;
    }
   // ����𰸣�ע�⻻�У���Ȼ��ȵ�����û�п������
    for (int i = 0; i < n; i++) {
        cout << result[i];
        if (i != n - 1) cout << endl;
    }
   // �ǵ�ɾ�����飬��Ȼ�����ڴ�й©�����ʲ���
    delete[] strs, result;
    return 0;
}
