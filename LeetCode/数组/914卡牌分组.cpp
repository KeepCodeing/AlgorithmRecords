#include <iostream>
#include <map>
#include <vector>
using namespace std;
// ��������ÿ��Ԫ�س��ָ��������Լ�����ɣ���Լ�����ڵ���2˵�����Է��� 
class Solution {
public:
	int gcd(int m, int n) {
		if (m % n == 0) return n;
		return gcd(n, m % n);
	}
    bool hasGroupsSizeX(vector<int>& deck) {
    	map<int, int > m;
        for (int i = 0; i < deck.size(); i++) {
        	// ͳ��Ԫ�ظ��� 
        	m[deck[i]]++;
		}
		int gcd = -1;
		for (map<int, int >::iterator it = m.begin(); it != m.end(); it++) {
			// ���㹫Լ�� 
			gcd = gcd == -1 ? it->second : this->gcd(gcd, it->second);
		}
		return gcd >= 2;
    }
};
int main() {
	return 0;
}
