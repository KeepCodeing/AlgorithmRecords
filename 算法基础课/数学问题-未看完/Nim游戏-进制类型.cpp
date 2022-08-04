#include <iostream>
using namespace std;
// 一共有N堆石子，编号1..n，第i堆中有a[i]个石子，每一次操作alc和udk都可以从任意一堆石子中
// 取出任意数量的石子，每次至少取出一颗，至多取出全部石子，两方分别行动，取完所有石子的一方
// 获胜，alc为先手，给定a，假设两人都采用最佳策略，谁会取胜？
// 分析：假设有3堆石子，第一堆有3个石子，第二堆有4个 ，第三堆有5个，根据证明如果将每堆石子的数量看 
// 为2进制，如011,100,110，再对它们全都进行一次异或操作，最后结果不为0，alc胜，相反udk胜 
int main() {
	int arr[4] = {1, 4, 5, 1142};
	int res = 0;
	for (int i = 0; i < 3; i++) res ^= arr[i];
	if (res) cout << "ALC WIN!";
	else cout << "UDK WIN!";
	return 0;
}
