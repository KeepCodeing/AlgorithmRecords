#include <iostream>
using namespace std;
// ��������ˣ�
// �����У��������������㲻�����н⣬���ǵû���
// ��ȵ�����IDE���ƺ�û��������� 
const int INT_MAX = 1145141919;
class Solution {
public:
	int minSize = INT_MAX;
	// temp������¼�ϴε�״̬�����Ǻ�ģ����ݲ�ͬ��һ�� 
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
		// �������������ݷ�Χ�������У�����Ҫ�����¡��Ų��¡��������Ϊ���������ô�� 
		if (boxSize == 0) return 0;
		int *elements = new int[eleCnt];
		for (int i = 0; i < eleCnt; i++) {
			cin >> elements[i];
			if (elements[i] <= boxSize) flag = true;
			eleSumSize += elements[i];
		}
		// ���ǵ��������Ԫ�ض�װ���� 
		if (!flag) return boxSize;
		// ������Щ���ǿ��ܵ���� 
		// ���ֻ��һ��Ԫ��
		if (eleCnt == 1) return boxSize >= eleSumSize ? boxSize - eleSumSize : boxSize;
		// �����װ������Ԫ�� 
		if (eleSumSize <= boxSize) return boxSize - eleSumSize;
		// �����Ų���������ν 
		// sort(elements, elements + eleCnt);
		// �������Ԫ�������������������أ�׹�٣������ݵĻ�Ӧ�ò��ÿ�����ô���ˣ�����������д��flag 
		// if (elements[0] > boxSize) return boxSize;
		// ���￪ʼ����
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
//		// �������������ݷ�Χ�������У�����Ҫ�����¡��Ų��¡��������Ϊ���������ô�� 
//		if (boxSize == 0) return 0;
//		int *elements = new int[eleCnt];
//		for (int i = 0; i < eleCnt; i++) {
//			cin >> elements[i];
//			eleSumSize += elements[i];
//		}
//		// ���ֻ��һ��Ԫ��
//		if (eleCnt == 1) return boxSize >= eleSumSize ? boxSize - eleSumSize : boxSize;
//		// �����װ������Ԫ�� 
//		if (eleSumSize <= boxSize) return boxSize - eleSumSize;
//		sort(elements, elements + eleCnt);
//		// �������Ԫ�������������������أ�
//		if (elements[0] > boxSize) return boxSize;
//		// ʣ���������������Ʒ�����������������������ô�������˵Ļ�Խ��ǰ��Ԫ�ؾ�ԽС
//		// Ҳ����˵���ǿ�������Ʒ�������ȥ��ǰ��Ʒ�����ֻҪ��Ʒ�����С�ڻ��ߵ����������
//		// �ˣ�����Ϸ��������
//		for (int i = 0; i < eleCnt; i++) {
//			// ����ʣ�����Ķ���Ԫ�����С�ڵ�������������ˣ�����ļ����൱�ڰ�С��Ԫ���޳��� 
//			eleSumSize -= elements[i];
//			if (eleSumSize <= boxSize) return boxSize - eleSumSize;
//		} 
//		delete[] elements;
//	}
//}; 
