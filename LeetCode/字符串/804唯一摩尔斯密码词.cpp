#include <iostream>
#include <vector>
#include <set>
using namespace std;
// ���������������ַ���ascii���������Ϊ�±�����������ң�û��Ҫ��map
class Solution {
public:
    int uniqueMorseRepresentations(vector<string> & words) {
    	string temp;
    	set<string > s;
    	string arr[] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.",
			"...","-","..-","...-",".--","-..-","-.--","--.."};
        for (int i = 0; i < words.size(); i++) {
        	for (int j = 0;  j < words[i].size(); j++) {
        		// ͨ���ַ���ASCII�������ȡ��ӦĦ˹���� 
        		temp += arr[words[i][j] - 'a'];
			}
			s.insert(temp); 
			temp.clear();
		}
		// ͳ�Ƽ������ж����ֲ��ظ�Ԫ�أ�������ͨ��һ�������ֶ�����
		// ������Ԫ��Ϊ1ʱ����ȴΪ0 
		return s.size();
    }
}; 
int main() {
	return 0;
}
