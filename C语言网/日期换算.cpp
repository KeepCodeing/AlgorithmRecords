#include <iostream>
using namespace std;

// ֮ǰһֱ�ȽϷ���������֮�����w��Ȼ���������ű��ŷ����Լ�����w..
// �ж�����������һ�򣬰��겻���İ�������..���·������Ļ�����������.. 

typedef long long LL;
int m[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int main() {
	LL x, y, res = 0;
	// ע�������ʽ����˵���ű�������%I64d����������дC�������ֻ�׹��... 
	// ȥ��ϰϵͳ������A+B Problem���ƺ�������д�ǿ��Ե�.. 
	scanf("%lld%lld", &x, &y);
	for (int i = 0; i < x - 1; i++) res += m[i];
	res += y;
	printf("%lld", res);
	return 0;
}
