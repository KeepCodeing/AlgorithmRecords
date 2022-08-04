#include <iostream>
using namespace std;
// 排序就行了？
// 排序不行（绝望），这样搞不到最有解，还是得回溯
// 洛谷的在线IDE里似乎没有这个常量 
const int INT_MAX = 1145141919;
class Solution {
public:
	int minSize = INT_MAX;
	// temp用来记录上次的状态，算是和模板回溯不同的一点 
	void dfs(int level, int deepth, int target, int temp, int s[]) {
		if (level == deepth || target <= 0) {
			if (target < 0) target += temp;
			if (target < minSize) minSize = target;
			return;
		}
		for (int i = level; i < deepth; i++) {
			target -= s[i];
			dfs(i + 1, deepth, target, s[i], s);
			target += s[i];
		}
	}
	int resovle() {
		int boxSize, eleCnt, eleSumSize = 0;
		bool flag = false;
		cin >> boxSize >> eleCnt;
		// 有两个根据数据范围来的特判，另外要考虑下“放不下”箱子体积为负的情况怎么办 
		if (boxSize == 0) return 0;
		int *elements = new int[eleCnt];
		for (int i = 0; i < eleCnt; i++) {
			cin >> elements[i];
			if (elements[i] <= boxSize) flag = true;
			eleSumSize += elements[i];
		}
		// 考虑到如果所有元素都装不下 
		if (!flag) return boxSize;
		// 下面这些都是可能的情况 
		// 如果只有一个元素
		if (eleCnt == 1) return boxSize >= eleSumSize ? boxSize - eleSumSize : boxSize;
		// 如果能装下所有元素 
		if (eleSumSize <= boxSize) return boxSize - eleSumSize;
		// 回溯排不排序都无所谓 
		// sort(elements, elements + eleCnt);
		// 如果所有元素体积都比箱子体积大呢（坠毁），回溯的话应该不用考虑这么多了，或者在上面写个flag 
		// if (elements[0] > boxSize) return boxSize;
		// 这里开始回溯
		dfs(0, eleCnt, boxSize, 0, elements);
		delete[] elements;
		return minSize;
	}
}; 
int main() {
	Solution s = Solution();
	cout << s.resovle();
	return 0;
}
//class Solution {
//public:
//	int resovle() {
//		int boxSize, eleCnt, eleSumSize = 0;
//		cin >> boxSize >> eleCnt;
//		// 有两个根据数据范围来的特判，另外要考虑下“放不下”箱子体积为负的情况怎么办 
//		if (boxSize == 0) return 0;
//		int *elements = new int[eleCnt];
//		for (int i = 0; i < eleCnt; i++) {
//			cin >> elements[i];
//			eleSumSize += elements[i];
//		}
//		// 如果只有一个元素
//		if (eleCnt == 1) return boxSize >= eleSumSize ? boxSize - eleSumSize : boxSize;
//		// 如果能装下所有元素 
//		if (eleSumSize <= boxSize) return boxSize - eleSumSize;
//		sort(elements, elements + eleCnt);
//		// 如果所有元素体积都比箱子体积大呢，
//		if (elements[0] > boxSize) return boxSize;
//		// 剩下来的情况就是物品体积大于箱子体积的情况，那么排完序了的话越靠前的元素就越小
//		// 也就是说我们可以用物品总体积减去当前物品体积，只要物品总体积小于或者等于箱子体积
//		// 了，就算合法解出现了
//		for (int i = 0; i < eleCnt; i++) {
//			// 现在剩下来的都是元素体积小于等于箱子体积的了，这里的减就相当于把小的元素剔除掉 
//			eleSumSize -= elements[i];
//			if (eleSumSize <= boxSize) return boxSize - eleSumSize;
//		} 
//		delete[] elements;
//	}
//}; 
