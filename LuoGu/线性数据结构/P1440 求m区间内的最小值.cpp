//#include <iostream>
//#include <queue>
//#include <cstdio>
//using namespace std;
//
//// �������ڣ����Ǳ�five������ô������ģ�ⵥ��ջ�͵��������ˣ����ܣ�
//// ������priority_queue()���ԣ�STL������ȶ��к�����Ĭ�ϴ󶥶ѣ������
//// �ø�С���� 
//
//// �ݣ����������ͨ�Ļ������ڣ���������ĳ����ǰ�Ĵ��������... 
//
//// Ȼ��׹����...��Ϊ���ȶ��л��Զ����򣬶����������ǵ�ǰ��֮ǰ��һ���������ֵ
//// Ҳ����ǰ�����һ�����������һ���ܱ�ɾ��...
//
//// ��STLд����˫�˶���..������ģ�ⶼ����... 
//
//priority_queue<int, vector<int >, greater<int > > pri_que;
//int main() {
//	//for (int i = 0; i < 10; i++) pri_que.push(i);
//	//while (!pri_que.empty()) cout << pri_que.top(), pri_que.pop(); 
//	int n, m, t;
//	scanf("%d%d", &n, &m);
//	scanf("%d", &t);
//	pri_que.push(t), n--; 
//	printf("0\n");
//	while (n--) {
//		scanf("%d", &t);
//		if (pri_que.size() > m) pri_que.pop();
//		printf("%d\n", pri_que.top());
//		pri_que.push(t); 
//	}
//	return 0;
//} 

#include<bits/stdc++.h>
using namespace std;
int n,m,a[2000002];
priority_queue< pair< int , int > > q;//��Ԫ������ 
int main()
{
cin>>n>>m>>a[1];//�Ȱ�a[1]���벢������� 
q.push(make_pair(-a[1],1));//ÿ�η����෴����ȡ����ȻҲҪ��һ�£���������С���� 
printf("%d\n",0);//��һ����Զ���0 
for(int i=2;i<=n;i++){
    cin>>a[i];//���� 
    int x=q.top().second;//ȥ�����й�ʱ�ĶѶ� 
//    cout << x  << ' ' << i << endl;
    while(i-m>x){
        q.pop();
        x=q.top().second;
    } 
    //printf("%d\n",-q.top().first);//ȥ�෴��������ڵĶѶ� 
    q.push(make_pair(-a[i],i));//����ٽ���ǰֵ������У���Ϊǰm��ֵ���ǲ�������ǰֵ�ģ� 
}
return 0;
}
