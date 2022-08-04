#include <iostream>
#include <vector> 
#include <map>
using namespace std;

// ���������鷳����Ҫ�鷳������2~9��Ӧ����ĸ��ϵ���������Է���ֻ��7��9���ĸ���ĸ���������ֶ���������ĸ

// ԭ��˼·�Ǹ���ģ���������һ������ֻ�ܹ���һ���ַ�������������������ַ���Ҳ���ǲ�����Ͱ�ż���... 

class Solution {
public:
	vector<string > res; 
	map<int, string > mp;
	// �������ֶ�Ӧ���ַ��� 
	void getMap() {
		int num = 2, cnt;
		string temp;
		for (char c = 'a'; c <= 'z'; c++) {
			cnt = 1, temp = "";
			while ((num != 7 && num != 9) && cnt <= 3) temp += c, cnt++, c++;
			while ((num == 7 || num == 9) && cnt <= 4) temp += c, cnt++, c++;
			mp[num] = temp;
			num++, c--;
		}
	}
    vector<string> getValidT9Words(string num, vector<string>& words) {
		getMap();
		int nLen = num.size(), wLen = words.size(), bucket[26], temp[26], sLen, wTLen;
		string wTemp;
		if (!nLen || !wLen) return res;
		for (int i = 0; i < nLen; i++) {
			// ȡ�����ֶ�Ӧ����ĸ�ַ��� 
			sLen = mp[num[i] - '0'].size();
			// ����Щ��ĸӳ�䵽Ͱ�� 
			for (int j = 0; j < sLen; j++) bucket[mp[num[i] - '0'][j] - 'a']++;
		}
		bool flag;
		for (int i = 0; i < wLen; i++) {
			wTemp = words[i], wTLen = wTemp.size(), flag = true;
			for (int j = 0; j < 26; j++) temp[j] = bucket[j];
			for (int j = 0; j < wTLen; j++) {
				temp[wTemp[j] - 'a']--;
				if (temp[wTemp[j] - 'a'] < 0) {
					flag = false;
					break;
				}
			}
			if (flag) res.push_back(wTemp); 
		}
		return res;
    }
}; 

int main() {
	return 0;
}
