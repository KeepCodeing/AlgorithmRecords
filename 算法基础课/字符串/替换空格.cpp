#include <iostream>
using namespace std;
// ����һ���ַ�����Ҫ�����еĿո��滻Ϊ%20
// ˼·�������ַ�����replace������C++�е�replace()����������OOP�������в�ͬ
// ���ȣ�ָ�������￪ʼ�滻����ָ���滻���ٸ��ַ���������ʲô�ַ��滻 
int main() {
	string a = "Hello World C++ IS NOT GOD";
	// �������һ��ֻ�滻һ���ո�ֱ�����пո�û��
	while(true) {
		int index = a.find(" ");
		// ע�������find����������Ҳ���Ԫ���ˣ����᷵��һ�������ǣ��������ַ���.npos����ȡ 
		if (index == a.npos) break;
		// �����滻���пո� 
		a.replace(index, 1, "%20");
	} 
	cout << a << endl;
	return 0;
}
