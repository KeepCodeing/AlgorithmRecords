#include <windows.h>
#include <iostream>
using namespace std;
int main() {
	system("shutdown -s -t 300");
	while (true) {
		cout << "�õܵ�Ҫ����[����Ц]" << endl;
		Sleep(100);
	}
	return 0;
}
