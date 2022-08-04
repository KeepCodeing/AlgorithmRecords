#include <iostream>
#include <algorithm>
using namespace std;

// Ͱ�ţ�ע���Сд��ĸ���ã�����Ҫ������������Ͱ���Ԫ��Ĭ��ֵӦ��Ϊ-1��Ȼ���Ͱ����������
// �����±����...

// ������һ��AC���⣬���첻֪�����ͳ��˼ӰѾ���ʿ...AC�˰˸��⣬����������û��������ܵ���˵����û����
// ���ǽ����գ���Ȼ�����ⶼ��ˮ...Ȼ����ǿ��ٵ����ڻ�û�͹�����ϣ���������͹�������Ȼ��ֻ�еȿ����˲���
// ������.. 

class Solution {
public:
	typedef pair<int, char > PII;
    string frequencySort(string s) {
		int sLen = s.size(), INF = 0x3fffffff;
		if (!sLen) return "";
		string res = "";
		PII bucket[256];
		// ��Ϊ����Ҫ��������������԰�pair��first��������Ĭ��Ϊ�����ˣ�Ȼ���ں������Ͱ�ŵ�ʱ��
		// �ж��µ�ǰ��ĸ��first�ǲ���INF�������INF���Ͱ����ĳ�0��Ȼ�����Ϊ����������������д�������� 
		for (int i = 0; i <256; i++) bucket[i].first = INF, bucket[i].second = (char)i;
		for (int i = 0; i < sLen; i++) {
			// û�Ź�����ɸ�����-1<-2<-3... 
			if (bucket[s[i]].first == INF) bucket[s[i]].first = 0;
			bucket[s[i]].first--;
		}
		sort(bucket, bucket + 256);
		for (int i = 0; i < 256; i++) {
			if (bucket[i].first == INF) break;
			// Ͱ���... 
			while (bucket[i].first < 0) res += bucket[i].second, bucket[i].first++;
		}
		return res;
    }
}; 

int main() {
	Solution s = Solution();
	string str;
	cin >> str;
	cout << s.frequencySort(str); 
	return 0;
}
