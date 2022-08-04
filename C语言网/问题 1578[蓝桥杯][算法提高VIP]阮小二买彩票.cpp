#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// 看了下以前用回溯写的，pre这个变量是一个dfs内的变量，而不是一个
// 参数...我忘记了啊... 

vector<int > vec;
int main() {
	int num;
	cin >> num;
	while (num) {
		vec.push_back(num % 10);
		num /= 10; 
	}
	sort(vec.begin(), vec.end());
	do {
		for (int i = 0; i < vec.size(); i++) cout << vec[i];
		cout << endl;
		// next_permutation()函数可以生成合法的有重复元素的全排列 
	} while(next_permutation(vec.begin(), vec.end()));
	return 0;
}
