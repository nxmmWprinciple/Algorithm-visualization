/*
5 7
1 2 3
1 4 4
1 5 2
2 3 3
3 5 1
4 3 3
4 5 1
*/
#include<iostream>
#include<cstdio>
#include<cmath>
#include<windows.h>
#include <graphics.h>
#include <conio.h>
#include <sstream>
using namespace std;
int px[9] = {200,400,400,550,650,800,800,1000,1000};
int py[9] = { 400,300,500,300,500,200,600,200,600 };
void BellmanFord()
{
	initgraph(1200, 800, 1);
	int dis[10], bak[10], i, k, n, m, u[10], v[10], w[10], check, flag;
	int inf = 99999999;
	scanf("%d %d", &n, &m);
	for (i = 0; i < n; i++)
	{
		circle(px[i], py[i], 20);
		char str = i + '1';
		outtextxy(px[i], py[i], str);
		settextcolor(LIGHTBLUE);
		outtextxy(px[i] + 20, py[i] + 20, '-');
		outtextxy(px[0] + 20, py[0] + 20, '0');
	}
	int ok = 1;
	for (i = 1; i <= m; i++)
	{
		scanf("%d %d %d", &u[i], &v[i], &w[i]);
		char str = w[i] + '0';
		line(px[u[i] - 1], py[u[i] - 1], px[v[i] - 1], py[v[i] - 1]);
		// 计算箭头头部两条边的方向向量
		double dx = (px[u[i] - 1] + px[v[i] - 1]) / 2 - px[u[i] - 1];
		double dy = (py[u[i] - 1] + py[v[i] - 1]) / 2 - py[u[i] - 1];
		double length = sqrt(dx * dx + dy * dy);
		dx /= length;
		dy /= length;
		// 计算箭头头部两条边的终点坐标
		int arrowTipX1 = (px[u[i] - 1] + px[v[i] - 1]) / 2 + (int)(10 * (dy - dx));
		int arrowTipY1 = (py[u[i] - 1] + py[v[i] - 1]) / 2 - (int)(10 * (dx + dy));
		int arrowTipX2 = (px[u[i] - 1] + px[v[i] - 1]) / 2 - (int)(10 * (dy + dx));
		int arrowTipY2 = (py[u[i] - 1] + py[v[i] - 1]) / 2 - (int)(10 * (-dx + dy));
		// 绘制箭头头部
		line((px[u[i] - 1] + px[v[i] - 1]) / 2, (py[u[i] - 1] + py[v[i] - 1]) / 2, arrowTipX1, arrowTipY1);
		line((px[u[i] - 1] + px[v[i] - 1]) / 2, (py[u[i] - 1] + py[v[i] - 1]) / 2, arrowTipX2, arrowTipY2);
		if(ok==1)
		{
		    outtextxy((px[u[i] - 1] + px[v[i] - 1]) / 2, (py[u[i] - 1] + py[v[i] - 1]) / 2, str);
			ok = 0;
		}
		else
		{
		    outtextxy((px[u[i] - 1] + px[v[i] - 1]) / 2, ((py[u[i] - 1] + py[v[i] - 1]) / 2) - 20, str);
			ok = 1;
		}
	}
	for (i = 1; i <= n; i++)
		dis[i] = inf;
	dis[1] = 0;
	_getch();
	for (k = 1; k <= n - 1; k++)
	{
		check = 0;
		for (i = 1; i <= m; i++)
		{
			setlinecolor(GREEN);
			line(px[u[i] - 1], py[u[i] - 1], px[v[i] - 1], py[v[i] - 1]);
			_getch();
			if (dis[v[i]] > dis[u[i]] + w[i])
			{
				dis[v[i]] = dis[u[i]] + w[i];
				check = 1;
				char str = dis[v[i]] + '0';
				setlinecolor(RED);
				line(px[u[i] - 1], py[u[i] - 1], px[v[i] - 1], py[v[i] - 1]);
				_getch();
				settextcolor(LIGHTBLUE);
				outtextxy( px[v[i] - 1]+20, py[v[i] - 1]+20, str);
				_getch();
			}
			else
			{
				setlinecolor(WHITE);
				line(px[u[i] - 1], py[u[i] - 1], px[v[i] - 1], py[v[i] - 1]);
				_getch();
			}
		}
		for (i = 1; i <= m; i++)
		{
			setlinecolor(WHITE);
			line(px[u[i] - 1], py[u[i] - 1], px[v[i] - 1], py[v[i] - 1]);
		}
		_getch();
		if (check == 0)break;
	}
	flag = 0;
	for (i = 1; i <= m; i++)
		if (dis[v[i]] > dis[u[i]] + w[i])flag = 1;
	if (flag == 1)
	{
		printf("此图含有负权回路");
	}
	else
	{
		for (i = 1; i <= n; i++)
			printf("%d ", dis[i]);
	}
	_getch();
	closegraph();
	return ;
}
int main()
{
	BellmanFord();
	return 0;
}
