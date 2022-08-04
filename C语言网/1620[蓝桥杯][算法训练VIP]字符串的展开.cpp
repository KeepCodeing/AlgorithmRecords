#include <iostream>
#include <algorithm>
using namespace std;

// ���̣�������ϵ��Ǹ���һģһ��... 

bool isAlpha(char c) {
	return c >= 'a' && c <= 'z';
} 
bool isNum(char c) {
	return c >= '0' && c <= '9';
}
int main() {
	int p1, p2, p3;
	string str;
	string result;
	cin >> p1 >> p2 >> p3;
	cin >> str;
	int sLen = str.size();
	// ���ȿ�����-�����ڿ�ͷ��ĩβ������������޷�����չ���� 
	for (int i = 0; i < sLen; i++) {
		if (i != 0 && i != sLen - 1) {
			if(str[i] == '-') {
				// ��ȡ-��ǰ���ַ�
				char left = str[i - 1], right = str[i + 1];
				// ���ͬΪ��ĸ�������ֲŽ��в�������Ȼ����a-1���ַ�����չ������ 
				if (isAlpha(left) && isAlpha(right) || isNum(left) && isNum(right)) {
					// ���rightֻ��left��һ������������Ĳ���������ɾ��- 
					if (right - 1 == left) continue; 
					// ����ϸ�С���ұߣ�ִ�к������� 
					if (right > left) {
						string tStr = "";
						// ��ÿλ�ַ������в���
						// ע�⿪ͷ�ͽ�β���ַ�������չ�� 
						for (char j = left + 1; j <= right - 1; j++) {		
							// ����p1�������������д��Сд��* 
							char temp;
							if (p1 != 3) temp = (isAlpha(j) ? (p1 == 2 ? toupper(j) : j) : j);
							else temp = '*';
							// ִ��p2���ظ�
							for (int i = 0; i < p2; i++) tStr += temp;
						} 
						// ִ�з�ת��������������ж���p1��ֵ��ȫ��*û��Ҫ��ת 
						if (p3 == 2 && p1 != 3) {
							// ˫ָ��
							int leftIndex = 0, rightIndex = tStr.size() - 1;
							while (leftIndex < rightIndex) swap(tStr[leftIndex++], tStr[rightIndex--]); 
						} 
						// ���ϴ����Ľ�� 
						result += tStr;
						continue;
					}
				} 
			}
		}
		result += str[i];
	}
	cout << result;
	return 0;
}
