#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// ������ȫ����... 
vector<int > vec;
int main() {
	for (int i = 1; i <= 9; i++) vec.push_back(i);
	do {
		
	} while(next_permutation(vec.begin(), vec.end()));
	return 0;
}

// ����̫���ӣ����д����ѭ�����������ܵõ����� 
//#include <iostream>
//using namespace std;
//void countNum(int bucket[], int n) {
//	while (n) {
//		bucket[n % 10]++;
//		n /= 10;
//	}
//}
//int main() {
//	int bucket[11];
//	for (int i = 1; i <= 10000; i++) {
//		for (int j = 1; j <= 10000; j++) {
//			for (int k = 1; k <= 10000; k++) {
//				if (i == j * k) {
//					//cout << i << endl;
//					countNum(bucket, i);
//					countNum(bucket, j);
//					countNum(bucket, k);
//					bool flag = true;
//					for (int m = 1; m <= 9; m++) {
//						if (bucket[m] != 1) {
//							flag = false;
//							break;
//						}
//					}
//					if (flag) {
//						cout << i << " = " << j << " x " << k << endl;
//					}
//					fill(bucket, bucket + 11, 0);
//				}
//			}
//		}
//	}
//	return 0;
//}
