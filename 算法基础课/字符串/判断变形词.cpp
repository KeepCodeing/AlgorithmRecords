#include <iostream>
using namespace std;
// 给定两个字符串如:here you are，are you here ，判断它们是否是变形词（字符个数相同），不包括空格 
// 思路：1. 利用STL对它们排序并判断是否相等，这样做很简单，但是效率不高
// 2. 开辟一个计数数组，效率更高 
// 这种思想是计数排序的思想 
int main() { 
	string a = "here you are";
	string b = "are you here";
	if (a.size() != b.size()) cout << "can not!" << endl;
	// 使用字符的ASCII码作为整形数组的下标，注意这里的初始化方式 
	int *temp = new int[a.size()]();
	
	for (int i = 0; i < a.size(); i++) {
		if (a[i] == ' ') continue;
		temp[(int)a[i]] += 1;
	}
	
	for (int i = 0; i < b.size(); i++) {
		if (b[i] == ' ') continue;
		if (temp[(int)b[i]] < 0) {
			cout << "can not!" << endl;
			break;
		}
		temp[(int)b[i]] -= 1;
	}
	
	delete[] temp; 
	return 0;
}
