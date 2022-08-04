#include <iostream>
using namespace std;

// 一时不知道该怎么评价这个题w 


string strs[10] = {
	"XXXX.XX.XX.XXXX",
	"..X..X..X..X..X",
};
int main() {
	cout << strs[0];
	/* 
	XXX...X.XXX.XXX.X.X.XXX.XXX.XXX.XXX.XXX
	X.X...X...X...X.X.X.X...X.....X.X.X.X.X
	X.X...X.XXX.XXX.XXX.XXX.XXX...X.XXX.XXX
	X.X...X.X.....X...X...X.X.X...X.X.X...X
	XXX...X.XXX.XXX...X.XXX.XXX...X.XXX.XXX
	*/
	int t[] = {1, 2};
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 2; j++) {
			for (int k = i; k < i + 3; k++) cout << strs[t[j] - 1][k];
		}
		cout << endl;
	}
	return 0;
}

