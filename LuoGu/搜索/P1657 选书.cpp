#include <iostream>
#include <vector>
using namespace std;

// 套一层循环就完事了 
// 二维数组标记是否选过不可行，应该用一个专门的数组来，还有就是虽然一个人有两种选法，但是
// 所有人总的选法只有deepth种

// 其做法太低效了，每个人都标记下不如把选了的标记了 

int cnt = 0;
struct book {
	int ch[3];
};
bool use[25];
void dfs(int level, int deepth, bool arr[], int book_list[25][25]) {
	for (int i = 1; i <= deepth; i++) {
			for (int j = 1; j <= 2; j++) {
				if (!use[i] && book_list[level][j] == i) {
					use[i] = 1;
					// v.push_back(book_list[i].ch[j]); 
					dfs(level + 1, deepth, arr, book_list);
					// 将判断条件写在出口里可以加快回溯效率很多 
					if (level == deepth - 1) cnt++;
					// v.pop_back();
					use[i] = 0;
				}
				
			}
	}
}
int book_list[25][25];
int main() {
	int x;
	bool *arr;
	// book *book_list;
	cin >> x;
	// 用arr[i]元素表示第i个元素是否选过 
	arr = new bool[x + 1]();
	// 本来打算用vector的，不过可以用一维就用一维吧 
	// book_list = new book[x + 1];
	for (int i = 1; i <= x; i++) {
		cin >> book_list[i][1] >> book_list[i][2];
	}
	vector<int > v;
	dfs(1, x, arr, book_list);
	cout << cnt;
	delete[] arr, book_list;
	return 0;
}
/*#include <iostream>
#include <vector>
using namespace std;

// 套一层循环就完事了 

int cnt = 0;
struct book {
	int ch[3];
};
void dfs(int level, int deepth, bool arr[], book book_list[], int chooseCnt) {
	if (level == deepth + 1 && chooseCnt == deepth) {
		// for (int i = 0; i < v.size(); i++) cout << v[i] << ' ';
		// cout << endl;
		cnt++;
		return;
	}
	for (int i = level; i <= deepth; i++) {
			for (int j = 1; j <= 2; j++) {
				if (!arr[book_list[i].ch[j]]) {
					arr[book_list[i].ch[j]] = true;
					// v.push_back(book_list[i].ch[j]); 
					dfs(i + 1, deepth, arr, book_list, chooseCnt + 1);
					// v.pop_back();
					arr[book_list[i].ch[j]] = false;
				}
				
			}
	}
}
int main() {
	int x;
	bool *arr;
	book *book_list;
	cin >> x;
	// 用arr[i]元素表示第i个元素是否选过 
	arr = new bool[x + 1]();
	// 本来打算用vector的，不过可以用一维就用一维吧 
	book_list = new book[x + 1];
	for (int i = 1; i <= x; i++) {
		cin >> book_list[i].ch[1] >> book_list[i].ch[2];
	}
	vector<int > v;
	dfs(1, x, arr, book_list, 0);
	cout << cnt;
	delete[] arr, book_list;
	return 0;
}*/
