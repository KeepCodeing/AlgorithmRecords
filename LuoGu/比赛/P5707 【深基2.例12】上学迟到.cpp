#include <iostream>
using namespace std;
int main() {
	int s, v;
	cin >> s >> v;
	int miteCnt = 0;
	int t;
	while(true) {
		if (s >= 0) miteCnt++;
		else break;
		s -= v;
	}
	miteCnt += 10;
	t = miteCnt;
	int mCnt = 0;
	while(true) {
		if (t >= 0) {
			t -= 60;
			mCnt++;
		} else break;
	}
	mCnt = 8 - mCnt;
	if (mCnt < 0) {
		mCnt += 24;
	}
	if(mCnt >= 0 && mCnt <= 9) cout << 0;
	cout << mCnt << ":" << 60 - miteCnt;
	return 0;
}
