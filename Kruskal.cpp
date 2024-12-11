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
int root;
struct edge
{
    int u;
    int v;
    int w;
};
struct edge e[15];
int n, m;
int fa[7] = { 0 }, suma = 0, Count = 0;
void quicksort(int left, int right)
{
    int i, j;
    struct edge t;
    if (left > right)
        return;
    i = left;
    j = right;
    while (i != j)
    {
        while (e[j].w >= e[left].w && i < j)
            j--;
        while (e[i].w <= e[left].w && i < j)
            i++;
        if (i < j)
        {
            t = e[i];
            e[i] = e[j];
            e[j] = t;
        }
    }
    t = e[left];
    e[left] = e[i];
    e[i] = t;
    quicksort(left, i - 1);
    quicksort(i + 1, right);
    return;
}
int getfa(int v)
{
    if (fa[v] == v)
        return v;
    else
    {
        fa[v] = getfa(fa[v]);
        return fa[v];
    }
}
int mergek(int u, int v)
{
    int t1, t2;
    t1 = getfa(u);
    t2 = getfa(v);
    if (t1 != t2)
    {
        root = t2;
        fa[t2] = t1;
        return 1;
    }
    return 0;
}
int main()
{
    initgraph(1200, 800, 1);
    int i;
    scanf("%d %d", &n, &m);
    for (i = 0; i < n; i++)
    {
        circle(px[i], py[i], 20);
        char str = i + '1';
        outtextxy(px[i], py[i], str);
    }
    int ok = 1;
    for (i = 1; i <= m; i++)
    {
        scanf("%d %d %d", &e[i].u, &e[i].v, &e[i].w);
        char str = e[i].w + '0';
        line(px[e[i].u - 1], py[e[i].u - 1], px[e[i].v - 1], py[e[i].v - 1]);
        if (ok == 1)
        {
            outtextxy((px[e[i].u - 1] + px[e[i].v - 1]) / 2, (py[e[i].u - 1] + py[e[i].v - 1]) / 2, str);
            ok = 0;
        }
        else
        {
            outtextxy((px[e[i].u - 1] + px[e[i].v - 1]) / 2, ((py[e[i].u - 1] + py[e[i].v - 1]) / 2) - 20, str);
            ok = 1;
        }
    }
    _getch();
    quicksort(1, m);
    for (i = 1; i <= n; i++)
    {
        fa[i] = i;
        settextcolor(LIGHTBLUE);
        char str = i + '0';
        outtextxy(px[i-1]+20, py[i-1]+20, str);
    }
    _getch();
    for (i = 1; i <= m; i++)
    {
        if (mergek(e[i].u, e[i].v))
        {
            setlinecolor(GREEN);
            line(px[e[i].u - 1], py[e[i].u - 1], px[e[i].v - 1], py[e[i].v - 1]);
            _getch();
            settextcolor(LIGHTBLUE);
            char str = getfa(e[i].u) + '0';
            for (int s = 1; s <= n; s++)
            {
                if (getfa(s) == getfa(e[i].v))
                {
                    outtextxy(px[s - 1] + 20, py[s - 1] + 20, str);
                    fa[s] = getfa(e[i].v);
                }
            }
            _getch();
            Count++;
            suma = suma + e[i].w;
        }
        if (Count == n - 1)
        {
            break;
        }
    }
    printf("%d", suma);
    _getch();
    closegraph();
    return 0;
}*/