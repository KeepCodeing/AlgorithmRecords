#include <iostream>
#include <algorithm>
using namespace std;

// ֻ�뵽�˱�������w��n^2�����赱ǰѧ���Ĵ�ȫ�ԣ�Ȼ��ö������λ�õ�����
// ѧ���Ĵ𰸣��Ե�ǰλ�õ�ѧ���Ĵ�Ϊ��׼���ж����Ǽ��������ö��ٷ֣�����
// ����ʹÿ��ѧ������һ�����֣����ǻ���5�����Ҫ���ǣ��Ǿ���ȫ��һ���𰸵�
// ������ڶ�����������Ӧ�þ�����ʾ�ˣ���Ȼÿ��ѧ��������һ�������ֵ������
// ��������������ܱ�֤�ܷ�����������ѧ��ѡ��ȫ�Ƿ�ֵ�����Ǹ�ѡ����... 
// д���·��ֲ��ܽ�ȫ��һ���𰸵������Ϊѧ�����������ͻᡰ����� �����ɸ�
// ѧ������˽��䵥����ȡ��������... 

// TLE��ww����һ��˼·�����𰸿���һ����ά���飬Ȼ��ͳ�Ƶ�һ���ж��ٸ�A��B��C..�ڶ����ж��ٸ������Դ����ƣ�Ȼ��ö��ÿһ����A��B��C..Ϊ��ʱ
// �ܻ�ȡ�ķ���... 

const int N = 1000 + 10;
string stu[N];
int scores[N];
int bucket[N][10];
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> stu[i];
	for (int i = 0; i < m; i++) cin >> scores[i];
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) bucket[i][stu[i][j] - 'A']++;
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < 5; j++) cout << bucket[i][j] << ' ';
		cout << endl;
	}
	return 0;
}
//const int N = 1000 + 10;
//string stu[N];
//int scores[N];
//int main() {
//	string tt = "ABCDE";
//	do {
//		cout << tt << endl;
//	} while(next_permutation(tt.begin(), tt.end()));
//	int n, m;
//	cin >> n >> m;
//	for (int i = 0; i < n; i++) cin >> stu[i];
//	for (int i = 0; i < m; i++) cin >> scores[i];
//	// �ô��Ե�i��λ�õ�ѧ��Ϊ��׼ 
//	int res = 0, t;
//	for (int i = 0; i < n; i++) {
//		t = 0;
//		for (int j = 0; j < n; j++) {
//			for (int k = 0; k < m; k++) {
//				// �Աȸ�λ�ϵĴ𰸣������ȷ�����Ϸ�ֵ 
//				if (stu[i][k] == stu[j][k]) t += scores[k];
//			}
//		}
//		res = max(res, t);
//	}
//	// ��ȫѡһ���𰸵����Ҳ�ӵ�����... 
//	for (int i = 0; i < 5; i++) {
//		t = 0;
//		for (int j = 0; j < n; j++) {
//			for (int k = 0; k < m; k++) {
//				if (stu[j][k] == (char)('A' + i)) t += scores[k];	
//			}
//		}
//		res = max(res, t);
//	} 
//	cout << res << endl;
//	return 0;
//}
