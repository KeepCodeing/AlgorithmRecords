#include <iostream>
#include <map>
using namespace std;
map<string, int > m;
int main() {
	int n;
	int code;
	string name;
	int score;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> code;
		if (code != 4) cin >> name;
		switch(code) {
			case 1:
				cin >> score;
				m[name] = score;
				cout << "OK" << endl;
				break;
			case 2:
				if (m.count(name)) cout << m[name] << endl;
				else cout << "Not found" << endl;
				break;
			case 3:
				if (m.count(name)) {
					m.erase(name); 
					cout << "Deleted successfully" << endl;
				} else {
					cout << "Not found" << endl;
				}
				break;
			case 4:
				cout << m.size() << endl;
				break;
		}
	} 
	return 0;
}
