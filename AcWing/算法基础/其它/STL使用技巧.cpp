#include <iostream>
#include <queue>
using namespace std;

// vector:底层使用了倍增的思想，即每次内存空间占满后，都将接下来分配
// 的内存空间扩大一倍，理论上来说插入新元素可以达到O(1)的速度，可以
// 按照字典序进行对比，另外，其提供的size()方法只需要O(1)的复杂度 

// string:常用的substr(start, offset)方法，当截取长度超过剩余字符串长度时，会返回剩余
// 的所有字符串，当只指定start参数时，会返回从start开始后的所有字符串，c_str()方法
// 会返回该字符串的头指针，即可使用printf输出string 

// priority_queue：默认是个大顶堆，要将其改成小顶堆有两种方法，一种是直接插入
// -x，另一种是提供一个对比函数

// pair:可以看成有两个变量的结构体，且自带一个比较函数 

int main() {
	return 0;
}
