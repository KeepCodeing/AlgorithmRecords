#include<bits/stdc++.h>
using namespace std;

// 又是一道第一次训练赛的题，那时候还是用C做的，而且
// 想不明白为什么错了...
// 又爆了...，数据太大不能直接模拟

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
// 一片WA和TLE...，那时候太年轻ww
#include <stdio.h>
#include <string.h>
#define MAX_LENGTH 5000
int main() {
    // 从cookie☆了解的东方，不然这题看起来或许会很奇怪罢...
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
