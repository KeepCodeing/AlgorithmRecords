#include <iostream>
using namespace std;

// ����ϼ�������֪��Ϊʲô������ϲ���ˢ����֪���ǲ�����ΪAC��֮��Ķ�������֮Ϊ����Щ���п��޵Ķ�������˼����
// �ܶ���... 

int main() {
	// ��w���㽶����i���㽶Ҫi*wԪ��������nԪ 
	int k, n, w;
	cin >> k >> n >> w;
	int cost = 0, res = 0;
	for (int i = 1; i <= w; i++) cost += i * k;
	res = n - cost;
	// ���ϵ�Ǯ������Ͳ��������ѽ�Ǯ�������ǮΪ0������������෴��... 
	if (res >= 0) res = 0;
	else res = -res;
	cout << res << endl;
	return 0;
}
