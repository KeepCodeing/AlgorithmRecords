#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// 权当复习有重复元素的全排列了，虽然可以用库函数... 

// 奇妙，倒车了，首先是i=哪里，写成了level，可能是普通回溯写多了w
// 还有就是去重，也忘得差不多了，不过还算写出来了，但是不知道为什么字符串不能去重...
// 我谔谔，好像是string类不能去重，改成vector就行了...
// 原因找到了，visited标记的是层数，而不是字符... 

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
