#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// ��ʼѡ����ˢ��ս�����ˣ����治�ᣬ̰��Ҳ������������...�������ǲ��鼯����...�����������İɣ�
// POJ�����ƺ�����һЩ������ⲻ�����⣬�������������е�����꣬Ȼ��Ҫ�����о��벻����D�ĵ���
// �������ӡ�����ν��ά�޲������ǽ���ǰ�������ӵ����е���뵽���鼯����Կ�������С����������
// �Ȱ����е�ľ�����������Ȼ��Ѿ���Ϸ��ĵ�ɸѡ������ά�޾�ֱ�����ߡ�������Բ�������vector
// �ڽӱ��˼�룬��ǰ����Ϊ���㣬Ȼ��������ܺ������ڵĵ������... 

// ��֪��Ϊʲô���RE���������ڽӱ������... 

typedef pair<int, int > PII;
const int N = 1001 + 10;
bool fixedNode[N];
// ��ߵ��ڽӱ� 
vector<int > graph[N];
// �Ȱ�����ĵ������
vector<PII > poi;
bool check(int x1, int y1, int x2, int y2, int d) {
	return sqrt((x1 - x2 + .0) * (x1 - x2) + (y1 - y2) * (y1 - y2)) <= d +.0; // d�����ͨ�ŷ�Χ���������پ���Ϊd... 
}
struct unionFind {
	int bin[N];
	unionFind () {
		for (int i = 0; i < N; i++) bin[i] = i;
	}
	int anc(int x) {
		if (x != bin[x]) bin[x] = anc(bin[x]);
		return bin[x];
	}
	void uni(int x, int y) {
		bin[anc(x)] = y;
	}
	bool ask(int x, int y) {
		return anc(x) == anc(y);
	}
};
unionFind u;
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, d;
	cin >> n >> d;
	int x, y;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		poi.push_back(PII(x, y));
	}
	// �㵱ǰ���ܵ���Щ��
	int pLen = poi.size();
	for (int i = 0; i < pLen; i++) {
		for (int j = i + 1; j < pLen; j++) {
			if (check(poi[i].first, poi[i].second, poi[j].first, poi[j].second, d)) {
				// ������ı�Ŵ�1��ʼ 
				graph[i + 1].push_back(j + 1); 
			}
		}
	}
	char op;
	while (cin >> op) {
		if (op == 'O') {
			cin >> x;
			// �����ظ���ӣ������RE 
			if (fixedNode[x]) continue;
			fixedNode[x] = true;
			for (int i = 0; i < graph[x].size(); i++) u.uni(x, graph[x][i]);
		} else {
			cin >> x >> y;
			cout << (u.ask(x, y) ? "SUCCESS" : "FAIL") << endl;
		}
	} 
	return 0;
}
