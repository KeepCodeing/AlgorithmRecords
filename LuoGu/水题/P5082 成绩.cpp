#include <iostream>
#include <cstdio>
using namespace std;
int main() {
	long n;
	int cj;
	cin >> n;
	long long scoreSum = 0, trSum = 0, kf;
	for (int i = 0; i < n; i++) {
		cin >> cj;
		scoreSum += cj;
	}
	for (int i = 0; i < n; i++) {
		cin >> cj;
		trSum += cj;
	}
	kf = scoreSum - trSum;
	// ������ˣ����Բ��óˣ�����˾��� 
	scoreSum *= 3, trSum *= 2;
	printf("%.6lf", (scoreSum - trSum * 1.0) / kf);
	return 0;
}
