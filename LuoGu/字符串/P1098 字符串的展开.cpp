#include <iostream>
#include <algorithm>
using namespace std;
bool isNum(char c) {
	return c >= '0' && c <= '9';
}
bool isAlpha(char c) {
	return c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z';
}
int main() {
	int p1, p2, p3;
	cin >> p1 >> p2 >> p3;
	string str, result;
	cin >> str;
	int sLen = str.size();
	for (int i = 0; i < sLen; i++) {
		if (str[i] == '-') {
			// ���ǵ��ַ�����β���ܳ���-�����������޷�
			// �������� 
			if (i != 0 && i != sLen - 1) {
				char left = str[i - 1], right = str[i + 1];
				// �������ұ�ֻ����ߴ�1���������ɾ��- 
				if (left + 1 == right) {
					continue;
				} 
				// �ұߴ�����߿�ʼ������ȥ��-������ԭ������ȥ������Ҫ����������ַ�
				// ��ȻС���ұ��ַ����ǲ���ͬһ�����͵����������9-A 
				if (right > left && (isAlpha(left) && isAlpha(right) || isNum(left) && isNum(right))) {
					string temp;
					for (char j = left; j <= right; j++) {
						// p1 == 3�����*�������ж��Ƿ�����ĸ�����ﶼ�ж�����p1�������ظ����� 
						char t = (p1 != 3 ? j : '*');
						if (isAlpha(t) && p1 != 3) {
							if (p1 == 1) t = tolower(t); 
							else t = toupper(t);
						}
						// ����p2���ظ� 
						for (int k = 1; k <= p2; k++) {
							// ������β�ַ����в�������������Ϊ��ֻ������-������Ҫ�����ж��� 
							if (j == left || j == right) continue;
							temp += t;
						}
					}
					// ����p3�ĵ��� 
					if (p3 == 2 && p1 != 3) {
						int l = 0, r = temp.size() - 1;
						// �����ˣ�����֮ǰд����r++.. 
						while (l < r) swap(temp[l++], temp[r--]);
					}
					result += temp;
					continue;
				}
			}
		}
		result += str[i];
	}	
	cout << result;
	return 0;
}
