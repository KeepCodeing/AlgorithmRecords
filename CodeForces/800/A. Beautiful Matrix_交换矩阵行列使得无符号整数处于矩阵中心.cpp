#include <iostream>
#include <cmath>
using namespace std;

// 乍一看是个模拟，但是感觉这样很麻烦，因为只有一个数字要被换到指定的位置，故而非该数字所在的行列无论怎么换
// 也不会对逼近答案有任何贡献，而题目说只能换相邻的两行或者两列，由此可以推断出只要将非0数组所在的行减去中间行
// 的位置的差的绝对值即是其换到中间行要的步数，同理，列也是一样... 


int main() {
	int row, col, num;
	for (int i = 1; i <= 5; i++) {
		for (int j = 1; j <= 5; j++) {
			cin >> num;
			// 题目没说那个无符号整形一定是1，不过其一定不是0，然后记录到了位置就可以直接算了 
			if (num) {
				row = i, col = j;
				break;
			}
		}
	}
	cout << abs(row - 3) + abs(col - 3) << endl;
	return 0;
}
