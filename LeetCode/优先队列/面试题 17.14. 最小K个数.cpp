#include <iostream>
#include <queue>
using namespace std;

// �����ѣ�������ϵ������� 
// ��w��ԭ��C++Ĭ���Ǵ����ѣ���Ϊд���·�õ���priority_queue<int, vector<int>, greater<int > > que������ʽ��
// �ѣ�һ˲��Ϊ�ǰ���Ȩ�Ӵ�С����ģ�Ȼ��д��������������·��·����С... 

class Solution {
public:
	priority_queue<int > que;
    vector<int > res;
	vector<int> smallestK(vector<int>& arr, int k) {
		int aLen = arr.size();
		if (!aLen || !k) return res;
		for (int i = 0; i < aLen; i++) {
			que.push(arr[i]);
			k--;
//            if (k < 0) que.pop(), k = 0; 
		}
		while (que.size()) res.push_back(que.top()), que.pop();
        return res;
    }
};

int main() {
	priority_queue<int> que;
	int n;
	cin >> n;
	int t;
	while (n--) cin >> t, que.push(t);
	while (que.size()) cout << que.top(), que.pop(); 
	return 0;
}
