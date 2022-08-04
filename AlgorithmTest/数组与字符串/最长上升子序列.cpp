#include <iostream>
#include <vector>
#include <map>
using namespace std;
struct Bound {
	int height;
	int low;
	Bound(int h = 0, int l = 0) {
		height = h, low = l;
	}
};
// ����һ�����飬������������ĳ����磺5 8 3 2 1 4�������3��4���㣩

// ˼·��ÿ��ֻ��Ҫ�Աȵ�ǰԪ�غ�һλ�������㵱ǰԪ��+1��-1���ɣ���Ϊ�ض�������
// �����У����Ա���ʱֻ�ø����������Сֵ���� 

int longest(vector<int > nums) {
	map<int, Bound > table;
	int local, maxLen = 0;
	
	for (int i = 0; i < nums.size(); i++) {
		// ȥ���ظ������ 
		if (table.count(nums[i])) continue;
		
		local = nums[i];
		int low = local, height = local;
		// ÿ�α���ʱ�������ýṹ�������һ���������ֵ����Сֵ 
		// ��������������������Ƿ������Сֵ 
		if (table.count(local - 1)) {
			low = table[local - 1].low;
		}
		// ��������������������Ƿ�������ֵ 
		if (table.count(local + 1)) {
			height = table[local + 1].height;
		}
		// �������ֵ����Сֵ 
		table[low].height = table[local].height = height;
		table[height].low = table[local].low = low;
		
		if (height - low + 1 > maxLen) {
			maxLen = height - low + 1;
		}
	}
	return maxLen;
}
int main() {
	vector<int > v;
	for (int i = 0; i < 10; i++) v.push_back(i);
	cout << longest(v) << endl;
	return 0;
}
