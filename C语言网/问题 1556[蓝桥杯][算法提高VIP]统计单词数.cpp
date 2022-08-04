#include <iostream>
#include <map>
#include <vector>
using namespace std;
map<string, int > words;
vector<string > let; 
int main() {
	string str;
	getline(cin, str);
	str += " ";
	// This is a test. This test is easy. This is a test. This test is easy.
	int sLen = str.size();
	string temp;
	int maxLen = -1;
	for (int i = 0; i < sLen; i++) {
		if (str[i] == ',' || str[i] == '.') continue;
		if (str[i] != ' ') {
			temp += toupper(str[i]);
		} else {
			int tSize = temp.size();
			maxLen = max(maxLen, tSize);
			if (!words.count(temp)) let.push_back(temp);
			words[temp]++;
			temp = ""; 
		}
	}
	for (int i = 0; i < let.size(); i++) {
		for (int j = 0; j < maxLen - let[i].size(); j++) cout << ' ';
		cout << let[i] << ':';
		for (int j = 0; j < words[let[i]]; j++) cout << '*';
		cout << words[let[i]] << endl;
	}
	return 0;
}
