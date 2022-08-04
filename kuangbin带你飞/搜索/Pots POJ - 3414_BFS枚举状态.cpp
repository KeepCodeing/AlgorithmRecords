#include <iostream>
using namespace std;

// 看到题目虽然能想到BFS，不过却完全没有头绪呢...这种BFS也算第一次做，思路是通过BFS枚举所有状态集并且记录路径...
// 首先题目给出了三个操作，装满桶，清空桶，将一个桶的水倒到另一个桶里去...那么每个状态都有两种情况，装满a桶，装满
// b桶，清空a桶，清空b桶，将a桶的水倒到b桶，将b桶的水倒到a桶。总共六种状态，我们写的BFS也就是枚举这六种状态，就和
// 之前写的“素数路径”那个题一样...

const int N = 110;
// a桶的大小，b桶的大小和要均分的水的数量
int a, b, c;
struct Node {
	// a桶里的水，b桶里的水，操作数，当前节点的上一个节点（用来输出路径），所用最少步数
	int x, y, op, last, step;
	Node(int x, int y, int op, int last, int step) : x(x), y(y), op(op), last(last), step(step) {};
	Node() {};
} que[N * N + 10];
// 用来标记a桶装了多少水，b桶装了多少水..
bool visited[N][N];
// 打印结果.. 
void print(int op) { 
	if(op == 1) cout << "FILL(1)" << endl;
	else if (op == 2) cout << "FILL(2)" << endl;
	else if (op == 3) cout << "POUR(2,1)" << endl;
	else if (op == 4) cout << "POUR(1,2)" << endl;
	else if (op == 5) cout << "DROP(1)" << endl;
	else cout << "DROP(2)" << endl;
}
// 倒序输出，因为要求输出操作过程 
void printPath(int last) {
	if (que[last].last == 0) {
		print(que[last].op);
		return;
	}
	printPath(que[last].last);
	print(que[last].op);
}
void bfs() {
	int qtop = 0, qback = 0;
	// 初始化ab桶的水的数量
	que[qtop] = Node(0, 0, 0, 0, 0);
	int at, bt;
	while (qtop <= qback) {
		Node now = que[qtop++];
		// 如果找到了答案输出步数和路径，注意是任意一个杯子满足就行 
		if (now.x == c || now.y == c) {
			cout << now.step << endl;
			printPath(qtop - 1);
			return;
		}
		// 枚举这6种操作对应的情况
		for (int i = 1; i <= 6; i++) {
			// 将a桶装满的情况，a桶的水等于其容积，b桶的水不变
			if (i == 1) at = a, bt = now.y;
			// 将b桶装满的情况，同a桶
			else if (i == 2) at = now.x, bt = b;
			// 将b桶的水倒入a桶的情况，要么a桶被倒满了，要没被倒满，没倒满a桶的水就是原来的水加b桶的水，
			// b桶的水要么倒完了，要么没有，没有的情况b桶的水就是原来的水减去a桶还可以装多少水...
			else if (i == 3) at = min(a, now.x + now.y), bt = max(0, now.y - (a - now.x));
			// 将a桶的水倒入b桶，同理
			else if (i == 4) bt = min(b, now.x + now.y), at = max(0, now.x - (b - now.y));
			// 清空a桶，b桶水不改变
			else if (i == 5) at = 0, bt = now.y;
			// 清空b桶，a桶水不改变
			else at = now.x, bt = 0;
			// 判断下当前枚举的状态是否使用过了，入队当前枚举的状态
			if (!visited[at][bt]) {
				visited[at][bt] = true;
				// 注意这里记录上一个状态的方式，是通过队头的下标来的，当前的六个状态都是根据队头元素来的
				// 而队头在取元素的时候进行了自增，因此要减回去..
				que[++qback] = Node(at, bt, i, qtop - 1, now.step + 1);
			}

		}
	}
	// 不可能凑出来的情况 
	cout << "impossible" << endl;
}
int main() {
	cin >> a >> b >> c;
	bfs();
	return 0;
}
