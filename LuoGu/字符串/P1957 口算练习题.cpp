#include <iostream>
#include <sstream>
using namespace std;

// �ƺ�����ǰ�����鷳give up�˵���w����ˢ������۵�ʱ���ֿ�����...
// ��֮������ҵ���пγ̶�û������ӣ�������Ҫ�Ͽ��ˣ������������������
// ��five����ʱ��ˢ��Щ�㷨���... 

// ����ģ�⣬�����е�þ���ǰ��ѧ��ʱ��д����ĸо��ˣ�ֻ�������ڿ��ǵıȵ�������˾�����
// ͨ���ַ��������任����һ��ʼ���ַ���������֣�Ȼ���ж��������������ת�����ֵı�������
// ��Ӧ�Ĳ������ٰѽ��ת���ַ���������ͳ�Ƴ���...������������ϲ��࣬���ǽ����˰�... 

// ͨ����������봦�����ʡȥ�ܶ಻��Ҫ�Ĳ�������������ת��... 
 
// �ַ���ת���֣������ǵ����ַ����� 
int str2num(string n1) {
	int t;
	stringstream ss;
	ss << n1, ss >> t;
	return t;
}
// ����ת�ַ�������Ҫ�������������Ľ�� 
string num2str(int n1) {
	string t;
	stringstream ss;
	ss << n1, ss >> t;
	return t;
}
// ����𰸣�һ��ʼд�����������һ���ظ������Ծ͸��һ�������� 
void printRes(int n, string n1, string n2, char op) {
	string re = num2str(n);
	int rLen = n1.size() + n2.size() + re.size() + 2;
	cout << n1 << op << n2 << '=' << re << endl;
	cout << rLen << endl;
}
// ���ĺ�����ͨ����������ж�Ӧ������������ 
void solve(string op, string n) {
	string n1 = n, n2;
	if (n == "") cin >> n1;
	cin >> n2;
	// ��Ӧ���������в����������ڴ��ε�ʱ�򴫽���Ͳ�������ͬ���� 
	if (op == "a") printRes(str2num(n1) + str2num(n2), n1, n2, '+');
	else if (op == "b") printRes(str2num(n1) - str2num(n2), n1, n2, '-');
	else if (op == "c") printRes(str2num(n1) * str2num(n2), n1, n2, '*');
}
int main() {
	int T;
	cin >> T;
	string op, n1, pre = "";
	while (T--) {
		cin >> op;
		// ���������һ�����������ͷ��һ�������ֿ�ͷ����������������Ĳ�ֻͬ�е�һ������
		// ���ַ����ǲ������������֣����Կ�����solve()�������жϣ�����pre�ĸ���Ҳ����ÿһ��
		// ���붼���£���Ȼpre���ܻ������֣�����ֻҪ�������ǲ�����ʱ�Ž��и��� 
		if (op == "a" || op == "b" || op == "c") pre = op, solve(op, "");
		else solve(pre, op); // ��������ˣ���д�˸�����... 
	}
	return 0;
}
