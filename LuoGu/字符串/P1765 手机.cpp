#include <iostream>
#include <cmath>
using namespace std;

// ������2����ģ����鷳����Ҫ�����ҹ��� 
// д��ʺ�ˣ������ٸĳɺ�����... 
// ׹�٣�ԭ���� 

int main() {
	string str;
	getline(cin, str);
	int cnt = 0;
	for (int i = 0; i < str.size(); i++) {
		if ('a' <= str[i] && 'z' >= str[i]) {
			if ('c' - str[i] >= 0) {
				cnt += abs('a' - str[i]) + 1;
			} else if ('f' - str[i] >= 0) {
				cnt += abs('d' - str[i]) + 1;
			} else if ('i' - str[i] >= 0) {
				cnt += abs('g' - str[i]) + 1;
			} else if ('l' - str[i] >= 0) {
				cnt += abs('j' - str[i]) + 1;
			} else if ('o' - str[i] >= 0) {
				cnt += abs('m' - str[i]) + 1;
			} else if ('s' - str[i] >= 0) {
				cnt += abs('p' - str[i]) + 1;
			} else if ('v' - str[i] >= 0) {
				cnt += abs('t' - str[i]) + 1;
			} else if ('z' - str[i] >= 0) {
				cnt += abs('w' - str[i]) + 1;
			}
		} else if (str[i] = ' '){
			// �����������и����ţ�֮ǰֱ��д�˸�else
			// ��0��.... 
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}
