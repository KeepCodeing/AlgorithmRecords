#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
using namespace std;
vector<int > nums;
struct node {
	int val, id;
	node(int val, int id) : val(val), id(id) {};
	bool operator<(const node& n) const {
		if (val != n.val) return val > n.val;
		return id < id;
	}
};
bool cmp(node a, node b) {
	return a.id < b.id;
}
vector<node > vec;
set<node > s; 
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		nums.push_back(t); 
		s.insert(node(t, i));
	}
	set<node >::iterator it = s.begin();
	for (int i = 1; i <= m; i++) {
		vec.push_back(*it); 
		it++;
	}
	sort(vec.begin(), vec.end(), cmp);
	int vLen = vec.size();
	for (int i = 0; i < vLen; i++) {
		printf("%d", vec[i].val);
		if (i != vLen - 1) printf(" ");
	}
	return 0;
}
