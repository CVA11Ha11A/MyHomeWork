#include <stdio.h>
#include <iostream>
#include <conio.h> // _getch ���� �ʿ��� �ش�����
#include <stdlib.h> //�������� �ʿ��� �ش�����
#include <time.h> // �����ʱ�ȭ���ʿ��� �ش�����
#include <windows.h> //Sleep�� �ʿ��� �ش�����

using namespace std;
//���� ���� �Լ� ����
//�迭�� ������ ������ �� * �� �����ʰ� ����
//Ŭ���� ���ǹ� ����
int main(void)
{
	int UserChoiceLevel = 0; //�÷��̾� ���̵� ����

	const int GROUND_Y = 7;
	const int GROUND_X = 7;

	int NumReSet = 1;
	int NumMaximum = UserChoiceLevel * UserChoiceLevel;
	int Number[GROUND_Y][GROUND_X]{ 0, }; //2�߹迭�� �Ⱦ��� �ѹ迭�� �ٳ־���Ҽ�������
	int Y = 2; //0���� ��ġ ���� ����
	int X = 2;

	cout << ("���̵��� ����\n3~6 ���ϴ� ���̵��� �Է����ּ���");
	//if (UserChoiceLevel >= 7 || UserChoiceLevel <= 2){ }  //���ǹ����� Ż���� �����ؾߵ�
	
	cin >> UserChoiceLevel;
	//cout << UserChoiceLevel; //�Է°� Ȯ��

	while (1)
	{
		//���ʵ� �����
		for (int x,y = 0; y < UserChoiceLevel; y++)
		{
			for (x = 0; x < UserChoiceLevel; x++)
			{
				Number[y][x]= NumReSet++; //�ۿ��ִ� ������ ���Ҷ� �����̸� ���ڸ� �Ѿ ��
			}
			
		} // * ����


		for (int i = 0; i < UserChoiceLevel; i++) //0�� ����
		{
			for (int j = 0; j < UserChoiceLevel; j++)
			{
				if (i == X && j == Y)
				{
					Number[i][j] = '\0'; //0�� ������ ������ ����
				}
				printf(" %d ", Number[i][j]);
			}
			printf("\n");
		}

		int Move = _getch(); //�Է¹ޱ�

		system("CLS");

		switch (Move) //�Է¹����� ���
		{
		case 'a':   //a�Է����� ���� ������ �ٽþȵ��ƿ� �����ʿ�
			Y = Y - 1;
			if (Y > UserChoiceLevel)
			{
				Y = Y +2;
			}
			break;
		case'd':
			Y = Y + 1;
			if (Y > UserChoiceLevel)
			{
				Y = Y - 2;
			}
			break;
		case'w':	//W�Է����� ���� ������ �ٽþȵ��ƿ� �����ʿ�
			X = X - 1;
			if (X > UserChoiceLevel)
			{
				X = X + 2;
			}
			break;

		case 's':
			X = X + 1;
			if (X > UserChoiceLevel)
			{
				X = X - 2;
			}
			break;
		default:
			break;
		}



	}
	return 0;
}