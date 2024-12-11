/*
6 10
1 2 2
1 3 5
2 3 1
2 4 3
3 4 3
3 5 4
3 6 1
4 5 1
4 6 4
5 6 1
*/
#include<iostream>
#include<cstdio>
#include<cmath>
#include<windows.h>
#include <graphics.h>
#include <conio.h>
using namespace std;
int px[9] = {200,400,400,550,650,800,800,1000,1000};
int py[9] = { 400,300,500,300,500,200,600,200,600 };

int main()
{
	initgraph(1200, 800, 1);
	int e[10][10], dis[10], book[10], i, j, n, m, t1, t2, t3, u, v, min;
	int inf = 99999999;
	scanf("%d %d", &n, &m);
	int x = 200, y = 200;
	for (int i = 0; i < n; i++)
	{
		circle(px[i], py[i], 20);
		char str = i + '1';
		outtextxy(px[i], py[i], str);
	}
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			if (i == j)e[i][j] = 0;
			else e[i][j] = inf;
	int ok = 1;
	for (i = 1; i <= m; i++)
	{
		scanf("%d %d %d", &t1, &t2, &t3);
		e[t1][t2] = t3;
		char str = t3 + '0';
		line(px[t1-1], py[t1-1], px[t2 -1], py[t2 -1]);
		// 计算箭头头部两条边的方向向量
		double dx = (px[t1 - 1] + px[t2 - 1]) / 2 - px[t1 - 1];
		double dy = (py[t1 - 1] + py[t2 - 1]) / 2 - py[t1 - 1];
		double length = sqrt(dx * dx + dy * dy);
		dx /= length;
		dy /= length;
		// 计算箭头头部两条边的终点坐标
		int arrowTipX1 = (px[t1 - 1] + px[t2 - 1]) / 2 + (int)(10 * (dy - dx));
		int arrowTipY1 = (py[t1 - 1] + py[t2 - 1]) / 2 - (int)(10 * (dx + dy));
		int arrowTipX2 = (px[t1 - 1] + px[t2 - 1]) / 2 - (int)(10 * (dy + dx));
		int arrowTipY2 = (py[t1 - 1] + py[t2 - 1]) / 2 - (int)(10 * (-dx + dy));
		// 绘制箭头头部
		line((px[t1 - 1] + px[t2 - 1]) / 2, (py[t1 - 1] + py[t2 - 1]) / 2, arrowTipX1, arrowTipY1);
		line((px[t1 - 1] + px[t2 - 1]) / 2, (py[t1 - 1] + py[t2 - 1]) / 2, arrowTipX2, arrowTipY2);
		settextcolor(WHITE);
		if (ok == 1)
		{
			outtextxy((px[t1 - 1] + px[t2 - 1]) / 2, (py[t1 - 1] + py[t2 - 1]) / 2, str);
			ok = 0;
		}
		else
		{
			outtextxy((px[t1 - 1] + px[t2 - 1]) / 2, ((py[t1 - 1] + py[t2 - 1]) / 2) - 20, str);
			ok = 1;
		}
		if (t1 == 1)
		{
			settextcolor(LIGHTBLUE);
			outtextxy(px[t2 - 1] + 20, py[t2 - 1] + 20, str);
		}
	}
	for (i = 1; i <= n; i++)
		dis[i] = e[1][i];
	for (i = 1; i <= n; i++)
		book[i] = 0;
	book[1] = 1;
	_getch();
	for (i = 1; i < n; i++)
	{
		min = inf;
		for (j = 1; j <= n; j++)
		{
			if (e[i][j] > 0 && e[i][j] < inf)
			{
				setlinecolor(LIGHTBLUE);
				line(px[i - 1], py[i - 1], px[j - 1], py[j - 1]);
			}
		}
		_getch();
		for (j = 1; j <= n; j++)
		{
			if (book[j] == 0 && e[i][j] <= min && e[i][j] > 0)
			{
				min = e[i][j];
				u = j;

			}
		}
		setlinecolor(RED);
		line(px[i - 1], py[i - 1], px[u - 1], py[u - 1]);
		_getch();
		book[u] = 1;
		setfillcolor(BROWN);
		solidcircle(px[u - 1], py[u - 1], 20);
		_getch();
		for (v = 1; v <= n; v++)
		{
			if (e[u][v] < inf)
			{
				if (dis[v] > dis[u] + e[u][v])
				{
					dis[v] = dis[u] + e[u][v];
					setlinecolor(RED);
					line(px[u - 1], py[u - 1], px[v - 1], py[v - 1]);
					_getch();
					char str = dis[v] + '0';
					settextcolor(LIGHTBLUE);
					outtextxy(px[v - 1] + 20, py[v - 1] + 20, str);
					_getch();
				}
			}
		}
	}
	for (i = 1; i <= n; i++)
		printf("%d ", dis[i]);
	_getch();
	closegraph();
	return 0;
}
