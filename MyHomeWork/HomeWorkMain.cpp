#include <stdio.h>
#include <iostream>
#include <conio.h> // _getch 사용시 필요한 해더파일
#include <stdlib.h> //랜덤사용시 필요한 해더파일
#include <time.h> // 난수초기화의필요한 해더파일
#include <windows.h> //Sleep에 필요한 해더파일

using namespace std;
//랜덤 셔플 함수 제작
//배열이 유저가 선택한 값 * 값 넘지않게 설정
//클리어 조건문 제작
int main(void)
{
	int UserChoiceLevel = 0; //플레이어 난이도 선택

	const int GROUND_Y = 7;
	const int GROUND_X = 7;

	int NumReSet = 1;
	int NumMaximum = UserChoiceLevel * UserChoiceLevel;
	int Number[GROUND_Y][GROUND_X]{ 0, }; //2중배열이 안쓰고 한배열에 다넣어야할수도있음
	int Y = 2; //0문자 위치 지정 변수
	int X = 2;

	cout << ("난이도를 설정\n3~6 원하는 난이도를 입력해주세요");
	//if (UserChoiceLevel >= 7 || UserChoiceLevel <= 2){ }  //조건문에서 탈출기능 삽입해야됨
	
	cin >> UserChoiceLevel;
	//cout << UserChoiceLevel; //입력값 확인

	while (1)
	{
		//별필드 만들기
		for (int x,y = 0; y < UserChoiceLevel; y++)
		{
			for (x = 0; x < UserChoiceLevel; x++)
			{
				Number[y][x]= NumReSet++; //밖에있는 변수로 더할때 움직이면 숫자를 넘어서 감
			}
			
		} // * 선언


		for (int i = 0; i < UserChoiceLevel; i++) //0의 조건
		{
			for (int j = 0; j < UserChoiceLevel; j++)
			{
				if (i == X && j == Y)
				{
					Number[i][j] = '\0'; //0이 구석에 박히게 만듦
				}
				printf(" %d ", Number[i][j]);
			}
			printf("\n");
		}

		int Move = _getch(); //입력받기

		system("CLS");

		switch (Move) //입력받은값 명령
		{
		case 'a':   //a입력으로 벽을 넘을시 다시안돌아옴 수정필요
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
		case'w':	//W입력으로 벽을 넘을시 다시안돌아옴 수정필요
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