#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include<process.h>
#include<Windows.h>
#include <unistd.h>//read,write函数的头文件 
#include <sys/stat.h>//mkdir,mode类型头文件 


typedef struct Grade {
	int id;
	char name[20];
	int t;
	int f;
	float gra;
} Gra;

typedef struct User {
	int ID;
	char name[20];
	char password[20];
} Use;

Use allUser[1000];
Use user;
Gra grade[1000];
int n = 0, a = 0, b = 0;

int LoginPage();//登陆页面
void menu();//主菜单
void menu2();//二级菜单
int search(int id);//查询账号
void reg();//注册账号
void design1();//出题系统 1
void design2();//出题系统 2
void revision();//修改密码
void exam(int q);//考试模块
void timec();//考试倒计时
void examgrade();//考查看成绩
void CreateFolder(char *name);

//创建学号然后带入文件名
//创建文件夹


int main() {

	int s = 0;
	for (s = 0; s < 200; s++) {
		char name[200];
		int radix = 10;
		itoa(s, name, radix); //考生考号变成字符型
		CreateFolder(name);//调用函数
	}

	int i, t = 0;
a:
	menu();
	printf("\n\n*请输入您选择的功能：");
	scanf("%d", &i);
	system("CLS");
	switch (i) {
		case 1:
			reg();
			system("CLS");
			goto a;
			break;
		case 2:
			t = LoginPage();
			if (t == 0)
				goto a;
			break;
		default:
			printf("\a\a\n          *您输入的选项错误请重新输入 :)\n\n");//\a命令错误时发出错误提示音
			system("pause");
			goto a;
	}
	while (1) {
		system("CLS");
		menu2();
b:
		printf("\n\n*请输入您选择的功能：");
		scanf("%d", &i);
		getchar();
		system("CLS");
		switch (i) {
			case 1:
				exam(user.ID);
				break;
			case 2:
				examgrade();
				break;
			case 3:
				revision();
				break;
			case 4:
				design1();
				break;
			case 5:
				design2();
				break;
			default:
				printf("\a\a\n*您输入的选项错误请重新输入 :)\n\n");
				system("pause");
				goto b;
		}
	}
}
void CreateFolder(char *name) {
    char sysTem[200];
	strcpy(sysTem, "mkdir ");
//	strcat(name, "C:\\Users\\张三\\Desktop\\考生学号");
//	strcat(name, "\\");
	strcat(sysTem, "考生学号");
	strcat(sysTem, name);
	system(sysTem);


}


void menu() { //主菜单
	printf("\n          ************************考试系统*************************\n");
	printf("          *    1.账号注册                      2.账号登陆         *\n");
	printf("          *********************************************************\n");
}

void menu2() { //二级菜单
	printf("\n          *************************菜单****************************\n");
	printf("          *    1.我要考试                      2.查询成绩         *\n");
	printf("          *    3.成绩排名                      4.修改密码         *\n");
	printf("          *                      0.退出系统                       *\n");
	printf("          *********************************************************\n");
	printf("\n*%s 同学您好，欢迎登陆本答题系统 :)  您的登陆ID为：%d\n", user.name, user.ID);
}

void reg() { //注册账号
	char key[20];
	int t;
	printf("\n          ************************注册页面*************************\n");
	printf("          *请输入您的name:  ");
	scanf("%s", allUser[n].name);
	printf("          *\n");
	printf("          *请输入您的password:  ");
	scanf("%s", allUser[n].password);
	do {
		printf("          *请再次输入您的password:  ");
		scanf("%s", key);
		if (strcmp(key, allUser[n].password) == 0) //比较输入密码是否正确 ，调用字符串函数
			t = 0;
		else {
			t = 1;
			printf("          *您输入的密码错误，请重新输入 :) \n");
		}
	} while (t == 1);
	printf("          *\n");
	printf("          *注册成功！\n");
	allUser[n].ID = n + 1000;
	printf("          *\n");
	printf("          *您的ID: %d\n", allUser[n].ID);
	system("pause"); //暂停检查输出
	n++;
}

int LoginPage() { //登陆页面
	int t;
	char key[20];
	printf("\n          ************************登陆页面*************************\n");//展示题头
	printf("          *请输入您的ID:  ");
	scanf("%d", &user.ID);
	getchar();//读入ID
	printf("          *\n");
	t = search(user.ID);
	if (!t) { //t未查找到对应结果
		printf("          *您输入的账号未注册，请注册账号后再次使用本程序 :) \n");
		return 0;//return 0表示返回假值，结果或输入不满足程序要求
	}
	do {
		printf("          *请输入您的password:  ");
		scanf("%s", key);
		if (strcmp(key, user.password) == 0) //同上调用字符串函数比较password是否正确
			t = 0;
		else {
			t = 1;
			printf("          *您输入的密码错误，请重新输入 :) \n");
		}
	} while (t == 1);
	return 1;//return 1表示程序可执行，满足要求
}

int search(int id) { //查询账号
	int i;
	for (i = 0; i < n; i++)
		if (allUser[i].ID == id)
			break;
	if (i == n)
		return 0;
	else {
		user = allUser[i];
		return 1;
	}
}

