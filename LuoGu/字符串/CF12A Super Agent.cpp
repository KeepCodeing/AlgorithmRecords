#include <iostream>
using namespace std;

// ��Ȼ��ˮ�⣬���Ǳ�����˾ͱ��浽�ַ�����...���Ƶ���Ҳ�����ˣ�������ʱ�򲻻�..��ν���ĶԳƼ����ַ���
// ת��Ϊһά֮���Ǹ����Ĵ�... 

int main() {
	string str, t;
	for (int i = 0; i < 3; i++) cin >> t, str += t;
	int left = 0, right = str.size() - 1;
	while (left < right) {
		if (str[left++] != str[right--]) {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
	return 0;
}
