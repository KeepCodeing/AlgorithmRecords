#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include<process.h>
#include<Windows.h>
#include <unistd.h>//read,write������ͷ�ļ� 
#include <sys/stat.h>//mkdir,mode����ͷ�ļ� 


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

int LoginPage();//��½ҳ��
void menu();//���˵�
void menu2();//�����˵�
int search(int id);//��ѯ�˺�
void reg();//ע���˺�
void design1();//����ϵͳ 1
void design2();//����ϵͳ 2
void revision();//�޸�����
void exam(int q);//����ģ��
void timec();//���Ե���ʱ
void examgrade();//���鿴�ɼ�
void CreateFolder(char *name);

//����ѧ��Ȼ������ļ���
//�����ļ���


int main() {

	int s = 0;
	for (s = 0; s < 200; s++) {
		char name[200];
		int radix = 10;
		itoa(s, name, radix); //�������ű���ַ���
		CreateFolder(name);//���ú���
	}

	int i, t = 0;
a:
	menu();
	printf("\n\n*��������ѡ��Ĺ��ܣ�");
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
			printf("\a\a\n          *�������ѡ��������������� :)\n\n");//\a�������ʱ����������ʾ��
			system("pause");
			goto a;
	}
	while (1) {
		system("CLS");
		menu2();
b:
		printf("\n\n*��������ѡ��Ĺ��ܣ�");
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
				printf("\a\a\n*�������ѡ��������������� :)\n\n");
				system("pause");
				goto b;
		}
	}
}
void CreateFolder(char *name) {
    char sysTem[200];
	strcpy(sysTem, "mkdir ");
//	strcat(name, "C:\\Users\\����\\Desktop\\����ѧ��");
//	strcat(name, "\\");
	strcat(sysTem, "����ѧ��");
	strcat(sysTem, name);
	system(sysTem);


}


void menu() { //���˵�
	printf("\n          ************************����ϵͳ*************************\n");
	printf("          *    1.�˺�ע��                      2.�˺ŵ�½         *\n");
	printf("          *********************************************************\n");
}

void menu2() { //�����˵�
	printf("\n          *************************�˵�****************************\n");
	printf("          *    1.��Ҫ����                      2.��ѯ�ɼ�         *\n");
	printf("          *    3.�ɼ�����                      4.�޸�����         *\n");
	printf("          *                      0.�˳�ϵͳ                       *\n");
	printf("          *********************************************************\n");
	printf("\n*%s ͬѧ���ã���ӭ��½������ϵͳ :)  ���ĵ�½IDΪ��%d\n", user.name, user.ID);
}

void reg() { //ע���˺�
	char key[20];
	int t;
	printf("\n          ************************ע��ҳ��*************************\n");
	printf("          *����������name:  ");
	scanf("%s", allUser[n].name);
	printf("          *\n");
	printf("          *����������password:  ");
	scanf("%s", allUser[n].password);
	do {
		printf("          *���ٴ���������password:  ");
		scanf("%s", key);
		if (strcmp(key, allUser[n].password) == 0) //�Ƚ����������Ƿ���ȷ �������ַ�������
			t = 0;
		else {
			t = 1;
			printf("          *������������������������ :) \n");
		}
	} while (t == 1);
	printf("          *\n");
	printf("          *ע��ɹ���\n");
	allUser[n].ID = n + 1000;
	printf("          *\n");
	printf("          *����ID: %d\n", allUser[n].ID);
	system("pause"); //��ͣ������
	n++;
}

int LoginPage() { //��½ҳ��
	int t;
	char key[20];
	printf("\n          ************************��½ҳ��*************************\n");//չʾ��ͷ
	printf("          *����������ID:  ");
	scanf("%d", &user.ID);
	getchar();//����ID
	printf("          *\n");
	t = search(user.ID);
	if (!t) { //tδ���ҵ���Ӧ���
		printf("          *��������˺�δע�ᣬ��ע���˺ź��ٴ�ʹ�ñ����� :) \n");
		return 0;//return 0��ʾ���ؼ�ֵ����������벻�������Ҫ��
	}
	do {
		printf("          *����������password:  ");
		scanf("%s", key);
		if (strcmp(key, user.password) == 0) //ͬ�ϵ����ַ��������Ƚ�password�Ƿ���ȷ
			t = 0;
		else {
			t = 1;
			printf("          *������������������������ :) \n");
		}
	} while (t == 1);
	return 1;//return 1��ʾ�����ִ�У�����Ҫ��
}

