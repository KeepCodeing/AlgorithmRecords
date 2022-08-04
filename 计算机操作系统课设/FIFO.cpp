#include<iostream>
#include<cstdlib>
#include<ctime>
#include<vector>
#include<queue>
#include<algorithm>
#include<windows.h> 
using namespace std;

//搜索函数 
int search(vector<int> number, int num, int CacheSize){
	for(int i = 0; i < CacheSize; i++){
		if(number[i] == num){
			return i;
		}
	}
	return 0;
}

//FIFO算法 
void FIFO( int CacheSize ){
	//随机函数生成地址
	srand( time(0) ); 
	vector<int> number;//用来存储内存块 
	int end = ( rand() % 11 ) + 10;
	cout << "正在随机生成存储地址流：";
	for( int i = 0; i < end; i++){
		number.push_back(( rand() % 9 ) + 1 );
		Sleep(200);
		cout << number[i] << "  ";
	}
	cout << "(内存块大小" << CacheSize << ")" << endl; 
	for(int i = 0 ; i < CacheSize; i++){
		cout << number[i] << "  ";
	}
	cout << "进入内存" << endl; 
	int add = 0;//替换的脚标 
	int all = 0;//总共调度了多少次 
	int  hit = 0;//命中了多少次 
	for(int i = CacheSize; i < end; i++){
		all++;
		//查找 
		int temp = search(number, number[i], CacheSize);
		//如果找到 
		if(temp){
			for(int i = 0; i < CacheSize; i++){
				cout << number[i] << "  ";
			}
			cout << "命中" << endl;
			hit++;
		}else{
			int test = number[add]; 
			number[add] = number[i];
			for(int i = 0; i < CacheSize; i++){
				cout << number[i] << "  ";
			}
			cout << test << "被调出" << endl;
			add++;
			add %= CacheSize;
			
		}
	}
	cout << "命中率:" << ( hit * 1.0 / all * 1.0 ) * 100 << "%" << endl;
}

int FIFO(){
	int CacheSize;//内存块大小 
	cout << "请输入内存块大小：";
	cin >> CacheSize;
	FIFO( CacheSize );
	return 0;
}


