#include <iostream>
#include <queue>
using namespace std;

// 带根堆，和洛谷上的题类似 
// 草w，原来C++默认是带根堆，因为写最短路用的是priority_queue<int, vector<int>, greater<int > > que这种形式的
// 堆，一瞬以为是按边权从大到小排序的，然而写完才想起来是最短路是路径最小... 

class Solution {
public:
	priority_queue<int > que;
    vector<int > res;
	vector<int> smallestK(vector<int>& arr, int k) {
		int aLen = arr.size();
		if (!aLen || !k) return res;
		for (int i = 0; i < aLen; i++) {
			que.push(arr[i]);
			k--;
//            if (k < 0) que.pop(), k = 0; 
		}
		while (que.size()) res.push_back(que.top()), que.pop();
        return res;
    }
};

int main() {
	priority_queue<int> que;
	int n;
	cin >> n;
	int t;
	while (n--) cin >> t, que.push(t);
	while (que.size()) cout << que.top(), que.pop(); 
	return 0;
}
