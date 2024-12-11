/*
5
ABABC
9
ABABABCAA
*/
/*#include<iostream>
#include<string>
#include<cstdio>
#include<cmath>
#include<windows.h>
#include <graphics.h>
#include <conio.h>
using namespace std;
const int N = 100010, M = 1000010;
int y = 200, x[9] = { 200,300,400,500,600,700,800,900,1000 }, ty = 600;
int n, m;
int Next[N];
string s, p;
void get_Next(string s, int next[])		
{
	int j = 0;
	next[0] = 0;	
	for (int i = 1; i < s.size(); i++) 
	{
		for (int h = 0; h < s.size(); h++)
		{
			outtextxy(x[h+2], y, s[h]);
		}
		char stri = i + '0';
		char strj = j + '0';
		outtextxy(x[i+2], y - 140, stri);
		outtextxy(x[j+2], y - 140, strj);
		setlinecolor(GREEN);
		line(x[j+2], y - 20, x[j+2], y - 120);
		line(x[i+2], y - 20, x[i+2], y - 120);
		_getch();
		cleardevice();
		while (j > 0 && s[i] != s[j])	
			j = next[j - 1];	
		if (s[i] == s[j])	
			j++;	
		next[i] = j;	
		cout << "next[" << i << "]=" << next[i] << endl;
		char strne = next[i] + '0';
		outtextxy(x[i+2], y +20, strne);
		for (int h = 0; h < s.size(); h++)
		{
			outtextxy(x[h + 2], y, s[h]);
		}
		char strii = i + '0';
		char strjj = j + '0';
		outtextxy(x[i + 2], y - 140, strii);
		outtextxy(x[j + 2], y - 140, strjj);
		setlinecolor(GREEN);
		line(x[j + 2], y - 20, x[j + 2], y - 120);
		line(x[i + 2], y - 20, x[i + 2], y - 120);
		_getch();
		cleardevice();
	}
}
int main()
{
	initgraph(1200, 800, 1);
	cin >> n >> p >> m >> s;
	get_Next(p, Next);
	for (int i = 0, j = 0; i < m; i++) 
	{
		for (int h = 0; h < n; h++)
		{
			outtextxy(x[h + 2], ty, p[h]);
		}
		for (int h = 0; h < m; h++)
		{
			outtextxy(x[h], y, s[h]);
		}
		setlinecolor(GREEN);
		line(x[i], y - 20, x[i], y - 120);
		line(x[j+2], ty - 20, x[j+2], ty - 120);
		_getch();
		cleardevice();
		while (j > 0 && s[i] != p[j])	
			j = Next[j - 1];
		if (s[i] == p[j])
			j++;
		if (j == n) 
		{
			cout << i - n + 1 << " ";
			j = Next[j - 1];
		}
		for (int h = 0; h < n; h++)
		{
			outtextxy(x[h + 2], ty, p[h]);
		}
		for (int h = 0; h < m; h++)
		{
			outtextxy(x[h], y, s[h]);
		}
		j--;
		setlinecolor(GREEN);
		line(x[i], y - 20, x[i], y - 120);
		line(x[j + 2], ty - 20, x[j + 2], ty - 120);
		j++;
		_getch();
		cleardevice();
	}
	_getch();
	closegraph();
	return 0;
}*/