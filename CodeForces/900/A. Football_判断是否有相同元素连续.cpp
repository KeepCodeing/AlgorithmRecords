#include <iostream>
using namespace std;

// ���˰���ſ�������w����˼�ǲ����д��ڵ���7��Ԫ������һ��...
// �ȽϺ�����Ǳ�����������Ӷ���ȫû���⣬������������������˫ָ�룬����������
// �Ǹ�ѹ���ַ������⣬��ͳ���ж��ٸ�Ԫ���ظ���Ȼ�������ִ���... 

int main() {
	string str;
	cin >> str;
	bool flag = false;
	int left = 0, right = 0, sLen = str.size();
	// ȫ��Ԫ�ضԱ����˲��˳�.. 
	while (left < sLen) {
		// ��ָ�������������и���Ϊ1������һ����ͬԪ�س���ʱ��right��ʵ�Ѿ��ǲ�ͬԪ���Ǹ�
		// λ����... 
		while (str[left] == str[right]) right++;
		// ����������������Ա�֤��������Ȼ�ģ���Ϊright��ʵ��λ�ô�1 
		if (right - left >= 7) {
			flag = true;
			break;
		}
		// �ӵ�һ����ͬ��Ԫ�ؿ�ʼ��������ɨ 
		left = right;
	}
	if (flag) cout << "YES";
	else cout << "NO";
	cout << endl;
	return 0;
}
