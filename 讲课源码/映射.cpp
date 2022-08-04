#include <iostream>
#include <map>
using namespace std;

int main() {
	map<string, string > mp;
	mp["hello"] = "world";
	mp["lambda"] = "half life";
	mp["higurashi"] = "umineko";
	
	cout << mp["hello"] << endl;
	
	// map同样无法直接遍历，需要使用迭代器
	for (map<string, string>::iterator it = mp.begin(); it != mp.end(); ++it) {
		// 映射中本质存放的是一个pair 
		cout << it->first << " " << it->second << endl;
	}
	return 0;
}
