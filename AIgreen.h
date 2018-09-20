#pragma once
#include"chess.h"
void chess::AI()
{
	bool played = false;
	//下一子可赢(6)
	for (int i = 0; i < 3; i++)
	{
		if (msg[i][0].who + msg[i][1].who + msg[i][2].who == -2 && played == false)
		{
			for (int j = 0; j < 3; j++)
			{
				if (msg[i][j].who == 0)
				{
					msg[i][j].who = AI_chessman;
					chessman_O(msg[i][j].x, msg[i][j].y);
					played = true;
					break;
				}
			}
		}
		if (msg[0][i].who + msg[1][i].who + msg[2][i].who == -2 && played == false)
		{
			for (int j = 0; j < 3; j++)
			{
				if (msg[j][i].who == 0)
				{
					msg[j][i].who = AI_chessman;
					chessman_O(msg[j][i].x, msg[j][i].y);
					played = true;
					break;
				}
			}
		}
	}
	if ( msg[0][0].who + msg[1][1].who + msg[2][2].who == -2)
	{
		for (int j = 0; j < 3; j++)
		{
			if (msg[j][j].who == 0)
			{
				msg[j][j].who = AI_chessman;
				chessman_O(msg[j][j].x, msg[j][j].y);
				played = true;
				break;
			}
		}
	}
	if ( msg[0][2].who + msg[1][1].who + msg[2][0].who == -2)
	{
		for (int j = 0; j < 3; j++)
		{
			if (msg[j][2-j].who == 0)
			{
				msg[j][2-j].who = AI_chessman;
				chessman_O(msg[j][2-j].x, msg[j][2-j].y);
				played = true;
				break;
			}
		}
	}
	//不下该子会输(5)
	for (int i = 0; i < 3; i++)
	{
		if (msg[i][0].who + msg[i][1].who + msg[i][2].who == 2 && played == false)
		{
			for (int j = 0; j < 3; j++)
			{
				if (msg[i][j].who == 0)
				{
					msg[i][j].who = AI_chessman;
					chessman_O(msg[i][j].x, msg[i][j].y);
					played = true;
					break;
				}
			}
		}
		if (msg[0][i].who + msg[1][i].who + msg[2][i].who == 2 && played == false)
		{
			for (int j = 0; j < 3; j++)
			{
				if (msg[j][i].who == 0)
				{
					msg[j][i].who = AI_chessman;
					chessman_O(msg[j][i].x, msg[j][i].y);
					played = true;
					break;
				}
			}
		}
	}
	if (msg[0][0].who + msg[1][1].who + msg[2][2].who == 2 && played == false)
	{
		for (int j = 0; j < 3; j++)
		{
			if (msg[j][j].who == 0)
			{
				msg[j][j].who = AI_chessman;
				chessman_O(msg[j][j].x, msg[j][j].y);
				played = true;
				break;
			}
		}
	}
	if (msg[0][2].who + msg[1][1].who + msg[2][0].who == 2 && played == false)
	{
		for (int j = 0; j < 3; j++)
		{
			if (msg[j][2 - j].who == 0)
			{
				msg[j][2 - j].who = AI_chessman;
				chessman_O(msg[j][2 - j].x, msg[j][2 - j].y);
				played = true;
				break;
			}
		}
	}
	//优先下进攻路线多的位置(4)
	if (msg[1][1].who == 0 && played == false)
	{
		msg[1][1].who = AI_chessman;
		chessman_O(msg[1][1].x, msg[1][1].y);
		played = true;
	}
	if (msg[0][0].who == 0 && msg[0][0].who + msg[0][1].who + msg[0][2].who == 0 && msg[0][0].who + msg[1][0].who + msg[2][0].who == 0 && played == false)
	{
		msg[0][0].who = AI_chessman;
		chessman_O(msg[0][0].x, msg[0][0].y);
		played = true;
	}
	if (msg[2][0].who == 0 && msg[2][0].who + msg[2][1].who + msg[2][2].who == 0 && msg[0][0].who + msg[1][0].who + msg[2][0].who == 0 && played == false)
	{
		msg[2][0].who = AI_chessman;
		chessman_O(msg[2][0].x, msg[2][0].y);
		played = true;
	}
	if (msg[0][2].who == 0 && msg[0][0].who + msg[0][1].who + msg[0][2].who == 0 && msg[0][2].who + msg[1][2].who + msg[2][2].who == 0 && played == false)
	{
		msg[0][2].who = AI_chessman;
		chessman_O(msg[0][2].x, msg[0][2].y);
		played = true;
	}
	if (msg[2][2].who == 0 && msg[2][0].who + msg[2][1].who + msg[2][2].who == 0 && msg[0][2].who + msg[1][2].who + msg[2][2].who == 0 && played == false)
	{
		msg[2][2].who = AI_chessman;
		chessman_O(msg[2][2].x, msg[2][2].y);
		played = true;
	}
	//次选进攻路线多&&对方略势(3)
	if (msg[1][1].who == 0 && played == false)
	{
		msg[1][1].who = AI_chessman;
		chessman_O(msg[1][1].x, msg[1][1].y);
		played = true;
	}
	//次选进攻路线多&&对方略势(2)
	if (msg[0][0].who == 0 && msg[0][0].who + msg[0][1].who + msg[0][2].who == -1 && msg[0][0].who + msg[1][0].who + msg[2][0].who == 1 && played == false)
	{
		msg[0][0].who = AI_chessman;
		chessman_O(msg[0][0].x, msg[0][0].y);
		played = true;
	}
	if (msg[0][0].who == 0 && msg[0][0].who + msg[0][1].who + msg[0][2].who == 1 && msg[0][0].who + msg[1][0].who + msg[2][0].who == -1 && played == false)
	{
		msg[0][0].who = AI_chessman;
		chessman_O(msg[0][0].x, msg[0][0].y);
		played = true;
	}
	if (msg[2][0].who == 0 && msg[2][0].who + msg[2][1].who + msg[2][2].who == -1 && msg[0][0].who + msg[1][0].who + msg[2][0].who == 1 && played == false)
	{
		msg[2][0].who = AI_chessman;
		chessman_O(msg[2][0].x, msg[2][0].y);
		played = true;
	}
	if (msg[2][0].who == 0 && msg[2][0].who + msg[2][1].who + msg[2][2].who == 1 && msg[0][0].who + msg[1][0].who + msg[2][0].who == -1 && played == false)
	{
		msg[2][0].who = AI_chessman;
		chessman_O(msg[2][0].x, msg[2][0].y);
		played = true;
	}
	if (msg[0][2].who == 0 && msg[0][0].who + msg[0][1].who + msg[0][2].who == -1 && msg[0][2].who + msg[1][2].who + msg[2][2].who == 1 && played == false)
	{
		msg[0][2].who = AI_chessman;
		chessman_O(msg[0][2].x, msg[0][2].y);
		played = true;
	}
	if (msg[0][2].who == 0 && msg[0][0].who + msg[0][1].who + msg[0][2].who == 1 && msg[0][2].who + msg[1][2].who + msg[2][2].who == -1 && played == false)
	{
		msg[0][2].who = AI_chessman;
		chessman_O(msg[0][2].x, msg[0][2].y);
		played = true;
	}
	if (msg[2][2].who == 0 && msg[2][0].who + msg[2][1].who + msg[2][2].who == -1 && msg[0][2].who + msg[1][2].who + msg[2][2].who == 1 && played == false)
	{
		msg[2][2].who = AI_chessman;
		chessman_O(msg[2][2].x, msg[2][2].y);
		played = true;
	}
	if (msg[2][2].who == 0 && msg[2][0].who + msg[2][1].who + msg[2][2].who == 1 && msg[0][2].who + msg[1][2].who + msg[2][2].who == -1 && played == false)
	{
		msg[2][2].who = AI_chessman;
		chessman_O(msg[2][2].x, msg[2][2].y);
		played = true;
	}
	//单一进攻路线(1)
	if (msg[0][1].who == 0  && played == false)
	{
		msg[0][1].who = AI_chessman;
		chessman_O(msg[0][1].x, msg[0][1].y);
		played = true;
	}
	if (msg[2][1].who == 0 && played == false)
	{
		msg[2][1].who = AI_chessman;
		chessman_O(msg[2][1].x, msg[2][1].y);
		played = true;
	}
	if (msg[1][2].who == 0 && played == false)
	{
		msg[1][2].who = AI_chessman;
		chessman_O(msg[1][2].x, msg[1][2].y);
		played = true;
	}
	if (msg[2][1].who == 0 && played == false)
	{
		msg[2][1].who = AI_chessman;
		chessman_O(msg[2][1].x, msg[2][1].y);
		played = true;
	}\
	//只能平局了
	for (int i = 0; played == false && i < 5; i++)
	{
		int x = rand() % 3;
		int y = rand() % 3;
		srand(unsigned(time_t()));
		if (msg[x][y].who == 0 && played == false)
		{
			msg[x][y].who = AI_chessman;
			chessman_O(msg[x][y].x, msg[x][y].y);
			played = true;
		}
	}
	for (int x = 0; x < 3; x++)
	{
		for (int y = 0; y < 3; y++)
		{
			if (msg[x][y].who == 0 && played == false)
			{
				msg[x][y].who = AI_chessman;
				chessman_O(msg[x][y].x, msg[x][y].y);
				played = true;
			}
		}
	}
}