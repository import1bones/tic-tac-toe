#pragma once
#include<graphics.h>
#include<iostream>
#include<ctime>
#include<random>
#define player_chessman 1;
#define AI_chessman -1;
using std::default_random_engine;
//以上为包含的预处理文件
class chess
{
public:
	void game();
	void map();
	bool judge_c();
	int who_first();
	void chessman_O(int x,int y);
	void chessman_X(int x,int y);
	void player();
	void AI();
private:
	struct chessman_msg
	{
		int x;
		int y;
		int end_x = x + 100;
		int end_y = y + 100;
		int who=0;
	};
	int last;
	chessman_msg msg[3][3];
	MOUSEMSG mouse;
};

inline void chess::game()
{
	
	initgraph(600, 500);
	int times = 0;
	char who = 'n';
	map();
	int first = who_first();
	if (first == 1)
//		goto AI_first;
	while (judge_c()==true&&times<9)
	{
		if (judge_c() == true && times < 9)
		{
			player();
			times++;
			if (judge_c() == false)
			{
				who = 'p';
			}
		}
		AI_first:
		if (judge_c() == true && times < 9)
		{
			AI();
			times++;
			if (judge_c() == false)
			{
				who = 'a';
			}
		}
	}
	if (who == 'n')
	{
		fillrectangle(100, 150, 400, 350);
		outtextxy(200, 220, "draw");
		getchar();
	}
	else
	{
		if (who == 'a')
		{
			fillrectangle(100, 150, 400, 350);
			outtextxy(200, 220, "AI win");
			getchar();
		}
		if (who == 'p')
		{
			fillrectangle(100, 150, 400, 350);
			outtextxy(200, 220, "player win");
			getchar();
		}
	}
	closegraph();
}

inline void chess::map()
{
	for (int x = 0; x < 4; x++)
	{
		line(100 + (100 * x), 100, 100 + (100 * x), 400);
		for (int y = 0; y < 4; y++)
		{
			line(100, 100 + (100 * y), 400, 100 + (100 * y));
			if (x < 3 && y < 3)
			{
				msg[x][y].x = 100 + (100 * x);
				msg[x][y].y = 100 + (100 * y);
			}
		}
	}
}

inline bool chess::judge_c()
{
	bool win = false;
	for (int i = 0; i < 3; i++)
	{
		if (msg[i][0].who + msg[i][1].who + msg[i][2].who == 3 || msg[i][0].who + msg[i][1].who + msg[i][2].who == -3)
		{
			win = true;
		}
		if (msg[0][i].who + msg[1][i].who + msg[2][i].who == 3 || msg[0][i].who + msg[1][i].who + msg[2][i].who == -3)
		{
			win = true;
		}
	}
	if (msg[0][0].who + msg[1][1].who + msg[2][2].who == 3 || msg[0][0].who + msg[1][1].who + msg[2][2].who == -3)
	{
		win = true;
	}
	if (msg[0][2].who + msg[1][1].who + msg[2][0].who == 3 || msg[0][2].who + msg[1][1].who + msg[2][0].who == -3)
	{
		win = true;
	}
	if (win == false)
	{
		return true;
	}
	else
	{
		return false;
	}
}

inline int chess::who_first()
{
	int x[10];
	int mid;
	int end;
	default_random_engine x1;
	for (int i = 0; i < 10; i++)
	{
		x[i] = x1();
	}
	mid = x1();
	for (; mid >= 10;)
	{
		mid = mid % 10;
	}
	end = x[mid];
	end = unsigned(end);
	if (end%2==0)
	{
		outtextxy(450,100,"first:player");
		return 0;
	}
	else
	{
		outtextxy(450, 100, "first:AI");
		return 1;
	}
}

inline void chess::chessman_O(int x,int y)
{
	circle(x + 50, y + 50, 50);
}

inline void chess::chessman_X(int x,int y)
{
	line(x, y, x + 100, y + 100);
	line(x + 100, y, x, y + 100);
}

inline void chess::player()
{
	bool played = false;
	int mid_x, mid_y;
	start:
	while (played == false)
	{
		mouse = GetMouseMsg();
		if(mouse.x > 100 && mouse.y > 100 && mouse.x < 400 && mouse.y < 400 && mouse.mkLButton == true)
		{

			mid_x = (mouse.x - (mouse.x % 100) - 100) / 100;
			mid_y = (mouse.y - (mouse.y % 100) - 100) / 100;
			if (msg[mid_x][mid_y].who == 0)
			{
				msg[mid_x][mid_y].who = player_chessman;
				chessman_X(msg[mid_x][mid_y].x, msg[mid_x][mid_y].y);
				played = true;
				break;
			}
		}
		else
		{
			goto start;
		}
	}
}