#include <iostream>
using namespace std;
// 分析：对字符进行计数即可 
class Solution {
public:
    int maxNumberOfBalloons(string text) {
    	if (text.empty() || text.size() < 7) return 0;
        float cnt[5] = {0};
        int tLen = text.size();
        for (int i = 0; i < tLen; i++) {
        	switch(text[i]) {
        		case 'b' : cnt[0]++;break;
        		case 'a' : cnt[1]++;break;
        		case 'l' : cnt[2] += 0.5;break;
        		case 'o' : cnt[3] += 0.5;break;
        		case 'n' : cnt[4]++;break;
			}
		}
		int minNum = cnt[0];
		for (int i = 1; i < 5; i++) {
			if (cnt[i] < minNum) minNum = cnt[i];
		}
		return minNum;
    }
};
int main() {
	return 0;
}
