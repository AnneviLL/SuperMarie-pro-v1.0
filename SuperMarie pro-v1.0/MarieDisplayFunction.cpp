#include "MarieDisplayFunction.h"
#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include "Mdefine.h"
#pragma comment(lib,"Winmm.lib")

void menu_show()
{
	int i=0;
	char play[] = _T("Play Now!");
	IMAGE img_preplay;
	initgraph(WIDTH, HIGH);
	loadimage(&img_preplay, _T("res\\level_1.png"));
	mciSendString("open res\\背景音乐.mp3 alias music_back", NULL, 0, NULL);
	mciSendString("play music_back", NULL, 0, NULL);
	
	
	putimage(0, 0, WIDTH, HIGH, &img_preplay, 0, 0);
	setbkmode(TRANSPARENT);
	settextcolor(BLACK);
	settextstyle(50, 0, _T("黑体"));
	outtextxy(WIDTH*0.4, HIGH*0.4, "进入游戏");
	outtextxy(WIDTH*0.4, HIGH*0.4, "设置");
		
	FlushBatchDraw();
	Sleep(2);

	_getch();
	closegraph();
}