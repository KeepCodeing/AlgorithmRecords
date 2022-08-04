#include <iostream>
#include <map>
using namespace std;

// ����һ�������ַ�������Ϣ�ַ������ж���Ϣ�ܷ����������
// ʱ�临�Ӷ�:O(m + n) 
bool check_news(string news, string msg) {
	// ����˼·������Ϣ�ַ����е�ÿ���ַ���Ҫ�������ַ����г��֣��ҳ��ִ���ҪС��
	// ���������и��ַ����ֵĴ���
	if (news.length() < msg.length()) return false;
	map<char, int> news_map;
	// ͳ�������ַ����ַ����� 
	for (int i = 0; i < news.length(); i++) {
		news_map[news[i]]++;
	} 
	for (int i = 0; i < msg.length(); i++) {
		// �����Ϣ�ַ�����ĳ���ַ�û���ֻ��߳��ִ��������������ַ���˵���������
		// C++�е�map��ȡkey�����ڵ�value��Ĭ�Ϸ���0 
		if (news_map[msg[i]] <= 0) return false;
		// ���������ַ���ʣ����ַ����� 
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
