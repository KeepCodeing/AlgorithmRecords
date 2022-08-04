#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

// 看了题解才知道这个题是BFS...DFS写的和雪一样而且还是错的... 
// DFS没有最短路特性，而且且写的还是个错的w 

int nums[10];
bool primes[10001];
void getPrimes() {
	primes[0] = primes[1] = true;
	for (int i = 2; i <= sqrt(10000); i++) {
		if (primes[i]) continue;
		for (int j = i * i; j <= 10000; j += i) {
			primes[j] = true;
		}
	}
}
vector<int > vec;
void dfs(int level, int deepth) {
//	for (int i = 0; i < 4; i++) cout << nums[i];
//	cout << "------" << endl;
	if (level == deepth) {
//		for (int i = 0; i < 4; i++) cout << nums[i];
//		cout << "------" << endl;
		for (int i = 0; i < vec.size(); i++) cout << vec[i] << endl;
		cout << endl << "----" << endl;
		return;
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 10; j++) {
			if (i == 0 && j == 0) continue;
			int temp = nums[i];
			nums[i] = j; 
			int t = nums[0] * 1000 + nums[1] * 100 + nums[2] * 10 + nums[3];
			if (primes[t]) continue;
			vec.push_back(t); 
			dfs(level + 1, deepth);
			vec.pop_back();
			nums[i] = temp;
		}
	}
}
int main() {
	getPrimes();
	for (int i = 0; i < 4; i++) cin >> nums[i];
	dfs(0, 4);
	
	// for (int i = 0; i <= 10000; i++) if(!primes[i]) cout << i << endl;
	return 0;
}
