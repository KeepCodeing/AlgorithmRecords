#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// ����ˮ�⣬��Ȼ�����ǳ��ͣ���������ǽ����һ��һ��AC����...
// ˼·���ǰ��������±��������Ȼ���Ȼ���ڽ⣬����ģ�����Ĺ��̣���ԭ���鰴�����������
// ��������cnt��Ԫ�ص��±������������ͷ������� 

class Solution {
typedef pair<int, int > PII;
public:
	vector<vector<int> > res;
    vector<vector<int> > groupThePeople(vector<int>& groupSizes) {
        int gLen = groupSizes.size();
        vector<PII > temp;
		vector<int > rtemp;
		// ����������Ȼ���cnt����ͬ�������˷��飬��Ϊһ�����ڽ⣬�������ǿ��е�w 
        for (int i = 0; i < gLen; i++) temp.push_back(PII(groupSizes[i], i));
        sort(temp.begin(), temp.end());
		int cnt, tLen = temp.size();
		for (int i = 0; i < tLen; i++) {
			cnt = temp[i].first;
			while (cnt--) {
				rtemp.push_back(temp[i].second);
				i++; 
			}
			// ע�������i--����Ϊ��ѭ�����i++����Ϊwhile���Ѿ�����for���i++�� 
            i--;
			res.push_back(rtemp); 
            rtemp.clear();
		}
		return res;
    }
};


int main() {
	return 0;
}
