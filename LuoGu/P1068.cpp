#include <iostream>
#include <algorithm> 
using namespace std;
struct info {
	int id;
	int score;
};
bool cmp(info a, info b) {
	if (a.score != b.score) return a.score > b.score;
	return a.id < b.id;
}
int main() {
	int n, t, line, counter = 0;
	cin >> n >> t;
	info *arr = new info[n];
	for (int i = 0; i < n; i++) {
		info temp;
		cin >> temp.id >> temp.score;
		arr[i] = temp;
	}
	sort(arr, arr + n, cmp);
	// 下标从0开始的，所以要减一，在测试时没有发现 
	line = arr[(int)(t * 1.5) - 1].score;
	for (int i = 0; i < n; i++) {
		if (arr[i].score < line) break;
		counter++;
	}
	cout << line << ' ' << counter << endl;
	for (int i = 0; i < counter; i++) cout << arr[i].id << ' ' << arr[i].score << endl;
	return 0;
}
