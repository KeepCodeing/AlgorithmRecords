#include <iostream>
#include <map>
using namespace std;

int main() {
	map<string, string > mp;
	mp["hello"] = "world";
	mp["lambda"] = "half life";
	mp["higurashi"] = "umineko";
	
	cout << mp["hello"] << endl;
	
	// mapͬ���޷�ֱ�ӱ�������Ҫʹ�õ�����
	for (map<string, string>::iterator it = mp.begin(); it != mp.end(); ++it) {
		// ӳ���б��ʴ�ŵ���һ��pair 
		cout << it->first << " " << it->second << endl;
	}
	return 0;
}