void design1() { //出题系统 1
	int q;
	FILE *fp1, *fp2;
	for (q = 0; q < 100; q++) {
//打开考生文件夹
		char str[100], filename[100];
		char filepath[] = "Users\\张三\\Desktop\\考生学号";
		int radix = 10;
		itoa(q, str, radix);//把考生文件夹编号转成字符串
		strcpy(filename, filepath);
		strcat(filename, str);
		fp1 = fopen(filename, "w");

//打开试卷
		fp2 = fopen("Users\\张三\\Desktop\\题库\\题库1.txt", "r");

//边读边写
		for (; !feof(fp2);) {
			char ch;
			ch = fgetc(fp2);
			fputc(ch, fp1);
		}
	}
}

void design2() { //出题系统 2
//分配试卷


	int q;
	FILE *fp1, *fp2;
	for (q = 0; q < 100; q++) {
//打开考生文件夹
		char filepath[] = "Users\\张三\\Desktop\\考生学号";
		char str[100], filename[100];
		int radix = 10;
		itoa(q, str, radix);//把考生文件夹编号转成字符串
		strcpy(filename, filepath);
		strcat(filename, str);
		fp1 = fopen(filename, "w");

//打开试卷
		char filepath2[] = "Users\\张三\\Desktop\\题库\\题库1.txt";
		char filename2[100];
//itoa(q, str, radix);这个因为上面已经转过了，所以可以直接用str作为i的字符串
		strcpy(filename2, filepath2);
		strcat(filename2, str);
		fp2 = fopen(filename2, "w");

//边读边写
		for (; !feof(fp2);) {
			char ch;
			ch = fgetc(fp2);
			fputc(ch, fp1);
		}
	}
}

void exam(int q) { //考试模块
	char num[10];
	int radix = 10;
	itoa(q, num, radix);
	char filename[100];
	char temp[] = ".txt";
	//读试卷
	char path[] = "Users\\张三\\Desktop\\考生学号\\";
	strcpy(filename, path);
	strcat(filename, num);
	strcat(filename, temp);
	FILE *fp1;
	fp1 = fopen(filename, "r");
//读答案
	char ans_path[] = "Users\\张三\\Desktop\\答案\\" ;
	char ans_filename[100];
	strcpy(ans_filename, ans_path);
	strcat(ans_filename, num);
	strcat(ans_filename, temp);
	FILE *fp2;
	fp2 = fopen(ans_filename, "r");
//评判
	while (1) {
		//读入一题
		char ch;
		while ((ch = fgetc(fp1)) != '\n') {
			putchar(ch);
		}
		putchar('\n');
		//考生输入一题的答案（选择判断）
		char ans;
		scanf("%c", &ans);
		//读入一题的答案
		char answer;
		answer = fgetc(fp2);
		//考生输入答案（编程）
		scanf("%s", &ans);
		//读入题目答案
		char answer1[100];
		fgets(answer1, 99, fp2) ;
		//改卷
		if (ans == answer) {
			printf("\n答案正确\n");
		} else {
			printf("\n答案正确\n");
		}
		if (feof(fp1)) {
			break;
		}
	}
}

void timec() {
	printf("输入倒计时时间\n");
	int hour = 0, min = 0, sec = 0;
	scanf("%d:%d:%d", &hour, &min, &sec);
	if (hour > 24 || hour < 0 || min > 60 || min < 0 || sec > 60 || sec < 0) {
		printf("输入错误\n");
		return;
	}
	printf("开始倒计时\n");
	int i, j, k;
	for (i = hour; i >= 0; i--) {
		for (j = min; j >= 0; j--) {
			for (k = sec; k >= 0; k--) {
				printf("\r%2d:%2d:%2d", i, j, k);
				Sleep(1000);
			}
			sec = 59;
		}
		min = 59;
	}
}

void examgrade() { //考查看成绩
	int i, t = 0;
	printf("\n  参考人员  正确个数  错误个数  正确率\n");
	for (i = 0; i < b; i++) {
		if (grade[i].id != user.ID)
			continue;
		t++;
		printf("%d. %6s  %6d  %6d   %.2f%%\n", t, grade[i].name, grade[i].t, grade[i].f, grade[i].gra);
	}
	printf("\n\n  ***以上是您的所有考试成绩，即将跳转回主页面 :) ***\n\n");
	system("pause");
}

void revision() { //修改密码
	char key[20], ch;
	int t, i;
	do {
		printf("\n*请输入您现在的密码：");
		gets(key);
		if (strcmp(key, user.password) == 0)
			t = 0;
		else {
			t = 1;
			printf("*您输入的密码错误，请重新输入 :) \n");
			printf("\n*是否继续修改密码 Y/N :");
			ch = getchar();
			getchar();
			if (ch == 'N' || ch == 'n') {
				printf("*即将返回到菜单页面 :)\n\n");
				system("pause");
				return;
			}
		}
	} while (t == 1);
	printf("*请输入您的新密码：");
	gets(user.password);
	for (i = 0; i < n; i++)
		if (allUser[i].ID == user.ID)
			break;
	if (i < n)
		strcpy(allUser[i].password, user.password);//字符串函数将新密码与使用者ID匹配
	printf("修改成功，即将返回到菜单页面 :)\n\n");
	system("pause");
}


