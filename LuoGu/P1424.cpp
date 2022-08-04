#include <iostream>
using namespace std;
int main() {
	long long road = 0;
	int start, end;
	cin >> start >> end;
	int g = start;
	for(int i = 0; i < end; i++) {
		if (g != 6 && g != 7) road += 250;
		if (g == 7) g = 1;
		else g++;
	}
	cout << road;
}
