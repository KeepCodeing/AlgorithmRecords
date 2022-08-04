#include <iostream>
using namespace std;

// 这种类型的题是贪心问题，首先考虑怎么样的贪心方案才是合法的
// 因为每次只能选开头的字母和结尾的字母，我们是否可以简单的认为要使新字符串的字典序最小，在每次选择时就使当前字符字典序
// 最小呢？答案是可行的，但是如果当前选择的两个字符相同呢？如果只是随便选一个字符的话，还能保证接下来的选择字典序最小吗？
// 答案是不行，因为我们要保证新字符串的字典序最小，就要保证字典序较小的字符串永远都是优先被选择的，那么如果上面那个情况
// 我们随便选了一个字符，它并不能保证i - 1, i -2...处的字符字典序就要小于另一个位置的字符，如此思考下去，我们发现：当两个
// 字符不相同时，选择字典序最小的字符即可，当两个字符相同时，要保证当前选择的这一边的字符后面/前面的第一个不相同的字符字典
// 序最小，例如aabbccddaa，我们发现有两个aa重复了，这时继续向后选，可以得到先选左边的a更优，因为这个a后面的b比右边a后面的d
// 字典序更小，这样就可以保证我们下次选择的时候字典序小的字符总是被优先选择... 

// 双指针对比坠毁了，因为这个字符串不一定是个对称的，也就是指left指针不一定和right指针对称（这里似乎是可以保证对称的）
// 去洛谷找到了原题，看题解似乎不是简单的贪心加双指针...果然贪心过样例么w 

// 气急败坏交了十一次，因为输出格式半天没搞定，书上没有说换行，本five虽然看到了题面里的换行但是还是因为池沼搞了半天... 

// 啊啊，搞了半天这个题，贪心题，真是难呢w 

const int N = 2010;
char letters[N];
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> letters[i];
	int left = 0, right = n - 1;
	string res;
	bool flag;
	int cnt = 1;
	while (left <= right) {
		flag = false;
		// 精髓所在，利用这个循环可以正序倒序对比头尾字符以及如果他们相同后面的字符的字典序... 
		for (int i = 0; i + left < right; i++) {
			// 模拟下left就是从0到right，而right就是从right到0 
			if (letters[left + i] < letters[right - i]) {
				flag = true;
				break;
			} else if (letters[left + i] > letters[right - i]) {
				flag = false;
				break;
			}
		}
		// 这里也可以直接输出... 
		if (flag) res += letters[left++];
		else res += letters[right--];
	}
	int rLen = res.size();
	// 不要忘记换行哦（绝望） 
	for (int i = 0; i < rLen; i++) {
		cout << res[i];
		if ((i + 1) % 80 == 0) cout << endl;
	}
	return 0;
}

/*
// 事实证明就是简单的字符串贪心，这里考虑了下为什么双指针不可行，观察循环for (int i = 0; i + left < right; i++)
// 可以发现right这个变量全程没有发生改变，同样left也没有发生改变，只有偏移量发生了改变。

// 想了下发现了症结所在，书里说是正着对比一次，反着对比一次，如果我们仅仅进行一次简单的双指针，可以认为只是进行了
// 一次正序对比，这这对于部分重复字符串的情况可能可行， 但不适用于与所有情况，如果倒序对比加正序对比，就可以完全
// 确认先选哪个字符串 
 
// 存疑，因为例题过不了，而看题解那个例题又不像简单的字符串贪心 
while (left <= right) {
	// 这里采用其更加熟悉的双指针对比头尾字符串
	flag = false;
	int tl = left, tr = right;
	while (tl < tr) {
		if(letters[tl++] < letters[tr--]) {
			flag = true;
			break;
		} else if (letters[tl++] > letters[tr--]) {
			flag = false;
			break;
		}
	}
	if (flag) res += letters[left++];
	else res += letters[right--];
}
*/
