#include <iostream>
#include <map>
using namespace std;

// 给定一个新闻字符串和消息字符串，判断消息能否由新闻组成
// 时间复杂度:O(m + n) 
bool check_news(string news, string msg) {
	// 核心思路就是消息字符串中的每个字符都要在新闻字符串中出现，且出现次数要小于
	// 等于新闻中该字符出现的次数
	if (news.length() < msg.length()) return false;
	map<char, int> news_map;
	// 统计新闻字符串字符个数 
	for (int i = 0; i < news.length(); i++) {
		news_map[news[i]]++;
	} 
	for (int i = 0; i < msg.length(); i++) {
		// 如果消息字符串中某个字符没出现或者出现次数大于了新闻字符，说明不能组成
		// C++中的map获取key不存在的value会默认返回0 
		if (news_map[msg[i]] <= 0) return false;
		// 更新新闻字符串剩余的字符个数 
		news_map[msg[i]]--;
	}
	return true;
} 

int main() {
	string news, msg;
	cin>> news >> msg;
	cout << check_news(news, msg) << endl;
	return 0;
}
