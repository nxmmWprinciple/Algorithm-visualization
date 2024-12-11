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
/*#include<iostream>
#include<cstdio>
#include<cmath>
#include<windows.h>
#include <graphics.h>
#include <conio.h>
using namespace std;
int px[9] = { 200,400,400,550,650,800,800,1000,1000 };
int py[9] = { 400,300,500,300,500,200,600,200,600 };
int main()
{
	initgraph(1200, 800, 1);
	int e[10][10], k, i, j, n, m, t1, t2, t3;
	int inf = 99999999;
	int book[10][10] = { 0 };
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
			else e[i][j] = inf;
	int ok = 1;
	for (i = 1; i <= m; i++)
	{
		scanf("%d %d %d", &t1, &t2, &t3);
		e[t1][t2] = t3;
		book[t1][t2] = 1;
		char str = t3 + '0';
		line(px[t1 - 1], py[t1 - 1], px[t2 - 1], py[t2 - 1]);
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
		if(ok==1)
		{
		    outtextxy((px[t1 - 1] + px[t2 - 1]) / 2, (py[t1 - 1] + py[t2 - 1]) / 2, str);
			ok = 0;
		}
		else
		{
		    outtextxy((px[t1 - 1] + px[t2 - 1]) / 2, ((py[t1 - 1] + py[t2 - 1]) / 2)-20, str);
			ok = 1;
		}
	}
	_getch();
	for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= n; j++)
			{
				printf("%10d", e[i][j]);
			}
			printf("\n");
		}
		_getch();
	for (k = 1; k <= n; k++)
	{
		setfillcolor(BROWN);
		solidcircle(px[k - 1], py[k - 1], 20);
		_getch();
		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= n; j++)
			{
				if (e[i][j] >= e[i][k] + e[k][j])
				{
					e[i][j] = e[i][k] + e[k][j];
					char str = e[i][j] + '0';
					setlinecolor(RED);
					int ok = 0;
					if (e[k][j]!=inf&&k!=j&&book[k][j]==1)
					{
						line(px[j - 1], py[j - 1], px[k - 1], py[k - 1]);
						ok = 1;
					}
					if (e[i][k]!=inf&&k!=j&&book[k][j]==1)
					{
						line(px[i - 1], py[i - 1], px[k - 1], py[k - 1]);
						ok = 1;
					}
					if (ok)
					{
						_getch();
					}
					setlinecolor(WHITE);
					int okk = 0;
					if (e[k][j] != inf && k != j && book[k][j] == 1)
					{
						line(px[j - 1], py[j - 1], px[k - 1], py[k - 1]);
						okk = 1;
					}
					if (e[i][k] != inf && k != j && book[k][j] == 1)
					{
						line(px[i - 1], py[i - 1], px[k - 1], py[k - 1]);
						okk = 1;
					}
					if (okk)
					{
						_getch();
					}
				}
			}
		}
		system("cls");
		printf("更新min{各点经过%d点到达各点的距离,原距离}:\n", k);
		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= n; j++)
			{
				printf("%10d", e[i][j]);
			}
			printf("\n");
		}
		_getch();
	}
	system("cls");
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			printf("%10d", e[i][j]);
		}
		printf("\n");
	}
	_getch();
	closegraph();
	return 0;
}*/