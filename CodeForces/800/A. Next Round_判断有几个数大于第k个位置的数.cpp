#include <iostream>
using namespace std;

// ��������˼�Ǹ�n������Ȼ���һ��λ��k��Ҫ��ͳ���м��������ڵ���nums[k]�������бȽϴ���������
// ��Ϊ��������ǵݼ��ģ��������������ǻ������㣬����ֱ�ӱ���������... 

const int N = 50 + 10;
int nums[N];
int main() {
	int n, k, cnt = 0;
	cin >> n >> k;
	// �±��1��ʼ 
	for (int i = 1; i <= n; i++) cin >> nums[i];
	// ע��ڶ�����������������ʾ���Ƿ���Ϊ0�Ķ��鲻�ܱ���������������k��λ�õĶ����������Ϊ0��
	// Ҳ����˵nums[i] >= nums[k]��Ч���ҽ���nums[i] > 0 
	for (int i = 1; i <= n; i++) cnt += (nums[i] >= nums[k] && nums[i] > 0);
	cout << cnt << endl;
	return 0;
}
