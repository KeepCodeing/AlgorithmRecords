#include <iostream>
using namespace std;

// 事实上其搞错了状态w..暂且不想做了w.. 
// 根据上一次坠毁的经验来看，这个题只有一个状态，而不能分成两个讨论，由此导致它的状态转移方程应该也是一个。那么惯例的，先写式子。
// 设F(i, j)为第i个起点，在第j天的最小疲劳值，为什么这里可以省去走或者不走这个状态呢？因为我们可以发现不管是走，还是不走，他们取
// 一个最优解最后都是产生一个新的状态，走，那么新状态就是走的花费，不走，那么新状态就是昨天走的最优解。
// 通过F(i, j)可以得到，第i个起点第j天的最优解由昨天的最优解以及今天的选择决定，F(i - 1, j - 1)表示第i - 1个起点，第j - 1天的最优
// 解（只有j-1天过了才能选第j天），而F(i, j - 1) * 花费就是第i - 1个起点走到第i个起点的花费，那么可以知道，F(i, j)要么是不走，要么
// 是走，不走的话，最优解就是昨天的最优解，走的话，最优解就是今天走的疲劳值，所以有方程F(i, j) = min{F(i - 1, j - 1), F(i, j - 1) * 花费}
 

int main() {
	return 0;
}
