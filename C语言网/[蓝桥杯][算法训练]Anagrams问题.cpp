#include <iostream> 
using namespace std;
const int N = 30;
int bucket[N];
int main() {
	string str1, str2;
	cin >> str1 >> str2;
	int sLen1, sLen2;
	sLen1 = str1.size(), sLen2 = str2.size();
	if (sLen1 != sLen2) {
		cout << "N";
		return 0;
	}
	for (int i = 0; i < sLen1; i++) bucket[tolower(str1[i]) - 'a']++;
	for (int i = 0; i < sLen2; i++) bucket[tolower(str2[i]) - 'a']--;
	for (int i = 0; i < 26; i++) {
		if (bucket[i] < 0) {
			cout << "N";
			return 0;
		}
	}
	cout << "Y";
	return 0;
}
