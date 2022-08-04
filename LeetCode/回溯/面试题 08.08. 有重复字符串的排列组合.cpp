#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// Ȩ����ϰ���ظ�Ԫ�ص�ȫ�����ˣ���Ȼ�����ÿ⺯��... 

// ��������ˣ�������i=���д����level����������ͨ����д����w
// ���о���ȥ�أ�Ҳ���ò���ˣ���������д�����ˣ����ǲ�֪��Ϊʲô�ַ�������ȥ��...
// �����̣�������string�಻��ȥ�أ��ĳ�vector������...
// ԭ���ҵ��ˣ�visited��ǵ��ǲ������������ַ�... 

vector<char > vec, nums;
bool visited[256];
void dfs(int level, int deepth) {
	if (level >= deepth) {
		for (int i = 0; i < vec.size(); i++) cout << vec[i];
		cout << endl;
		return;
	}
	int pre = nums[0] - 1;
	for (int i = 0; i < deepth; i++) {
		if (visited[i] || nums[i] == pre) continue;
		visited[i] = true;
		vec.push_back(nums[i]); 
		dfs(level + 1, deepth);
		vec.pop_back();
		visited[i] = false;
		pre = nums[i];
	}
}

int main() {
	int n;
	char t;
	cin >> n;
	while (n--) {
		cin >> t;
		nums.push_back(t); 
	}
	sort(nums.begin(), nums.end());
	dfs(0, nums.size());
	return 0;
}
