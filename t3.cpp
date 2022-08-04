#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#define endl '\n'
using namespace std;

struct Node {
	double k, b;
	
	bool operator<(const Node& a) const {
		if (a.k != k) return a.k < k;
		return a.b < b;
	}
};

vector<Node > vec;
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	for (int x1 = 0; x1 <= 19; x1++) {
		for (int y1 = 0; y1 <= 20; y1++) {
			for (int x2 = 0; x2 <= 19; x2++) {
				for (int y2 = 0; y2 <= 20; y2++) {
					if (x1 == x2) continue;
					double k = (y1 - y2 + .0) / (x1 - x2);
					double b = y1 - k * x1;
					Node res;
					res.k = k, res.b = b;
					vec.push_back(res); 
				}
			}
		}
	}
	sort(vec.begin(), vec.end());
	int res = 1;
	for (int i = 1; i < vec.size(); i++) {
		if (fabs(vec[i].k - vec[i - 1].k) > 1e-8 || fabs(vec[i].b - vec[i - 1].b) > 1e-8) res++;
	}
	cout << res + 20;
	return 0;
}
