#include <iostream>
#include <algorithm>
using namespace std;

// 这类问题大致就是给出若干个时间区间，同一个时间区间内不能做两件事，要求最多能做什么

// 如给你一张课表，其列举出来所有课的开始和结束时间，假设你只有一个教室可用，且一个教室
// 不能同时上两节课，要求求出最多能上多少节课

// 只要当前选择的课的结束时间最早就能上更多的课，比如
// 数学:[9, 10],英语:[9.5, 10.5],计算机:[10, 11], C语言:[10.5, 11.5]
// 音乐:[11, 12] 

/*5
9 10
9.5 10.5
10 11
10.5 11.5
11 12*/
struct Courses {
	float start;
	float end;
	// 重载<运算符，方便排序 
	bool operator<(const Courses& s1) {
		// >是升序，<是降序 
		return this->end < s1.end;
	}
	Courses(float s = 0, float e = 0) {
		start = s, end = e;
	}
}; 
int resolve(Courses arr[], int n) {
	// 不管怎么样都可以选一间教室 
	int cnt = 1;
	// 因为排序后最靠前的课程就是结束时间最早的课程 ，所以我们
	// 用一个j来保存当前结束时间最早的课程的下标，然后用这个课程 
	// 的结束时间依次往后比较，如果该课程的结束时间小于或者等于
	// 另一个课程开始的时间，就说明教室可以再用一次，同时更新
	// j，再进行对比 
	int j = 0;
	for (int i = 1; i < n; i++) {
		// 如果结束时间小于或者等于另外课程的开始时间，就可以用教室 
		if (arr[j].end <= arr[i].start) {
			// 增加结果 
			cnt++;
			// 更新当前结束时间最早的教室 
			j = i;
		}
	}
	return cnt;
}
int main() {
	int n;
	cin >> n;
	Courses *arr = new Courses[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i].start >> arr[i].end;
	}
	sort(arr, arr + n);
	cout << resolve(arr, n) << endl;
	delete[] arr;
	return 0;
}
