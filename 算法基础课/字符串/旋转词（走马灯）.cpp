#include <iostream>
using namespace std;
// ����һ���ַ���A="waterbottle"���ַ���B="erbottlewat"���ж��ַ���B�ܷ�ͨ���ַ���A��ת�õ�
// ˼·������ת�ַ���Aʱ�����ǻ���һ����ת�㽫���Ϊx��y���ٽ�x��yƴ����������ַ���B������ 
// ��x=wat ,y=erbottle��y+x = B ��x+y = A ����ˣ�������Ҫ�ҳ������ת�㣬��������ô��ת��
// B��һ������2A����Ϊ2A�Ͱ��������еĿ��ܵķ�ת��ʽ 
int main() {
	string A;
	string B;
	cin >> A >> B;
	A += A;
	if (A.find(B) != A.npos) cout << "can!" << endl;
	return 0;
}
