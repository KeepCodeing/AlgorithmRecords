#include <iostream>
using namespace std;

// ������������Ķ�����...ϸ�����˺ֻ֪ܶ࣬��Ҫʹ��ǰֵ���
// ���й�ʽmax(dp[i - 1], dp[i - 1] + arr[i])�����Ǻ�����
// ��������Ĵ���ϸ�� 

// ��������Ŷ����Ҫ���ǿ��ǵ�ǰ����Ӷκ��Ƿ����0�����
// ǰ����Ӷκʹ���0���Ϳ��Լ��ϵ�ǰ�������С��0��˵��
// ��ʹ���ϵ�ǰ�����Ҳ������󣬻��������¿�ʼ 

// �����ֽⷨ���жϵ�ǰֵ����֮ǰ�ĺʹ� 
 
int *arr, *dp; 
int main() {
	int n;
	cin >> n;
	arr = new int[n];
	dp = new int[n + 1];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	dp[0] = 0;
	for (int i = 1; i <= n; i++) {
		dp[i] = max(dp[i - 1], 0) + arr[i - 1];
	}
	int ans = dp[1];
	for (int i = 2; i <= n; i++) ans = max(ans, dp[i]); 
	cout << ans;
	delete[] arr, dp;
	return 0;
}
/*
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n[200001],p,ans[200001]={0};
    int sum=-9999999;//|x|<=10000   QWQ
    cin>>p;
    for(int i=1;i<=p;i++)
    {
        cin>>n[i];//����
        ans[i]=max(ans[i-1]+n[i],n[i]);//DP
        sum=max(sum,ans[i]);//ȡ���ֵҲͬʱ���У���Լʱ��
    }
    cout<<sum;//ֱ�����
    return 0;
}
*/
