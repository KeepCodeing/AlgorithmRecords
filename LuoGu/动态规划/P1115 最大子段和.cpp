#include <iostream>
using namespace std;

// 好像是最基础的动规题...细节忘了很多，只知道要使当前值最大
// 就有公式max(dp[i - 1], dp[i - 1] + arr[i])，但是好像还有
// 负数情况的处理细节 

// 不是这样哦！主要还是考虑的前面的子段和是否大于0，如果
// 前面的子段和大于0，就可以加上当前数，如果小于0，说明
// 即使加上当前数结果也不会更大，还不如重新开始 

// 还有种解法是判断当前值大还是之前的和大 
 
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
        cin>>n[i];//输入
        ans[i]=max(ans[i-1]+n[i],n[i]);//DP
        sum=max(sum,ans[i]);//取最大值也同时进行，节约时间
    }
    cout<<sum;//直接输出
    return 0;
}
*/
