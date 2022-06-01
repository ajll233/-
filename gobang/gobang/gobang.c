#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//	��������
char board[15][15];
//	�������ӽ�ɫ
char role = '@';
//	����������������
char key_x = 7, key_y = 7;

//	��ʼ������
void init_board(void);

//	��ʾ����
void show_board(void);

//	����
void get_key(void);

//	�����������
bool check_win(void);

int main()
{
	//��ʼ������
	init_board();

	for (int i = 0; i < 225; i++)
	{
		//	��ʾ����
		show_board();

		//	����
		get_key();

		//	����Ƿ���������
		if (check_win())
		{
			show_board();
			printf("��Ϸ������%cʤ��!\n", role);
			return 0;
		}

		//	������ɫ	
		if ('@' == role)
		{
			role = '$';
		}
		else
		{
			role = '@';
		}
	}
	//	ƽ��
	printf("ƽ���ˣ�����������!\n");
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

//	��ʾ����
void show_board(void)
{
	//	������Ļ
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

//	����
void get_key(void)
{
	while (true)
	{
		//	������������
		printf("��%c������������:", role);
		scanf_s("%hhd%hhd", &key_x, &key_y);

		//	��������Ƿ�Ϸ�
		if (0 > key_x || 14 < key_x || 0 > key_y || 15 < key_y)
		{
			//	�Ƿ���������������	continue
			printf("����Ƿ�������������\n");
			continue;
		}

		//	����Ƿ���������
		if ('*' != board[key_x][key_y])
		{
			printf("��λ���������ӣ�����������\n");
			continue;
		}

		//	����
		board[key_x][key_y] = role;
		return;
	}
}

//	�����������
bool check_win(void)
{
	int cnt = 0;

	//	����
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