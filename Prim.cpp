/*
6 10
1 2 6
1 3 1
1 4 5
2 3 5
2 5 3
3 4 4
3 5 6
3 6 4
4 6 2
5 6 6
*/
/*#include<iostream>
#include<cstdio>
#include<cmath>
#include<windows.h>
#include <graphics.h>
#include <conio.h>
#include <sstream>
using namespace std;
int px[9] = { 200,400,400,550,650,800,800,1000,1000 };
int py[9] = { 400,300,500,300,500,200,600,200,600 };
int main()
{
    initgraph(1200, 800, 1);
    int n, m, i, j, k, min, t1, t2, t3;
    int e[7][7], dis[7], book[7] = { 0 }, vis[7][7] = { 0 };
    int inf = 99999999;
    int count = 0, sum = 0;
    scanf("%d %d", &n, &m);
    for (i = 0; i < n; i++)
    {
        circle(px[i], py[i], 20);
        char str = i + '1';
        outtextxy(px[i], py[i], str);
    }
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            if (i == j)e[i][j] = 0;
            else
            {
                e[i][j] = inf;
                e[j][i] = inf;
            }
    for (i = 1; i <= m; i++)
    {
        scanf("%d %d %d", &t1, &t2, &t3);
        e[t1][t2] = t3;
        e[t2][t1] = t3;
        char str = t3 + '0';
        line(px[t1 - 1], py[t1 - 1], px[t2 - 1], py[t2 - 1]);
        outtextxy((px[t1 - 1] + px[t2 - 1]) / 2, (py[t1 - 1] + py[t2 - 1]) / 2, str);
    }
    _getch();
    for (i = 1; i <= n; i++)
    {
        dis[i] = e[1][i];
    }
    book[1] = 1;
    count++;
    setfillcolor(BROWN);
    solidcircle(px[0], py[0], 20);
    _getch();
    setlinecolor(GREEN);
    for (int u = 1; u <= n ; u++)
    {
        if (e[1][u] < inf)
        {
            line(px[0], py[0], px[u - 1], py[u - 1]);
        }
    }
    _getch();
    printf("初始未连接的dis:\n");
    for (int r = 1; r <= n ; r++)
    {
        if (book[r] != 1)
        {
            printf("点%d:%d     ", r, dis[r]);
        }
    }
    printf("\n");
    _getch();
    while (count < n)
    {
        min = inf;
        for (i = 1; i <= n; i++)
        {
            if (book[i] == 0 && dis[i] < min)
            {
                min = dis[i];
                j = i;
            }
        }
        book[j] = 1;
        setlinecolor(RED);
        for (int l = 1; l <= n; l++)
        {
            if (e[l][j] == dis[j])
            {
                line(px[j - 1], py[j - 1], px[l - 1], py[l - 1]);
                vis[l][j] = 1;
                vis[j][l] = 1;
                break;
            }
        }
        _getch();
        setfillcolor(BROWN);
        solidcircle(px[j - 1], py[j - 1], 20);
        _getch();
        setlinecolor(GREEN);
        for (int u = 1; u <= n; u++)
        {
            if (e[j][u] < inf&&vis[j][u]!=1)
            {
                line(px[j - 1], py[j - 1], px[u - 1], py[u - 1]);
            }
        }
        _getch();
        count++;
        sum = sum + dis[j];
        for (k = 1; k <= n; k++)
        {
            if (book[k] == 0 && dis[k] > e[j][k])
            {
                dis[k] = e[j][k];
            }
        }
        printf("更新未连接的dis:\n");
        for (int r = 1; r <= n; r++)
        {
            if (book[r] != 1)
            {
                printf("点%d:%d     ", r,dis[r]);
            }
        }
        printf("\n");
        _getch();
    }
    printf("%d", sum);
    _getch();
    closegraph();
    return 0;
}*/