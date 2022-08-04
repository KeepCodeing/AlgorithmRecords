#include <iostream>
#include <vector> 
#include <map>
using namespace std;

// 看起来略麻烦，主要麻烦在生成2~9对应的字母关系，不过可以发现只有7和9是四个字母，其它数字都是三个字母

// 原来思路是个错的（绝望），一个按键只能贡献一个字符，而不是所有上面的字符，也就是不能用桶排计数... 

class Solution {
public:
	vector<string > res; 
	map<int, string > mp;
	// 生成数字对应的字符串 
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
			// 取出数字对应的字母字符串 
			sLen = mp[num[i] - '0'].size();
			// 将这些字母映射到桶里 
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