int search(int id) { //��ѯ�˺�
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

void design1() { //����ϵͳ 1
	int q;
	FILE *fp1, *fp2;
	for (q = 0; q < 100; q++) {
//�򿪿����ļ���
		char str[100], filename[100];
		char filepath[] = "Users\\����\\Desktop\\����ѧ��";
		int radix = 10;
		itoa(q, str, radix);//�ѿ����ļ��б��ת���ַ���
		strcpy(filename, filepath);
		strcat(filename, str);
		fp1 = fopen(filename, "w");

//���Ծ�
		fp2 = fopen("Users\\����\\Desktop\\���\\���1.txt", "r");

//�߶���д
		for (; !feof(fp2);) {
			char ch;
			ch = fgetc(fp2);
			fputc(ch, fp1);
		}
	}
}

void design2() { //����ϵͳ 2
//�����Ծ�


	int q;
	FILE *fp1, *fp2;
	for (q = 0; q < 100; q++) {
//�򿪿����ļ���
		char filepath[] = "Users\\����\\Desktop\\����ѧ��";
		char str[100], filename[100];
		int radix = 10;
		itoa(q, str, radix);//�ѿ����ļ��б��ת���ַ���
		strcpy(filename, filepath);
		strcat(filename, str);
		fp1 = fopen(filename, "w");

//���Ծ�
		char filepath2[] = "Users\\����\\Desktop\\���\\���1.txt";
		char filename2[100];
//itoa(q, str, radix);�����Ϊ�����Ѿ�ת���ˣ����Կ���ֱ����str��Ϊi���ַ���
		strcpy(filename2, filepath2);
		strcat(filename2, str);
		fp2 = fopen(filename2, "w");

//�߶���д
		for (; !feof(fp2);) {
			char ch;
			ch = fgetc(fp2);
			fputc(ch, fp1);
		}
	}
}

void exam(int q) { //����ģ��
	char num[10];
	int radix = 10;
	itoa(q, num, radix);
	char filename[100];
	char temp[] = ".txt";
	//���Ծ�
	char path[] = "Users\\����\\Desktop\\����ѧ��\\";
	strcpy(filename, path);
	strcat(filename, num);
	strcat(filename, temp);
	FILE *fp1;
	fp1 = fopen(filename, "r");
//����
	char ans_path[] = "Users\\����\\Desktop\\��\\" ;
	char ans_filename[100];
	strcpy(ans_filename, ans_path);
	strcat(ans_filename, num);
	strcat(ans_filename, temp);
	FILE *fp2;
	fp2 = fopen(ans_filename, "r");
//����
	while (1) {
		//����һ��
		char ch;
		while ((ch = fgetc(fp1)) != '\n') {
			putchar(ch);
		}
		putchar('\n');
		//��������һ��Ĵ𰸣�ѡ���жϣ�
		char ans;
		scanf("%c", &ans);
		//����һ��Ĵ�
		char answer;
		answer = fgetc(fp2);
		//��������𰸣���̣�
		scanf("%s", &ans);
		//������Ŀ��
		char answer1[100];
		fgets(answer1, 99, fp2) ;
		//�ľ�
		if (ans == answer) {
			printf("\n����ȷ\n");
		} else {
			printf("\n����ȷ\n");
		}
		if (feof(fp1)) {
			break;
		}
	}
}

void timec() {
	printf("���뵹��ʱʱ��\n");
	int hour = 0, min = 0, sec = 0;
	scanf("%d:%d:%d", &hour, &min, &sec);
	if (hour > 24 || hour < 0 || min > 60 || min < 0 || sec > 60 || sec < 0) {
		printf("�������\n");
		return;
	}
	printf("��ʼ����ʱ\n");
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

void examgrade() { //���鿴�ɼ�
	int i, t = 0;
	printf("\n  �ο���Ա  ��ȷ����  �������  ��ȷ��\n");
	for (i = 0; i < b; i++) {
		if (grade[i].id != user.ID)
			continue;
		t++;
		printf("%d. %6s  %6d  %6d   %.2f%%\n", t, grade[i].name, grade[i].t, grade[i].f, grade[i].gra);
	}
	printf("\n\n  ***�������������п��Գɼ���������ת����ҳ�� :) ***\n\n");
	system("pause");
}

void revision() { //�޸�����
	char key[20], ch;
	int t, i;
	do {
		printf("\n*�����������ڵ����룺");
		gets(key);
		if (strcmp(key, user.password) == 0)
			t = 0;
		else {
			t = 1;
			printf("*������������������������ :) \n");
			printf("\n*�Ƿ�����޸����� Y/N :");
			ch = getchar();
			getchar();
			if (ch == 'N' || ch == 'n') {
				printf("*�������ص��˵�ҳ�� :)\n\n");
				system("pause");
				return;
			}
		}
	} while (t == 1);
	printf("*���������������룺");
	gets(user.password);
	for (i = 0; i < n; i++)
		if (allUser[i].ID == user.ID)
			break;
	if (i < n)
		strcpy(allUser[i].password, user.password);//�ַ�����������������ʹ����IDƥ��
	printf("�޸ĳɹ����������ص��˵�ҳ�� :)\n\n");
	system("pause");
}


