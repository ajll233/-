#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//	定义棋盘
char board[15][15];
//	定义棋子角色
char role = '@';
//	定义棋子落子坐标
char key_x = 7, key_y = 7;

//	初始化棋盘
void init_board(void);

//	显示棋盘
void show_board(void);

//	落子
void get_key(void);

//	检查五子连珠
bool check_win(void);

int main()
{
	//初始化棋盘
	init_board();

	for (int i = 0; i < 225; i++)
	{
		//	显示棋盘
		show_board();

		//	落子
		get_key();

		//	检查是否五子连珠
		if (check_win())
		{
			show_board();
			printf("游戏结束，%c胜利!\n", role);
			return 0;
		}

		//	交换角色	
		if ('@' == role)
		{
			role = '$';
		}
		else
		{
			role = '@';
		}
	}
	//	平局
	printf("平局了，你们真无聊!\n");
	return 0;
}

void init_board(void)
{
	for (int x = 0; x < 15; x++)
	{
		for (int y = 0; y < 15; y++)
		{
			board[x][y] = '*';
		}
	}
}

//	显示棋盘
void show_board(void)
{
	//	清理屏幕
	system("clear");
	for (int x = 0; x < 15; x++)
	{
		for (int y = 0; y < 15; y++)
		{
			printf(" %c", board[x][y]);
		}
		printf("\n");
	}
}

//	落子
void get_key(void)
{
	while (true)
	{
		//	输入棋子坐标
		printf("请%c输入棋子坐标:", role);
		scanf_s("%hhd%hhd", &key_x, &key_y);

		//	检查棋子是否合法
		if (0 > key_x || 14 < key_x || 0 > key_y || 15 < key_y)
		{
			//	非法，继续重新输入	continue
			printf("坐标非法，请重新输入\n");
			continue;
		}

		//	检查是否已有棋子
		if ('*' != board[key_x][key_y])
		{
			printf("此位置已有棋子，请重新输入\n");
			continue;
		}

		//	落子
		board[key_x][key_y] = role;
		return;
	}
}

//	检查五子连珠
bool check_win(void)
{
	int cnt = 0;

	//	左右
	for (int y = key_y - 1; y >= 0; y--)
	{
		if (role == board[key_x][y])
		{
			cnt++;
		}
		else
		{
			break;
		}
	}
	for (int y = key_y + 1; y < 15; y++)
	{
		if (role == board[key_x][y])
		{
			cnt++;
		}
		else
		{
			break;
		}
	}
	if (4 <= cnt)
	{
		return true;
	}


	return false;
}