#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// �뵽��һ������+ǰ׺�͵����������ǿ��ܻᳬʱ�������д�ٶȲ��еĻ� 

// Ȼ��˼·����w���������������Ͽ���������û�취����һ�ε�ֵ�� 

typedef pair<int, int > PII;
vector<PII > vec;
int main() {
	int T;
	cin >> T;
	int s, t;
	while (T--) {
		cin >> s >> t;
		vec.push_back(PII(s, t)); 
	}
	sort(vec.begin(), vec.end());
	int vLen = vec.size();
	for (int i = 0; i < vLen; i++) {
		cout << vec[i].first << ' ' << vec[i].second << endl;
	}
	return 0;
} 
