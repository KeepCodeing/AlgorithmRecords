#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
int main() {
	
	/*
	QWERTYUIOPLKJHGFDSAZXCVBN 
	ABCDEFGHIJKLMNOPQRSTUVWXY 
	DSLIEWO
	*/
	map<char, int > m1, m2;
	vector<int > v1, v2;
	string security, message;
	cin >> security >> message;
	for (int i = 0; i < security.size(); i++) m1[security[i]]++;
	for (int i = 0; i < message.size(); i++) m2[message[i]]++;
	for (map<char, int >::iterator it = m1.begin(); it != m1.end(); it++) {
		cout << it->first << ":" << it->second << ' ';		
	}
	cout << endl;
	for (map<char, int >::iterator it = m2.begin(); it != m2.end(); it++) {
		cout << it->first << ":" << it->second << ' ';	
	}
	/*sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	for (int i = 0; i < v1.size(); i++) cout << v1[i] << ' ';
	cout << endl;
	for (int i = 0; i < v2.size(); i++) cout << v2[i] << ' ';*/
//	sort(security.begin(), security.end());
//	sort(message.begin(), message.end());
//	cout << message << endl;
//	cout << security << endl;
	return 0;
} 
