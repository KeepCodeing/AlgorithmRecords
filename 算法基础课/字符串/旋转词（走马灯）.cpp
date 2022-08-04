#include <iostream>
using namespace std;
// 给定一个字符串A="waterbottle"，字符串B="erbottlewat"，判断字符串B能否通过字符串A旋转得到
// 思路：在旋转字符串A时，我们会找一个旋转点将其分为x，y，再将x，y拼接起来组成字符串B，上例 
// 中x=wat ,y=erbottle，y+x = B ，x+y = A ，因此，我们需要找出这个旋转点，但无论怎么旋转，
// B都一定属于2A，因为2A就包含了所有的可能的翻转形式 
int main() {
	string A;
	string B;
	cin >> A >> B;
	A += A;
	if (A.find(B) != A.npos) cout << "can!" << endl;
	return 0;
}
