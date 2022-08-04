#include <iostream>
using namespace std;

// �ǵ���ǰȺ���ƺ����������..
// ��F(i, j, k)��ʾ��i�룬ħ��ֵΪjʱ�ĵ�k��״̬����Ϣ����Ϣ������Ӧ��Ҫ������Ϣ�Ͳ���Ϣ�Լ�ʹ��ħ�������ߵ������� 
// F(i, j, k)�����¼��־��ߣ� 
// ��F(i, PII(j, k, m))��ʾ��i�룬�ߵ���Զ����Ϊj����k��״̬����ֵΪm�����
// ֮��Ӧ�ð�״̬������Ϊһάʹ��.. 
// F(i, PII(j, 0, m)) = max{F(i - 1, PII(j, 0, m + 4)), F(i - 1, PII(j, 1, m + 4)), F(i - 1, PII(j, 2, m + 4))}�����ߵ���������벻�䣬���Ƿ���ֵ+4
// F(i, PII(j, 1, m)) = max{F(i - 1, PII(j, 0, m)), F(i - 1, PII(j, 1, m)), F(i - 1, PII(j, 2, m))} + 17���ߵ����������һ����/����/��ħ���ߵľ�����ѡ������
// F(i, PII(j, 1, m)) = max{F(i - 1, PII(j, 0, m - 10)), F(i - 1, PII(j, 1, m - 10)), F(i - 1, PII(j, 2, m - 10))} + 60��ħ���ߵ������ͬ��������һ�������
// ״̬��ѡ 

// ���븴����w����ȷ������ֱ��̰�ģ����������֣�Ȼ��������������Ϣ���������ֵ��߼�֮���ٶ�ԭ�����ܱ�ͽ�����߼�...���������Ĵ���...������ķ�ʽƭ��40��w 

const int N = 300000 + 10;
struct Status {
	int far, m, tm;
	Status (int far, int m, int tm) : far(far), m(m), tm(tm) {};
	Status () {};
} f[N][3];
Status my_max(Status s1, Status s2, Status s3, int flag, int tm) {
	Status m_s;
	if (s1.far > s2.far) m_s = s1;
	else m_s = s2;
	if (m_s.far < s3.far) m_s = s3;
	if (flag == 0) m_s.m += 4;
	else if (flag == 1) m_s.far += 17;
	else if (flag == 2) {
		// ���������ħ��������ħ��������-10��ֱ��д��>=0��w�� 
		if (m_s.m - 10 >= 0) m_s.m -= 10, m_s.far += 60;
		// ���������ħ������ô����ѡ��ͽ��������Ϣ��ע�⣬���ﶼ�Ƕ�m_s���״̬���Եģ�Ҳ����˵���޸ĵ�ǰ�����m_s��������s1��s2... 
		// �������ƺ���������m_s���״̬���ԣ�������Ϣ����ͽ��ȡ�����ܷ�ʹ�þ����Զ�������������ж��ֿ����ˣ������ǰ��Ϣ��ʹ����һ��
		// �ܹ�ʹ��ħ������ô���ǻ��ֱ��ѡ��ͽ���������ģ��������ѡ������Ϣ��ȴû��ʱ��ʹ�ã���ôҲ��ûͽ����������w..���ﻹ��̰��һ��
		// ֻѡͽ������...������������Ȼ�ǲ������.. 
		else if (m_s.m + 4 >= 10) {
			m_s.m = m_s.m + 4 - 10;
			m_s.tm = tm + 1;
			m_s.far += 60;
			return m_s;
		}
		else m_s.far += 17;
//		else if (s3.far + 17 > s2.far)
//		else if (s1.far > s2.far) s3.far += 17, m_s = s3;
//		else s3.m += 4, m_s = s3;
	}
	m_s.tm = tm;
	return m_s;
}
int main() {
	int m, s, t;
	cin >> m >> s >> t;
	f[0][0] = f[0][1] = f[0][2] = Status(0, m, 0);
	for (int i = 1; i <= t; i++) {
		// ��Ϣ�����������һ�������������������״̬�ù�����Ȼ��ѷ���ֵ�ָ� 
		f[i][0] = my_max(f[i - 1][0], f[i - 1][1], f[i - 1][2], 0, i);
		// ͽ���ߵ������ͬ������һ������������������״̬�ù�����Ȼ�󽫾������� 
		f[i][1] = my_max(f[i - 1][0], f[i - 1][1], f[i - 1][2] , 1, i);
		// ʹ��ħ����������������Ҫ�ж����Ƿ����㹻��ħ��������У��������ħ�������û�У�����ѡ��ͽ���߻�����Ϣ����Ȼ��Ҳ��ȡ����
		// �������
		f[i][2] = my_max(f[i - 1][0], f[i - 1][1], f[i - 1][2] , 2, i); 
	}
	int res = 0;
	bool flag;
	for (int i = 1; i <= t; i++) {
		flag = false;
		for (int j = 0; j < 3; j++) {
			if (f[i][j].tm == i) res = max(res, f[i][j].far);
			else flag = true;
		}
		if (flag) i++;
		if (res >= s) {
			cout << "Yes" << endl;
			cout << i << endl;
			return 0;
		}
	}
	cout << "No" << endl;
	cout << res << endl;
//	for (int i = 1; i <= t; i++) {
//		cout << f[i][0].far << ' ' << f[i][1].far << ' ' << f[i][2].far << endl;
//		cout << f[i][0].tm << ' ' << f[i][1].tm << ' ' << f[i][2].tm << endl;
//		cout << f[i][0].m << ' ' << f[i][1].m << ' ' << f[i][2].m << endl;
//		cout << endl;
//	}
	return 0;
}
/*
#include <cstdio>
#include <algorithm>
using namespace std;
int dp[300001];
int main(){
    int m,s,t;
    scanf("%d%d%d",&m,&s,&t);
    for(int i=1;i<=t;i++){//������˸����
        if(m>=10)dp[i]=dp[i-1]+60,m-=10;//������ã�����
        else dp[i]=dp[i-1],m+=4;//������Ϣ
    }
    for(int i=1;i<=t;i++){dp[i]=max(dp[i],dp[i-1]+17);//�����ܲ���dp[i]Ϊʹ�÷������ܲ������ֵ�����ţ�
    if(dp[i]>=s){printf("Yes\n%d",i);return 0;}//��������˾���s���ͳɹ��ˣ����yes
    }printf("No\n%d",dp[t]);//û�ɹ������no
    return 0;
}
*/
