#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// ���������������ģ��������������ģ��ֱ��Ӧ��STL���
// lower_bound��upper_bound��һ�������ҵ�һ�����ֵĸ���
// һ�������ҵ�һ���ȸ�������� 

vector<int > vec;
int main() {
	int n, q;
	cin >> n >> q;
	int temp;
	while (n--) cin >> temp, vec.push_back(temp);
	int vLen = vec.size();
	while (q--) {
		cin >> temp;
		// �������������ʼλ��
		int sIndex = lower_bound(vec.begin(), vec.end(), temp) - vec.begin();
		// ��������û�г��ֹ�������Ҳ�������� 
		if (vec[sIndex] != temp) {
			cout << "-1 -1" << endl;
			continue;
		} 
		int eIndex = upper_bound(vec.begin(), vec.end(), temp) - vec.begin();
		if (eIndex >= vLen) {
			// ���У���������������������upper_index�᷵��һ��������±�
			// �ȿӶ������ĩβֻ��һ�����ֵ����ôȷʵ�����λ�ú��յ�
			// λ����һ���ģ���������ж���Ļ�����Ǹ�λ�õ����ֵ��λ�ò�������Ҫ��λ�� 
			cout << sIndex << ' ' << vLen - 1 << endl;
			continue; 
		}
		// �ȿ�һ�������������˾���Ϊ������ȷ�ģ�Ȼ��׹���ˣ����
		// ����û��һ����Ϊ�ҵ����ǵ�һ�������ֵ��... 
		cout << sIndex << ' ' << eIndex - 1 << endl;
	}  
	return 0;
}
