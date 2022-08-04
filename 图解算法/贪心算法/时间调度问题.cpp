#include <iostream>
#include <algorithm>
using namespace std;

// ����������¾��Ǹ������ɸ�ʱ�����䣬ͬһ��ʱ�������ڲ����������£�Ҫ���������ʲô

// �����һ�ſα����оٳ������пεĿ�ʼ�ͽ���ʱ�䣬������ֻ��һ�����ҿ��ã���һ������
// ����ͬʱ�����ڿΣ�Ҫ�����������϶��ٽڿ�

// ֻҪ��ǰѡ��ĿεĽ���ʱ����������ϸ���ĿΣ�����
// ��ѧ:[9, 10],Ӣ��:[9.5, 10.5],�����:[10, 11], C����:[10.5, 11.5]
// ����:[11, 12] 

/*5
9 10
9.5 10.5
10 11
10.5 11.5
11 12*/
struct Courses {
	float start;
	float end;
	// ����<��������������� 
	bool operator<(const Courses& s1) {
		// >������<�ǽ��� 
		return this->end < s1.end;
	}
	Courses(float s = 0, float e = 0) {
		start = s, end = e;
	}
}; 
int resolve(Courses arr[], int n) {
	// ������ô��������ѡһ����� 
	int cnt = 1;
	// ��Ϊ������ǰ�Ŀγ̾��ǽ���ʱ������Ŀγ� ����������
	// ��һ��j�����浱ǰ����ʱ������Ŀγ̵��±꣬Ȼ��������γ� 
	// �Ľ���ʱ����������Ƚϣ�����ÿγ̵Ľ���ʱ��С�ڻ��ߵ���
	// ��һ���γ̿�ʼ��ʱ�䣬��˵�����ҿ�������һ�Σ�ͬʱ����
	// j���ٽ��жԱ� 
	int j = 0;
	for (int i = 1; i < n; i++) {
		// �������ʱ��С�ڻ��ߵ�������γ̵Ŀ�ʼʱ�䣬�Ϳ����ý��� 
		if (arr[j].end <= arr[i].start) {
			// ���ӽ�� 
			cnt++;
			// ���µ�ǰ����ʱ������Ľ��� 
			j = i;
		}
	}
	return cnt;
}
int main() {
	int n;
	cin >> n;
	Courses *arr = new Courses[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i].start >> arr[i].end;
	}
	sort(arr, arr + n);
	cout << resolve(arr, n) << endl;
	delete[] arr;
	return 0;
}
