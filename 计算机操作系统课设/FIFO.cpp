#include<iostream>
#include<cstdlib>
#include<ctime>
#include<vector>
#include<queue>
#include<algorithm>
#include<windows.h> 
using namespace std;

//�������� 
int search(vector<int> number, int num, int CacheSize){
	for(int i = 0; i < CacheSize; i++){
		if(number[i] == num){
			return i;
		}
	}
	return 0;
}

//FIFO�㷨 
void FIFO( int CacheSize ){
	//����������ɵ�ַ
	srand( time(0) ); 
	vector<int> number;//�����洢�ڴ�� 
	int end = ( rand() % 11 ) + 10;
	cout << "����������ɴ洢��ַ����";
	for( int i = 0; i < end; i++){
		number.push_back(( rand() % 9 ) + 1 );
		Sleep(200);
		cout << number[i] << "  ";
	}
	cout << "(�ڴ���С" << CacheSize << ")" << endl; 
	for(int i = 0 ; i < CacheSize; i++){
		cout << number[i] << "  ";
	}
	cout << "�����ڴ�" << endl; 
	int add = 0;//�滻�Ľű� 
	int all = 0;//�ܹ������˶��ٴ� 
	int  hit = 0;//�����˶��ٴ� 
	for(int i = CacheSize; i < end; i++){
		all++;
		//���� 
		int temp = search(number, number[i], CacheSize);
		//����ҵ� 
		if(temp){
			for(int i = 0; i < CacheSize; i++){
				cout << number[i] << "  ";
			}
			cout << "����" << endl;
			hit++;
		}else{
			int test = number[add]; 
			number[add] = number[i];
			for(int i = 0; i < CacheSize; i++){
				cout << number[i] << "  ";
			}
			cout << test << "������" << endl;
			add++;
			add %= CacheSize;
			
		}
	}
	cout << "������:" << ( hit * 1.0 / all * 1.0 ) * 100 << "%" << endl;
}

int FIFO(){
	int CacheSize;//�ڴ���С 
	cout << "�������ڴ���С��";
	cin >> CacheSize;
	FIFO( CacheSize );
	return 0;
}


