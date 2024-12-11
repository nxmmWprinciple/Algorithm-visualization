/*
accvcvccx
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include<cmath>
#include<windows.h>
#include <graphics.h>
#include <conio.h>
using namespace std;
int y = 200, x[19] = { 100,150,200,250,300,350,400,450,500,550,600,650,700,750,800,850,900,950,1000 };
string Get_new(string& str) 
{
    string temp = "#";
    for (int i = 0; str[i]; ++i) 
    {
        (temp += str[i]) += "#";
    }
    return temp;
}
int main()
{
    initgraph(1200, 800, 1);
    string str;
    cin >> str;
    str = Get_new(str);
    int* r = (int*)calloc(sizeof(int), str.size()), c = 0, ans = 0;
    for (int i = 1; str[i]; ++i) 
    {
        for (int cur = 0; str[cur]; cur++)
        {
            outtextxy(x[cur], y, str[cur]);
        }
        setlinecolor(GREEN);
        line(x[i], y - 20, x[i], y - 120);
        setlinecolor(RED);
        line(x[c], y + 20, x[c], y + 120);
        _getch();
        cleardevice();
        setlinecolor(RED);
        line(x[c], y + 20, x[c], y + 120);
        char chh = r[c] + '0';
        outtextxy(x[c], y + 140, chh);
        for (int cur = 0; str[cur]; cur++)
        {
            outtextxy(x[cur], y, str[cur]);
        }
        setlinecolor(GREEN);
        line(x[i], y - 20, x[i], y - 120);
        if (c + r[c] > i)  
            r[i] = min(r[2 * c - i], c + r[c] - i);
        while (i - r[i] >= 0 && str[i - r[i]] == str[i + r[i]])  
            ++r[i];
        --r[i];
        setlinecolor(LIGHTBLUE);
        line(x[i - r[i]], y + 20, x[i + r[i]], y + 20);
        char ch = r[i] + '0';
        outtextxy(x[i], y - 140, ch);
        setlinecolor(LIGHTBLUE);
        line(x[c - r[c]], y + 40, x[c + r[c]], y + 40);
        if (i + r[i] > c + r[c])
        {
            c = i;   //×¢Òâ¸üÐÂCµÄÎ»ÖÃ
        }
        ans = max(ans, r[i]);
        _getch();
        cleardevice();
    }
    cout << ans << endl;
    free(r);
    _getch();
    closegraph();
    return 0;
}
