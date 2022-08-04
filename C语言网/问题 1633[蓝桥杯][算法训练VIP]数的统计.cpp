#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// ��һ����ɢ��...
// ��ʵ��Ͱ��Ҳ���ԣ����鿪����... 
// ����mapĬ�ϰ���key����������������Ҳ������map��mapҪ������key����Ļ����԰�key��value�����һ��
// pair��Ȼ����vector���������ٶ����vector����value�������򣬾��ܵõ���Ӧ��key��˳���ˣ�Ҳ����˵sort
// ����ֱ�Ӷ�map���򣬵������ǿ��Խ���value������key��������map 
 
typedef pair<int, int > PII;
vector<int > nums, temp;
// ���֣�����涨�±��1��ʼ 
int findNum(int x) {
	return lower_bound(temp.begin(), temp.end(), x) - temp.begin() + 1;
}
PII cnts[1010];
int main() {
	int n;
	cin >> n;
	int t;
	for (int i = 0; i < n; i++) cin >> t, nums.push_back(t);
	// ��ԭ�����������ݣ���temp��ӳ���±꣬nums��ͳ��Ԫ������ 
	temp = nums;
	// �����ȥ�أ���ɢ���ĺ��Ĳ���֮һ 
	sort(temp.begin(), temp.end());
	temp.erase(unique(temp.begin(), temp.end()), temp.end()); 
	int tLen = temp.size();
	// ���ö��ֽ���λ����ӳ����±꣬���ﻹ����count()������ͳ��nums��Ҫ�ҵ�Ԫ�ص����� 
	for (int i = 0; i < tLen; i++) cnts[findNum(temp[i])] = PII(temp[i], count(nums.begin(), nums.end(), temp[i]));
	for (int i = 1; i <= tLen; i++) cout << cnts[i].first << ' ' << cnts[i].second << endl;
	return 0;
}
