#include<bits/stdc++.h>
using namespace std;

// ����һ����һ��ѵ�������⣬��ʱ������C���ģ�����
// �벻����Ϊʲô����...
// �ֱ���...������̫����ֱ��ģ��

string str;
long long times;
long long x, y;
int main() {
	cin >> str >> times;
	for(int i=0; i <= min((long long)str.size() - 1, times); i++) {
		if(str[i] == 'N')x++;
		if(str[i] == 'E')y++;
		if(str[i] == 'S')x--;
		if(str[i] == 'W')y--;
	}
	int bs = times / str.size();
	int ys = times % str.size();
	x *= bs, y *= bs;
	for(int i = 0; i < ys; i++) {
		if(str[i] == 'N')x++;
		if(str[i] == 'E')y++;
		if(str[i] == 'S')x--;
		if(str[i] == 'W')y--;
	}
	cout << y << " " <<x;
	return 0;
}




/*
// һƬWA��TLE...����ʱ��̫����ww
#include <stdio.h>
#include <string.h>
#define MAX_LENGTH 5000
int main() {
    // ��cookie���˽�Ķ�������Ȼ���⿴������������ְ�...
    char command[MAX_LENGTH];
    int i, n, start = 0;
    int x = 0, y = 0;
    int time;
    for (i = 0; (command[i] = getchar()) != '\n'; i++);
    scanf("%d", &time);
    for (n = 0; n < time; n++) {
        if (n < i) {
            start = n;
        } else if (n == i) {
            start = 0;
        } else {
            start = 0;
            if (start >= i) {
                start = 0;
            }
            start++;
        }
        switch (command[start]) {
            case 'E':
                x += 1;
                break;
            case 'S':
                y -= 1;
                break;
            case 'W':
                x -= 1;
                break;
            case 'N':
                y += 1;
                break;
        }

    }
    printf("%d %d", x, y);
    return 0;
}
*/
