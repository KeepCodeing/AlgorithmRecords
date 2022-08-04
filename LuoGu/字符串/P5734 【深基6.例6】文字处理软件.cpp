#include <iostream>
using namespace std;

// string类的练习 

int main() {
	int n, code, start, end;
	string str, temp;
	cin >> n;
	cin >> str;
	for (int i = 0; i < n; i++) {
		cin >> code;
		switch(code) {
			case 1:
				cin >> temp;
				str += temp;
				cout << str << endl;
				break;
			case 2:
				cin >> start >> end;
				str = str.substr(start, end); 
				cout << str << endl;
				break;
			case 3:
				cin >> start >> temp;
				str.insert(start, temp); 
				cout << str << endl;
				break;
			case 4:
				cin >> temp;
				cout << (int)str.find(temp) << endl;
				// 奇妙，不知道为什么这样写有问题 
//				if (str.find(temp) !=  str.npos) cout << str.find(temp) << endl;
//				else cout << -1; 
				break;
		}
	}
	return 0;
}
