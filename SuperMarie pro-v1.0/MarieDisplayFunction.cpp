﻿#include "MarieDisplayFunction.h"
#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include "Mdefine.h"
#include <stdlib.h>
#pragma comment(lib,"Winmm.lib")

    IMAGE img_preplay, img_test, img_start, img_help, img_exit, img_introduction;
	IMAGE img_help_page, img_back;
	IMAGE img_start_I, img_help_I, img_introduction_I, img_exit_I;
	IMAGE img_level1;
void GameStart()
{
	cleardevice();

////////////////////////////////////////////////////////////////////////////////////////////
															
    //是否处于当前页面
	int HOME_flag = 1; 
	int INTRODUCTION_flag = 0; 
	int HELP_flag = 0;
	int ESC_flag = 0;
	//图片资源的声明
	
////////////////////////////////////////////////////////////////////////////////////////////

	//图片的加载
	loadimage(&img_preplay, _T("res\\level_1.png"));
	loadimage(&img_start,_T("res\\开始游戏按钮.png"));
	loadimage(&img_help, _T("res\\操作说明按钮.png"));
	loadimage(&img_exit, _T("res\\退出游戏按钮.png"));
	loadimage(&img_introduction, _T("res\\游戏介绍按钮.png"));

	loadimage(&img_start_I, _T("res\\开始游戏按钮（放上）.png"));
	loadimage(&img_help_I, _T("res\\操作说明按钮（放上）.png"));
	loadimage(&img_introduction_I, _T("res\\游戏介绍按钮（放上）.png"));
	loadimage(&img_exit_I, _T("res\\退出游戏按钮（放上）.png"));

	//音乐加载
	mciSendString("open res\\背景音乐.mp3 alias music_back", NULL, 0, NULL);
	mciSendString("play music_back", NULL, 0, NULL);
	
	//图片输出
	
		putimage(0, 0, WIDTH, HIGH, &img_preplay, 0, 0);
		putimage(540, 235, &img_start);	//输出菜单界面
		putimage(540, 300, &img_help);
		putimage(540, 365, &img_introduction);
		putimage(540, 430, &img_exit);

		MOUSEMSG click;
		while (HOME_flag)
		{
			click = GetMouseMsg();
			switch (click.uMsg) //当前鼠标消息
			{
			case WM_LBUTTONDOWN: //表示鼠标左键单击响应

				//选择游戏开始
				if (click.x >= 540 && click.x <= 740 && click.y >= 235 && click.y <= 285 && HOME_flag == 1 && INTRODUCTION_flag == 0 && HELP_flag == 0) 
				{
					HOME_flag = 0;
					break; //终止循环，正式开始游戏，执行主函数中的下一个函数。
				}

				//选择游戏帮助
				else if (click.x >= 540 && click.x <= 740 && click.y >= 300 && click.y <= 350 && HOME_flag == 1 && HELP_flag == 0 && INTRODUCTION_flag == 0) 
				{
					HELP_flag = 1;
					HOME_flag = 0;
					cleardevice(); //这个函数用当前背景色清空屏幕，并将当前点移至 (0, 0)
					HelpPage(); // 调用HelpPage函数 显示 操作说明界面；
					ESC_flag = _getch(); //显示帮助界面后，随时准备获取用户的键盘输入。
				}
				
				//当按下esc键时返回上一级（->帮助<-）
				if (ESC_flag == ESC && HOME_flag == 0 && HELP_flag == 1 && INTRODUCTION_flag == 0) 
				{
					HOME_flag = 1, HELP_flag = 0, INTRODUCTION_flag = 0;
					cleardevice(); //这个函数用当前背景色清空屏幕，并将当前点移至 (0, 0)
					//重新回到主界面
					GameStart();

				}
				
				//选择 "游戏介绍"
				 if (click.x >= 540 && click.x <= 740 && click.y >= 365 && click.y <= 415 && HOME_flag == 1 && HELP_flag == 0 && INTRODUCTION_flag == 0)
				{

					INTRODUCTION_flag = 1;
					HOME_flag = 0;
					HELP_flag = 0;
					cleardevice();
					Introduction();

				    //显示介绍界面后，随时准备获取用户的键盘输入。
					ESC_flag = _getch();
				}

				 //当按下esc键时返回上一级（->介绍<-）
				if (ESC_flag == ESC && HOME_flag == 0 && HELP_flag == 0 && INTRODUCTION_flag == 1)
				{
					HOME_flag = 1, HELP_flag = 0, INTRODUCTION_flag = 0;
					cleardevice(); //这个函数用当前背景色清空屏幕，并将当前点移至 (0, 0)
					//重新回到主界面
					GameStart();
				}
				
				if (click.x >= 540 && click.x <= 740 && click.y >= 430 && click.y <= 480 && HOME_flag == 1 && HELP_flag == 0 && INTRODUCTION_flag == 0) //点击退出游戏
					exit(0);
					
			case WM_MOUSEMOVE: //检测鼠标移动（按钮效果所在）

				if (click.x >= 540 && click.x <= 740 && click.y >= 235 && click.y <= 285 && HOME_flag == 1 && INTRODUCTION_flag == 0 && HELP_flag == 0)
					putimage(540, 235, &img_start_I);
				else
					putimage(540, 235, &img_start);

				if (click.x >= 540 && click.x <= 740 && click.y >= 300 && click.y <= 350 && HOME_flag == 1 && HELP_flag == 0 && INTRODUCTION_flag == 0)
					putimage(540, 300, &img_help_I);
				else
					putimage(540, 300, &img_help);

				if (click.x >= 540 && click.x <= 740 && click.y >= 365 && click.y <= 415 && HOME_flag == 1 && HELP_flag == 0 && INTRODUCTION_flag == 0)
					putimage(540, 365, &img_introduction_I);
				else
					putimage(540, 365, &img_introduction);
				if (click.x >= 540 && click.x <= 740 && click.y >= 430 && click.y <= 480 && HOME_flag == 1 && HELP_flag == 0 && INTRODUCTION_flag == 0) 
					putimage(540, 430, &img_exit_I);
				else
					putimage(540, 430, &img_exit);

			    default:
				break;
			}
		}
		//清空绘图缓存
	FlushBatchDraw();
	Sleep(2);

	}
	

void HelpPage()
{
	IMAGE img_help_page;
	loadimage(&img_help_page, _T("res\\游戏帮助.png"));
	putimage(0, 0, &img_help_page); //输出帮助页面
}

void Introduction()
{
	IMAGE img_introduciton;
	loadimage(&img_introduciton, _T("res\\游戏介绍.png"));
	putimage(0, 0, &img_introduciton); //输出游戏介绍界面

}


void Hero_Show() //显示主角 需解决 遮罩、背景、移动残留。
{
	IMAGE Hero,Hero_mask;
	loadimage(&Hero, _T("res\\主角.png"));
	loadimage(&Hero_mask, _T("res\\主角（遮罩）"));

	putimage(0, HIGH - 120, 35, 50, &Hero_mask, 210, 80, NOTSRCERASE);
	putimage(0, HIGH - 120, 35, 50, &Hero, 210 , 80, SRCINVERT);
}

void game_show()
{
	IMAGE img_map_level1;
	int j = 0;
	loadimage(&img_map_level1, _T("res\\level_1.png"));
	putimage(0, 0, WIDTH, HIGH, &img_map_level1, 0, 0);
		
	
}

void Hero_TurnLeft()
{
	IMAGE img_Hero_TurnLeft;
}

void Hero_TurnRight()
{
	IMAGE img_Hero_TurnRight;

}

