#include <iostream>
using namespace std;

// ����Ǹ�ģ���⣬����Ҫ�Լ��ж��Ƿ������ȫ�޷��ó��𰸣��������ø�������ʲô��... 
// �������˵��µڶ�����������ȥw���ֿ��˱�ŷ���ԭ�ַ������ܷ����ı䣬����s1,s2���Ǵ�ԭ�ַ���������... 

// ��������w 
const int N = 777;
int main() {
	int T, len, cnt;
	string s1, s2, s12;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		cin >> len;
		cin >> s1 >> s2 >> s12;
		// ������Ϊ�˹������ĳ���1��w... 
		cnt = 0; 
		while (cnt < N) {
			// ������ַ�����ȣ����˳���ע�����������жϵ���ȣ��������������Ϊ���һ��ʼs1+s2==s12�任�Ĵ�������0... 
			if (s1 + s2 == s12) {
				cout << i << ' ' << cnt << endl;
				break;
			}
			// �����´������ﲻ�ܸ�ԭ�������ø��´��ݴ���... 
			string temp = "";
			for (int i = 0; i < len; i++) temp = temp + s2[i] + s1[i];
			s1 = temp.substr(0, len), s2 = temp.substr(len);  
			cnt++;
		}
		if (cnt == N) cout << i << ' ' << -1 << endl;
	}
	return 0;
}
