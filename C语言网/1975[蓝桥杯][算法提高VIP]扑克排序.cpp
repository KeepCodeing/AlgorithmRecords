#include <iostream>
#include <algorithm>
#include <cstdio> 
using namespace std;

// 还是借助结构体+STL完成罢，另外输入格式通过C的输入来控制 
// 这样写太大脑升级了，还是不建议... 
// 不过题解好像大多是这个思路，奇妙 

struct poke {
	// 转换为数字对比 
	int num, flower;
	// 输出用的字符 
	char outNum, outFlower;
	poke (int n = 0, int f = 0) {
		num = n, flower = f;
	}
	bool operator<(const poke& p) {
		if (num != p.num) return num < p.num;
		return flower < p.flower;
	}
};
poke pk[5];
int main() {
	char flower, num;
	char temp;
	for (int i = 0; i < 5; i++) {
		scanf("%c%c", &num, &flower);
		// 对10进行特殊处理，因为其它数字都是一位的，而10在字符下是两位 
		if (num == '1' && flower == '0') {
			pk[i].num = 10;
			// 10比较特殊标记下 
			pk[i].outNum = 't';
			temp = getchar();
			pk[i].outFlower = temp;
			if (temp == 'd') pk[i].flower = 0;
			else if (temp == 'c') pk[i].flower = 1;
			else if (temp == 'h') pk[i].flower = 2;
			else if (temp == 's') pk[i].flower = 3;
			continue;
		}
		// 将字母转换为数字 
		pk[i].outNum = num;
		if (num >= '2' && num <= '9') pk[i].num = (int)(num - '0');
		else if (num == 'J') pk[i].num = 11;
		else if (num == 'Q') pk[i].num = 12;
		else if (num == 'K') pk[i].num = 13;
		else if (num == 'A') pk[i].num = 14;
		// 将花色转换为数字 
		pk[i].outFlower = flower;
		if (flower == 'd') pk[i].flower = 0;
		else if (flower == 'c') pk[i].flower = 1;
		else if (flower == 'h') pk[i].flower = 2;
		else if (flower == 's') pk[i].flower = 3;
	}
	// 排序输出
	sort(pk, pk + 5);
	for (int i = 0; i < 5; i++) {
		// 10的特殊处理 
		if (pk[i].outNum == 't') {
			cout << 10 << pk[i].outFlower;
			continue;
		}
		cout << pk[i].outNum << pk[i].outFlower;
		if (i != 4) cout << ' ';
	}
	return 0;
}
