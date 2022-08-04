#include <iostream>
#include <map>
#define endl '\n'
using namespace std;

const int K = 1e6 + 10;

string strs[K];
int points[K][2];
int main() {
	string str;
	int sLen = 0, cnt = 0;
	int k;
	
	cin >> k;
	getchar();
	getline(cin, str);
	
	sLen = str.size();
	
	
	for (int i = 0; i < sLen; i++) {
		// ���ȼ��㵥�����꣬���ݿո�ָ� 
		string temp = "";
		int l = i, r = i;
		while (str[r] != ' ' && r < sLen) temp += str[r++];
		i = r;
		// ���������������Ӧͷβ��������� 
		points[cnt][0] = l;
		points[cnt][1] = r - 1;
		strs[cnt++] = temp;

//		cout << strs[cnt - 1] << ' ' << points[cnt - 1][0] << ' ' << points[cnt - 1][1] << endl;
	}
	
	// ֮��ɨ��[x, x + k]�����ڵĵ��ʣ����Ƿ���Alice Bob����
	for (int i = 0; i < sLen; i++) {
		if (i + k >= sLen) break;
		for (int j = i; j <= i + k; j++) {
			for (int t = 0; t < cnt; t++) {
				if (points[t][0] >= i && points[t][1] <= j) cout << strs[t] << endl;
			}
//			if (points[0] <= i && points[1] <= j) cout << strs
		}
	} 
	
	return 0;
}
// This is a story about Alice and Bob. Alice wants to send a private message to Bob.

/**
 * 
 #### ��������Է���
 
 [��������Է��� - �����ƿ� (lanqiao.cn)](https://www.lanqiao.cn/problems/198/learning/)
 
 ˼·�����ǽ���Ŀ��Ҫ��ֳ������֣�����Ҫ��`Alice`��`Bob`�������ʳ��֣������ִ�Сд���ɰ��������ţ���������Ϊ���ʳ��֣�������Ϊһ���ֳ��֣�`AliceMargatroid`����`Alice`����`Bob.`�ǺϷ��ģ������Ҫ�����Ǽ�����ַ�����������`k`��
 
 ����һ�⴮�Ĵ���һ�������ǿ��Ը��ݿո�һ���ַ�����Ϊ���ɸ����ʣ�����`A B C`���Է�Ϊ`A��B��C`����������ɡ�����һ������һ��Ĳ�ͬ����������Ҫ����**�������ʼ���ַ�����ȷ�����ǵľ����Ƿ���k֮��**�����������ò���**һ�ж�ȡ**��ʽ���ո�Ҳ�������ڡ�
 
 ����õ��ʺ�����������`k`�ڱ����е����á����ȿ���ȷ����**�ַ���೬��`k`�ĵ���������ζ����Ǵ�**��������˵����һ�������ڼ����`k`֮�ڵ����С�������ǽ���һ���ַ������������ᣬ��ô�Ϳ��Եó������Ľ��ۣ�**��ֻ���ܳ�����`[x, x + k]`�����Χ��**��
 **/
