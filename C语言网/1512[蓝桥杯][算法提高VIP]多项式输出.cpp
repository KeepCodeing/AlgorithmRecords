#include <iostream>
using namespace std;

// �þ���ǰ���������ʱ�������������ˣ���ʱ����û��ܿӵ�...
// ��˵����Ҳû�õ�����ȥ������Ӧ��д���������ɵ��

// ׹�����Σ����ܣ�����û������ 
 
int *nums;
int main() {
	int n;
	cin >> n;
	nums = new int[n + 5];
	for (int i = 1; i <= n + 1; i++) {
		cin >> nums[i];
	}
	// ��ʱ���ӵľ��Ǽ��ţ����ڿ��������ǰ���������ź��棬����
	// ֻ���жϵ�ǰ�Ƿ��ǵ�һ�������� 
	// ������...����Ŀ����n������Ҫ����n+1����..��ǰ����ˣ�����û�ģ���������Ŷ��û����Ŀ������׹���ˣ� 
	int xs = n;
	for (int i = 1; i <= n + 1; i++) {
		if (nums[i] > 0) {
			if (i != 1) cout << '+';
			// ����1����ϵ�� 
			if (nums[i] > 1) cout << nums[i];
		} else if (nums[i] < 0) {
			if (nums[i] == -1) cout << '-';
			else cout << nums[i];
		}
		// ������0����δ֪�� 
		if (nums[i] != 0 && xs != 0) cout << "x";
		if (xs > 1) cout << "^" << xs;
		xs--;
	}
	delete[] nums;
	return 0;
}
