#include <iostream>
#include <vector>
using namespace std;

// ������С�����Ӻ�ʼɨ���������ǰ��ʼɨ�������ŷ������˳�� 

int nums[9];
// Ϊ�˿��������ʽ���˸�ʸ�� 
vector<int > vec;
int main() {
	int n;
	cin >> n;
	while (n--) {
		for (int i = 0; i < 9; i++) cin >> nums[i];
		for (int i = 8; i >= 0; i--) {
			if (nums[i] + 1 <= nums[0]) vec.push_back(nums[i]); 
		}
		// ��nums[0]��Ϊ�ֽ�� 
		vec.push_back(nums[0]); 
		for (int i = 0; i <= 8; i++) {
			if (nums[i] - 1 >= nums[0]) vec.push_back(nums[i]); 
		}
		int vLen = vec.size();
		for (int i= 0; i < vLen; i++) {
			cout << vec[i];
			if (i != vLen - 1) cout << ' ';
		}
		cout << endl;
		vec.clear();
	}
	return 0;
}
