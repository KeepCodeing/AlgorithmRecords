#include <iostream>
#include <algorithm>
using namespace std;

// �����棬û˵��ʽ��ߵ���ֻ������λ��... 
// ���о��ǵ�ʽ�ұߵ���������ֻ������λ������λ���ģ�����һλ����λ�ģ�ȫ���в�����ֳ�������λ�õ������Ҫע�������α�֤
// �ֵ�����С����ʵ���ȫ������Ȼ������... 

const int N = 10;
int nums[N];
int main() {
	for (int i = 1; i <= 9; i++) nums[i] = i;
	do {
		 int z = nums[0] * 1000 + nums[1] * 100 + a[2] * 10 + a[3];
        int x1=a[4];
        int x2=a[4]*10+a[5];
        int y1=a[5]*1000+a[6]*100+a[7]*10+a[8];
        int y2=a[6]*100+a[7]*10+a[8];
        if(z==x1*y1) printf("%d = %d x %d\n",z,x1,y1);
        if(z==x2*y2) printf("%d = %d x %d\n",z,x2,y2);
	} while(next_permutation(nums + 1, nums + 9));
	return 0;
}
