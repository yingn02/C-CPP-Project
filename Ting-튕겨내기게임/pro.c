#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

// 색상 정의
#define BLACK	0
#define BLUE1	1
#define GREEN1	2
#define CYAN1	3
#define RED1	4
#define MAGENTA1 5
#define YELLOW1	6
#define GRAY1	7
#define GRAY2	8
#define BLUE2	9
#define GREEN2	10
#define CYAN2	11
#define RED2	12
#define MAGENTA2 13
#define YELLOW2	14
#define WHITE	15

#define STAR1 'O' // player1 표시
#define STAR2 'X' // player2 표시
#define BLANK ' ' // ' ' 로하면 흔적이 지워진다 

#define ESC 0x1b //  ESC 누르면 종료

#define SPECIAL1 0xe0 // 특수키는 0xe0 + key 값으로 구성된다.
#define SPECIAL2 0x00 // keypad 경우 0x00 + key 로 구성된다.

#define UP  0x48 // Up key는 0xe0 + 0x48 두개의 값이 들어온다.
#define DOWN 0x50
#define LEFT 0x4b
#define RIGHT 0x4d

#define UP2		'w'//player2 는 AWSD 로 방향키 대신
#define DOWN2	's'
#define LEFT2	'a'
#define RIGHT2	'd'

#define J	'j'
#define SPACE ' '

#define WIDTH 140
#define HEIGHT 70

#define TABLEWIDTH 75
#define TABLEHEIGHT 70

int Delay = 1; // 100 msec delay, 이 값을 줄이면 속도가 빨라진다.
int keep_moving = 1; // 1:계속이동, 0:한칸씩이동.
int time_out = 30; // 제한시간
int score[2] = { 0 };
int called[2];
char team1[20] = "레드팀";
char team2[20] = "블루팀";

void removeCursor(void) { // 커서를 안보이게 한다

	CONSOLE_CURSOR_INFO curInfo;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
	curInfo.bVisible = 0;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
}

void textcolor(int fg_color, int bg_color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), fg_color | bg_color << 4);
}

void gotoxy(int x, int y) //내가 원하는 위치로 커서 이동
{
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);// WIN32API 함수입니다. 이건 알필요 없어요
}

// 화면 지우기고 원하는 배경색으로 설정한다.
void cls(int bg_color, int text_color)
{
	char cmd[100];
	system("cls");
	sprintf(cmd, "COLOR %x%x", bg_color, text_color);
	system(cmd);
}

void intro(void) {
	unsigned char ch;
	int x, y;
	int len = strlen("■");

	textcolor(BLACK, WHITE);
	for (x = 0; x <= 138; x += len) {
		gotoxy(x, 0);
		printf("%s", "■");
		gotoxy(x, 68);
		printf("%s", "■");
	}
	for (y = 0; y <= 68; y++) {
		gotoxy(0, y);
		printf("%s", "■");
		gotoxy(138, y);
		printf("%s", "■");
	}

	//인트로 "탁구"
	textcolor(RED1, WHITE);
	gotoxy(10, 5);
	printf("■■■■   ■         ■■■■■■");
	gotoxy(10, 6);
	printf("■         ■                   ■");
	gotoxy(10, 7);
	printf("■■■■   ■■                 ■");
	gotoxy(10, 8);
	printf("■         ■                   ■");
	gotoxy(10, 9);
	printf("■■■■   ■                        ");
	gotoxy(10, 10);
	printf("                     ■■■■■■■ ");
	gotoxy(10, 11);
	printf("    ■■■■               ■");
	gotoxy(10, 12);
	printf("          ■               ■");
	gotoxy(10, 13);
	printf("          ■               ■");
	gotoxy(10, 14);
	printf("            ");
	gotoxy(10, 15);
	printf("            ");
	textcolor(BLUE1, WHITE);
	gotoxy(10, 17);
	printf("■■■■  ■ ■        ■■     ■");
	gotoxy(10, 18);
	printf("      ■  ■ ■      ■    ■   ■");
	gotoxy(10, 19);
	printf("      ■■■ ■      ■    ■   ■");
	gotoxy(10, 20);
	printf("      ■  ■ ■        ■■     ■");
	gotoxy(10, 21);
	printf("      ■  ■ ■           ");
	gotoxy(10, 22);
	printf("      ■  ■ ■          ■■■■");
	gotoxy(10, 23);
	printf("          ■ ■          ■    ■");
	gotoxy(10, 24);
	printf("                         ■■■■");

	textcolor(RED1, WHITE);

	//인트로 BLUE
	textcolor(BLUE2, WHITE);
	gotoxy(70, 10);
	printf("                                  ■■■■");
	textcolor(BLUE1, WHITE);
	gotoxy(70, 11);
	printf("               ■■■■■        ■■■■■");
	gotoxy(70, 12);
	printf("               ■■■■■       ■■■■■■");
	textcolor(BLUE2, WHITE);
	gotoxy(70, 13);
	printf("               ■■■■■       ■■■■■■");
	gotoxy(70, 14);
	printf("               ■■■■■       ■■■■■■");
	gotoxy(70, 15);
	printf("               ■■■■■        ■■■■■");
	gotoxy(70, 16);
	printf("                  ■■            ■■■■   ");
	gotoxy(70, 17);
	printf("                  ■■        ■■■■■■■■");
	gotoxy(70, 18);
	printf("                  ■■■  ■■■■■■■■■■■■");
	gotoxy(70, 19);
	printf("                     ■■■■■  ■■■■■■■■■■");
	gotoxy(70, 20);
	printf("                       ■■■     ■■■■■■   ■■■");
	gotoxy(70, 21);
	printf("                                  ■■■■■■    ■■■");
	gotoxy(70, 22);
	printf("                                  ■■■■■■    ■■■");
	//인트로 탁구대
	textcolor(BLUE1, WHITE);
	gotoxy(70, 23);
	printf("        □□□□□□□□□□□□□□□□□□□□□□□□□□");
	gotoxy(69, 24);
	printf("        □■■■■■■■■■■■□■■■■■■■■■■■■□");
	gotoxy(66, 25);
	printf("        □■■■■■■■■■■■□■■■■■■■■■■■■■□");
	gotoxy(65, 26);
	printf("        □■■■■■■■■■■■□■■■■■■■■■■■■■□");
	gotoxy(62, 27);
	printf("        □■■■■■■■■■■■□■■■■■■■■■■■■■■□");
	gotoxy(61, 28);
	printf("        □■■■■■■■■■■■□■■■■■■■■■■■■■■□");
	gotoxy(58, 29);
	printf("        □■■■■■■■■■■■□■■■■■■■■■■■■■■■□");
	gotoxy(57, 30);
	printf("        □■■■■■■■■■■■□■■■■■■■■■■■■■■■□");
	gotoxy(53, 31);
	printf("        □■■■■■■■■■■■□■■■■■■■■■■■■■■■■■□");
	gotoxy(52, 32);
	printf("        □■■■■■■■■■■■□■■■■■■■■■■■■■■■■■□");
	gotoxy(47, 33);
	printf("        □□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□");
	gotoxy(46, 34);
	printf("        □■■■■■■■■■■■■■□■■■■■■■■■■■■■■■■■□");
	gotoxy(42, 35);
	printf("        □■■■■■■■■■■■■■■□■■■■■■■■■■■■■■■■■■□");
	gotoxy(41, 36);
	printf("        □■■■■■■■■■■■■■■□■■■■■■■■■■■■■■■■■■□");
	gotoxy(37, 37);
	printf("        □■■■■■■■■■■■■■■■□■■■■■■■■■■■■■■■■■■□");
	gotoxy(36, 38);
	printf("        □■■■■■■■■■■■■■■□■■■■■■■■■■■■■■■■■■■□");
	gotoxy(31, 39);
	printf("        □■■■■■■■■■■■■■■■□■■■■■■■■■■■■■■■■■■■■□");
	gotoxy(30, 40);
	printf("        □■■■■■■■■■■■■■■■□■■■■■■■■■■■■■■■■■■■■□");
	gotoxy(25, 41);
	printf("        □■■■■■■■■■■■■■■■■■□■■■■■■■■■■■■■■■■■■■■□");
	gotoxy(24, 42);
	printf("        □■■■■■■■■■■■■■■■■□■■■■■■■■■■■■■■■■■■■■■□");
	gotoxy(20, 43);
	printf("        □■■■■■■■■■■■■■■■■■□■■■■■■■■■■■■■■■■■■■■■■□");
	gotoxy(19, 44);
	printf("        □■■■■■■■■■■■■■■■■■□■■■■■■■■■■■■■■■■■■■■■■□");
	gotoxy(14, 45);
	printf("        □■■■■■■■■■■■■■■■■■■□■■■■■■■■■■■■■■■■■■■■■■■□");
	gotoxy(13, 46);
	printf("        □■■■■■■■■■■■■■■■■■■□■■■■■■■■■■■■■■■■■■■■■■■□");
	gotoxy(8, 47);
	printf("        □■■■■■■■■■■■■■■■■■■■□■■■■■■■■■■■■■■■■■■■■■■■■□");
	gotoxy(7, 48);
	printf("        □■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■□");
	gotoxy(3, 49);
	printf("        □■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■□");
	gotoxy(2, 50);
	printf("        □□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□");



	//인트로 RED
	textcolor(RED2, WHITE);
	gotoxy(40, 38);
	printf("■■■■■■");
	gotoxy(39, 39);
	printf("■■■■■■■");
	textcolor(RED1, WHITE);
	gotoxy(38, 40);
	printf("■■■■■■■■");
	gotoxy(37, 41); 
	printf("■■■■■■■■■");
	gotoxy(37, 42);
	printf("■■■■■■■■■");
	textcolor(RED2, WHITE);
	gotoxy(37, 43);
	printf("■■■■■■■■■");
	gotoxy(38, 44);
	printf("■■■■■■■■");
	gotoxy(39, 45);
	printf("■■■■■■■");
	gotoxy(40, 46);
	printf("■■■■■■");
	gotoxy(39, 47);
	printf("■■■■■■■");
	gotoxy(30, 48);
	printf("■■■■■■■■■■■■■■■■■");
	gotoxy(24, 49);
	printf("■■■■■■■■■■■■■■■■■■■■");
	gotoxy(24, 50);
	printf("■■■■■■■■■■■■■■■■■■■■■");
	gotoxy(20, 51);
	printf("■■■■■■■■■■■■■■■■■■■■■■■■   ■■■■");
	gotoxy(20, 52);
	printf("■■■■■■■■■■■■■■■■■■    ■■■■■■■■■");
	gotoxy(20, 53);
	printf("■■■■  ■■■■■■■■■■■■■    ■■■■■■■■ ");
	gotoxy(18, 54);
	printf("■■■■■  ■■■■■■■■■■■■      ■■■■■■");
	gotoxy(16, 55);
	printf("■■■■■   ■■■■■■■■■■■■         ■■■■ ");
	gotoxy(15, 56);
	printf("  ■■■■    ■■■■■■■■■■■■      ");
	gotoxy(15, 57);
	printf("  ■■■■    ■■■■■■■■■■■■      ");
	gotoxy(15, 57);
	printf("  ■■■■    ■■■■■■■■■■■■      ");
	gotoxy(15, 58);
	printf("  ■■■■    ■■■■■■■■■■■■     ");
	gotoxy(15, 59);
	printf("  ■■■■   ■■■■■■■■■■■■      ");
	gotoxy(15, 60);
	printf("  ■■■■   ■■■■■■■■■■■■     ");
	gotoxy(15, 61);
	printf("  ■■■■■  ■■■■■■■■■■■■      ");
	gotoxy(15, 62);
	printf("  ■■■■■  ■■■■■■■■■■■■     ");
	gotoxy(15, 63);
	printf("  ■■■■    ■■■■■■■■■■■■     ");

	//인트로 탁구채
	textcolor(BLUE1, WHITE);
	gotoxy(85, 11);
	printf("■■■■■");
	gotoxy(85, 12);
	printf("■■■■■");
	gotoxy(85, 13);
	printf("■■■■■");
	gotoxy(85, 14);
	printf("■■■■■");
	textcolor(YELLOW1, WHITE);
	gotoxy(85, 15);
	printf("■■■■■");
	gotoxy(88, 16);
	printf("■■");
	gotoxy(88, 17);
	printf("■■");

	textcolor(RED1, WHITE);
	gotoxy(73, 44);
	printf("■■■■■");
	gotoxy(73, 45);
	printf("■■■■■");
	gotoxy(73, 46);
	printf("■■■■■");
	gotoxy(73, 47);
	printf("■■■■■");
	textcolor(YELLOW1, WHITE);
	gotoxy(73, 48);
	printf("■■■■■");
	gotoxy(76, 49);
	printf("■■");
	gotoxy(76, 50);
	printf("■■");

	//인트로 공
	textcolor(YELLOW1, WHITE);
	gotoxy(70, 20);
	printf("■■");
	gotoxy(70, 21);
	printf("■■");

	//인트로 네트
	textcolor(GRAY2, WHITE);
	gotoxy(56, 30);
	printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");
	gotoxy(56, 31);
	printf("■");
	gotoxy(56, 32);
	printf("■");
	gotoxy(122, 31);
	printf("■");
	gotoxy(122, 32);
	printf("■");


	while (1) { // 스페이스 바를 누르면 게임시작
		if (_kbhit()) {
			ch = _getch();
			if (ch == SPACE) {
				for (int i = 0; i < 5; i++) {
					textcolor(BLACK, WHITE);
					gotoxy(52, 64);
					printf("                                     ");
					gotoxy(52, 65);
					printf("  시작하려면 스페이스 바를 누르세요  ");
					gotoxy(52, 66);
					printf("                                     ");
					Sleep(70);
					textcolor(WHITE, BLACK);
					gotoxy(52, 64);
					printf("                                     ");
					gotoxy(52, 65);
					printf("  시작하려면 스페이스 바를 누르세요  ");
					gotoxy(52, 66);
					printf("                                     ");
					Sleep(70);
				}
				textcolor(WHITE, BLACK);
				gotoxy(52, 64);
				printf("                                     ");
				gotoxy(52, 65);
				printf("  시작하려면 스페이스 바를 누르세요  ");
				gotoxy(52, 66);
				printf("                                     ");
				Sleep(1000);
				break;
			}
				
		}
		else {
			textcolor(BLACK, WHITE);
			gotoxy(52, 64);
			printf("                                     ");
			gotoxy(52, 65);
			printf("  시작하려면 스페이스 바를 누르세요  ");
			gotoxy(52, 66);
			printf("                                     ");
			Sleep(500);
			textcolor(WHITE, BLACK);
			gotoxy(52, 64);
			printf("                                     ");
			gotoxy(52, 65);
			printf("  시작하려면 스페이스 바를 누르세요  ");
			gotoxy(52, 66);
			printf("                                     ");
			Sleep(500);
		}
	}
}

void putplayer1(int x, int y) {
	gotoxy(x, y); 
	textcolor(RED1, WHITE);
	printf("■■■■■\n");
	gotoxy(x, y+1);
	printf("■■■■■\n");
	gotoxy(x, y+2);
	printf("■■■■■\n");
	gotoxy(x, y+3);
	printf("■■■■■\n");
	textcolor(YELLOW1, WHITE);
	gotoxy(x, y+4);
	printf("■■■■■\n");
	gotoxy(x, y+5);
	printf("   ■■\n");
	gotoxy(x, y+6);
	printf("   ■■\n");
	textcolor(WHITE, WHITE);
}

void putplayer2(int x, int y) {
	gotoxy(x, y);
	textcolor(BLUE1, WHITE);
	printf("■■■■■\n");
	gotoxy(x, y + 1);
	printf("■■■■■\n");
	gotoxy(x, y + 2);
	printf("■■■■■\n");
	gotoxy(x, y + 3);
	printf("■■■■■\n");
	textcolor(YELLOW1, WHITE);
	gotoxy(x, y + 4);
	printf("■■■■■\n");
	gotoxy(x, y + 5);
	printf("   ■■\n");
	gotoxy(x, y + 6);
	printf("   ■■\n");
	textcolor(WHITE, WHITE);
}

void eraseplayer(int x, int y) {
	gotoxy(x, y);
	printf("            ");
	gotoxy(x, y+1);
	printf("            ");
	gotoxy(x, y+2);
	printf("            ");
	gotoxy(x, y+3);
	printf("            ");
	gotoxy(x, y+4);
	printf("            ");
	gotoxy(x, y+5);
	printf("            ");
	gotoxy(x, y+6);
	printf("            ");
	gotoxy(x, y+7);
	printf("            ");
}

void puttable(int x, int y) {
	int i;
	gotoxy(x, y);
	textcolor(BLUE1, WHITE);
	printf("□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□\n");
	for (i = 1; i < 22; i++) {
		gotoxy(x, y + i);
		printf("□■■■■■■■■■■■■■■■■■│■■■■■■■■■■■■■■■■■□\n");

	}
	gotoxy(x - 1, y + i);
	textcolor(GRAY2, WHITE);
	printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
	textcolor(BLUE1, WHITE);
	for (i = 1; i < 22; i++) {
		gotoxy(x, y + i + 22);
		printf("□■■■■■■■■■■■■■■■■■│■■■■■■■■■■■■■■■■■□\n");

	}
	gotoxy(x, y + i + 22);
	printf("□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□\n");
	textcolor(WHITE, WHITE);
}

void putball(int x, int y, int speed) {
	if(speed == 0)
		textcolor(RED2, WHITE);
	else
		textcolor(YELLOW1, WHITE);
	gotoxy(x, y);
	printf("■■");
	gotoxy(x, y+1);
	printf("■■");
}

void eraseball(int x, int y) {
	gotoxy(x, y);
	printf("    ");
	gotoxy(x, y + 1);
	printf("    ");
}

void hline(int x) {
	for (int i = 0; i < HEIGHT; i++) {
		gotoxy(x, i);
		textcolor(BLACK, WHITE);
		printf("┃");
	}
}

void putscore1(int x, int y, int score) {
	int i;
	textcolor(RED1, WHITE);
	gotoxy(x, y);
	printf("┏━━━━━━━━━━┓");
	for (i = 1; i <= 9; i++) {
		gotoxy(x, y + i);
		printf("┃                    ┃");
	}
	gotoxy(x, y + 10);
	printf("┗━━━━━━━━━━┛");
	if (score == 0) {
		gotoxy(x + 9, y + 3);
		printf("■■■");
		gotoxy(x + 8, y + 4);
		printf("■    ■");
		gotoxy(x + 8, y + 5);
		printf("■    ■");
		gotoxy(x + 8, y + 6);
		printf("■    ■");
		gotoxy(x + 9, y + 7);
		printf("■■■");
	}
	else if (score == 1) {
		gotoxy(x + 8, y + 3);
		printf("   ■");
		gotoxy(x + 8, y + 4);
		printf("   ■");
		gotoxy(x + 8, y + 5);
		printf("   ■");
		gotoxy(x + 8, y + 6);
		printf("   ■ ");
		gotoxy(x + 8, y + 7);
		printf("   ■ ");
	}
	else if (score == 2) {
		gotoxy(x + 8, y + 3);
		printf("■■■■");
		gotoxy(x + 8, y + 4);
		printf("      ■");
		gotoxy(x + 8, y + 5);
		printf("■■■■");
		gotoxy(x + 8, y + 6);
		printf("■  ");
		gotoxy(x + 8, y + 7);
		printf("■■■■");
	}
	else if (score == 3) {
		gotoxy(x + 8, y + 3);
		printf("■■■■");
		gotoxy(x + 7, y + 4);
		printf("       ■");
		gotoxy(x + 7, y + 5);
		printf(" ■■■■");
		gotoxy(x + 7, y + 6);
		printf("       ■");
		gotoxy(x + 8, y + 7);
		printf("■■■■");
	}
	else if (score == 4) {
		gotoxy(x + 8, y + 3);
		printf("■    ■");
		gotoxy(x + 7, y + 4);
		printf(" ■    ■");
		gotoxy(x + 7, y + 5);
		printf(" ■■■■");
		gotoxy(x + 7, y + 6);
		printf("       ■");
		gotoxy(x + 8, y + 7);
		printf("      ■");
	}
	else if (score == 5) {
		gotoxy(x + 8, y + 3);
		printf("■■■■");
		gotoxy(x + 8, y + 4);
		printf("■");
		gotoxy(x + 8, y + 5);
		printf("■■■■");
		gotoxy(x + 8, y + 6);
		printf("      ■");
		gotoxy(x + 8, y + 7);
		printf("■■■■");
	}
	else if (score == 6) {
		gotoxy(x + 8, y + 3);
		printf("■■■■");
		gotoxy(x + 8, y + 4);
		printf("■");
		gotoxy(x + 8, y + 5);
		printf("■■■■");
		gotoxy(x + 8, y + 6);
		printf("■    ■");
		gotoxy(x + 8, y + 7);
		printf("■■■■");
	}
	else if (score == 7) {
		gotoxy(x + 8, y + 3);
		printf("■■■■");
		gotoxy(x + 8, y + 4);
		printf("■    ■");
		gotoxy(x + 8, y + 5);
		printf("■    ■");
		gotoxy(x + 8, y + 6);
		printf("      ■");
		gotoxy(x + 8, y + 7);
		printf("      ■");
	}
	else if (score == 8) {
		gotoxy(x + 8, y + 3);
		printf("■■■■");
		gotoxy(x + 8, y + 4);
		printf("■    ■");
		gotoxy(x + 8, y + 5);
		printf("■■■■");
		gotoxy(x + 8, y + 6);
		printf("■    ■");
		gotoxy(x + 8, y + 7);
		printf("■■■■");
	}
	else if (score == 9) {
		gotoxy(x + 8, y + 3);
		printf("■■■■");
		gotoxy(x + 8, y + 4);
		printf("■    ■");
		gotoxy(x + 8, y + 5);
		printf("■■■■");
		gotoxy(x + 8, y + 6);
		printf("      ■");
		gotoxy(x + 8, y + 7);
		printf("■■■■");
	}
	if (score == 10) {
		gotoxy(x + 6, y + 3);
		printf("■    ■■■");
		gotoxy(x + 6, y + 4);
		printf("■   ■    ■");
		gotoxy(x + 6, y + 5);
		printf("■   ■    ■");
		gotoxy(x + 6, y + 6);
		printf("■   ■    ■");
		gotoxy(x + 6, y + 7);
		printf("■    ■■■");
	}
	if (score == 11) {
		gotoxy(x + 6, y + 3);
		printf("■        ■");
		gotoxy(x + 6, y + 4);
		printf("■        ■");
		gotoxy(x + 6, y + 5);
		printf("■        ■");
		gotoxy(x + 6, y + 6);
		printf("■        ■");
		gotoxy(x + 6, y + 7);
		printf("■        ■");
	}
}

void putscore2(int x, int y, int score) {
	int i;
	textcolor(BLUE1, WHITE);
	gotoxy(x, y);
	printf("┏━━━━━━━━━━┓");
	for (i = 1; i <= 9; i++) {
		gotoxy(x, y + i);
		printf("┃                    ┃");
	}
	gotoxy(x, y + 10);
	printf("┗━━━━━━━━━━┛");
	if (score == 0) {
		gotoxy(x + 9, y + 3);
		printf("■■■");
		gotoxy(x + 8, y + 4);
		printf("■    ■");
		gotoxy(x + 8, y + 5);
		printf("■    ■");
		gotoxy(x + 8, y + 6);
		printf("■    ■");
		gotoxy(x + 9, y + 7);
		printf("■■■");
	}
	else if (score == 1) {
		gotoxy(x + 8, y + 3);
		printf("   ■");
		gotoxy(x + 8, y + 4);
		printf("   ■");
		gotoxy(x + 8, y + 5);
		printf("   ■");
		gotoxy(x + 8, y + 6);
		printf("   ■ ");
		gotoxy(x + 8, y + 7);
		printf("   ■ ");
	}
	else if (score == 2) {
		gotoxy(x + 8, y + 3);
		printf("■■■■");
		gotoxy(x + 8, y + 4);
		printf("      ■");
		gotoxy(x + 8, y + 5);
		printf("■■■■");
		gotoxy(x + 8, y + 6);
		printf("■  ");
		gotoxy(x + 8, y + 7);
		printf("■■■■");
	}
	else if (score == 3) {
		gotoxy(x + 8, y + 3);
		printf("■■■■");
		gotoxy(x + 7, y + 4);
		printf("       ■");
		gotoxy(x + 7, y + 5);
		printf(" ■■■■");
		gotoxy(x + 7, y + 6);
		printf("       ■");
		gotoxy(x + 8, y + 7);
		printf("■■■■");
	}
	else if (score == 4) {
		gotoxy(x + 8, y + 3);
		printf("■    ■");
		gotoxy(x + 7, y + 4);
		printf(" ■    ■");
		gotoxy(x + 7, y + 5);
		printf(" ■■■■");
		gotoxy(x + 7, y + 6);
		printf("       ■");
		gotoxy(x + 8, y + 7);
		printf("      ■");
	}
	else if (score == 5) {
		gotoxy(x + 8, y + 3);
		printf("■■■■");
		gotoxy(x + 8, y + 4);
		printf("■");
		gotoxy(x + 8, y + 5);
		printf("■■■■");
		gotoxy(x + 8, y + 6);
		printf("      ■");
		gotoxy(x + 8, y + 7);
		printf("■■■■");
	}
	else if (score == 6) {
		gotoxy(x + 8, y + 3);
		printf("■■■■");
		gotoxy(x + 8, y + 4);
		printf("■");
		gotoxy(x + 8, y + 5);
		printf("■■■■");
		gotoxy(x + 8, y + 6);
		printf("■    ■");
		gotoxy(x + 8, y + 7);
		printf("■■■■");
	}
	else if (score == 7) {
		gotoxy(x + 8, y + 3);
		printf("■■■■");
		gotoxy(x + 8, y + 4);
		printf("■    ■");
		gotoxy(x + 8, y + 5);
		printf("■    ■");
		gotoxy(x + 8, y + 6);
		printf("      ■");
		gotoxy(x + 8, y + 7);
		printf("      ■");
	}
	else if (score == 8) {
		gotoxy(x + 8, y + 3);
		printf("■■■■");
		gotoxy(x + 8, y + 4);
		printf("■    ■");
		gotoxy(x + 8, y + 5);
		printf("■■■■");
		gotoxy(x + 8, y + 6);
		printf("■    ■");
		gotoxy(x + 8, y + 7);
		printf("■■■■");
	}
	else if (score == 9) {
		gotoxy(x + 8, y + 3);
		printf("■■■■");
		gotoxy(x + 8, y + 4);
		printf("■    ■");
		gotoxy(x + 8, y + 5);
		printf("■■■■");
		gotoxy(x + 8, y + 6);
		printf("      ■");
		gotoxy(x + 8, y + 7);
		printf("■■■■");
	}
	if (score == 10) {
		gotoxy(x + 6, y + 3);
		printf("■    ■■■");
		gotoxy(x + 6, y + 4);
		printf("■   ■    ■");
		gotoxy(x + 6, y + 5);
		printf("■   ■    ■");
		gotoxy(x + 6, y + 6);
		printf("■   ■    ■");
		gotoxy(x + 6, y + 7);
		printf("■    ■■■");
	}
	if (score == 11) {
		gotoxy(x + 6, y + 3);
		printf("■        ■");
		gotoxy(x + 6, y + 4);
		printf("■        ■");
		gotoxy(x + 6, y + 5);
		printf("■        ■");
		gotoxy(x + 6, y + 6);
		printf("■        ■");
		gotoxy(x + 6, y + 7);
		printf("■        ■");
	}
}

void erasescore(int x, int y) {
	gotoxy(x + 9, y + 3);
	printf("          ");
	gotoxy(x + 8, y + 4);
	printf("          ");
	gotoxy(x + 8, y + 5);
	printf("          ");
	gotoxy(x + 8, y + 6);
	printf("          ");
	gotoxy(x + 9, y + 7);
	printf("          ");
}

void player1(unsigned char ch, int *p1x, int *p1y) {
	static int oldx = 60, oldy = 60, newx = 60, newy = 60;
	int move_flag = 0;
	static unsigned char last_ch = 0;

	if (called[0] == 0) { // 처음 또는 Restart
		oldx = 60, oldy = 60, newx = 60, newy = 60;
		putplayer1(oldx, oldy);
		called[0] = 1;
		last_ch = 0;
		ch = 0;
	}
	if (keep_moving && ch == 0)
		ch = last_ch;
	last_ch = ch;

	switch (ch) {
	case LEFT:
		if (oldx > 0)
			newx = oldx - 1;
		else {
			newx = oldx + 1;
			last_ch = RIGHT;
		}
		move_flag = 1;
		break;
	case RIGHT:
		if (oldx < TABLEWIDTH - 1)
			newx = oldx + 1;
		else {
			newx = oldx - 1;
			last_ch = LEFT;
		}
		move_flag = 1;
		break;
	}
	if (move_flag) {
		*p1x = oldx;
		*p1y = oldy;
		eraseplayer(oldx, oldy); // 마지막 위치의 * 를 지우고
		putplayer1(newx, newy); // 새로운 위치에서 * 를 표시한다.
		oldx = newx; // 마지막 위치를 기억한다.
		oldy = newy;
	}
}

void player2(unsigned char ch, int *p2x, int *p2y) {
	static int oldx = 15, oldy = 3, newx = 15, newy = 3;
	int move_flag = 0;
	static char last_ch = 0;

	if (called[1] == 0) { // 처음 또는 Restart
		oldx = 15, oldy = 3, newx = 15, newy = 3;
		putplayer2(oldx, oldy);
		called[1] = 1;
		last_ch = 0;
		ch = 0;
	}
	// 방향키가 눌려지지 않은 경우 예전에 이동하던 방향으로 계속 이동
	if (keep_moving && ch == 0)
		ch = last_ch;
	last_ch = ch;

	switch (ch) {
	case LEFT2:
		if (oldx > 0)
			newx = oldx - 1;
		else {
			newx = oldx + 1;
			last_ch = RIGHT2;
		}
		move_flag = 1;
		break;
	case RIGHT2:
		if (oldx < TABLEWIDTH - 1)
			newx = oldx + 1;
		else {
			newx = oldx - 1;
			last_ch = LEFT2;
		}
		move_flag = 1;
		break;
	}
	if (move_flag) {
		*p2x = oldx;
		*p2y = oldy;
		eraseplayer(oldx, oldy); // 마지막 위치의 # 를 지우고
		putplayer2(newx, newy); // 새로운 위치에서 # 를 표시한다.
		oldx = newx; // 마지막 위치를 기억한다.
		oldy = newy;
		move_flag = 1; // 1:계속 이동, 0:한칸씩 이동
	}
}

void teamname(void) {
	textcolor(RED1, WHITE);
	gotoxy(58, 20);
	printf("레드팀의 이름을 적어주세요");
	gotoxy(58, 22);
	scanf("%s", team1);
	textcolor(BLUE1, WHITE);
	gotoxy(58, 30);
	printf("블루팀의 이름을 적어주세요");
	gotoxy(58, 32);
	scanf("%s", team2);
}

//게임 초기화, 처음 시작과 Restar때 호출
void init_game() {
	int x, y, i, j;
	char cmd[100];

	keep_moving = 1;
	Delay = 1;

	cls(WHITE, BLACK);
	removeCursor();
	sprintf(cmd, "mode con cols=%d lines=%d", WIDTH, HEIGHT);
	system(cmd);

	for (i = 0; i < WIDTH; i++) {
		for (j = 0; j < HEIGHT; j++) {
			gotoxy(i, j);
			printf(" ");
		}
	}
}

void main() {//////////////////////////////////////////////////////////////////////main
	unsigned char ch;
	int p1x, p1y, p2x, p2y;
	int sv, nball_x, nball_y, oball_x, oball_y;
	int goal_x, goal_y, ballmove, spike, speed;
	int win, score1, score2;

	//인트로
	intro();

	// 화면 비우기
	textcolor(WHITE, WHITE);
	for (int i = 0; i < WIDTH; i++) {
		for (int j = 0; j < HEIGHT; j++) {
			gotoxy(i, j);
			printf(" ");
		}
	}

	//팀명을 적으시오
	teamname();

START: //경기를 처음부터 다시 할 경우
	p1x = 60, p1y = 60, p2x = 15, p2y = 3;
	sv = 0, nball_x = 0, nball_y = 0, oball_x = 0, oball_y = 0;
	goal_x = 0, goal_y = 0, ballmove = 1, spike = 1, speed = 5;
	win = 0, score1 = 0, score2 = 0;

	init_game();

	puttable(5, 12); //탁구대 설치

	putplayer1(p1x, p1y); //플레이어 배치
	putplayer2(p2x, p2y);

	hline(95);//구분선 그리기

	putscore1(105, 38, score1); //점수판 배치
	putscore2(105, 20, score2);
	textcolor(BLACK, WHITE);
	gotoxy(110, 34);
	printf("■          ■");
	gotoxy(106, 50);
	printf("%s", team1);	//팀명 1
	gotoxy(106, 18);
	printf("%s", team2);	//팀명 2

	srand(time(NULL));	
	sv = 1 + rand() % 2; //랜덤 서브, 1이면 player1 2면 player2

SET: //경기 세팅, 점수가 났을 경우 또 불러온다
	spike = 1;
	if (win == 1) sv == 1;
	else if (win == 2) sv == 2;

	if (sv == 1) {
		nball_x = p1x - 10, nball_y = p1y + 2;
		oball_x = p1x - 10, oball_y = p1y + 2;
		goal_x = 0, goal_y = 0;
	}
	else if (sv == 2) {
		nball_x = p2x + 16, nball_y = p2y + 3;
		oball_x = p2x + 16, oball_y = p2y + 3;
		goal_x = 0, goal_y = 68;
	}
	putball(oball_x, oball_y, speed); //공 배치

	goal_x = 5 + rand() % TABLEWIDTH - 5; //랜덤으로 공이 향하는 좌표의 x값 정함

	gotoxy(107, 10);
	textcolor(BLACK, WHITE);
	printf("J 를 누르면 서브합니다");

	while (1) { // 서브 대기
		ch = _getch();
		if (ch == J) {
			gotoxy(107, 10);
			textcolor(WHITE, WHITE);
			printf("J 를 누르면 서브합니다");
			break;
		}
	}

	//경기 시작
	while (1) {
		//탁구대
		puttable(5, 12);
		//공

		if (sv == 1) {
			goal_y = 0;
			if (oball_y > goal_y) { //y축
				nball_y = oball_y - 1;
				ballmove = 1;
			}
			if (oball_x > goal_x) { //x축
				nball_x = oball_x - 1;
				ballmove = 1;
			}
			else if(oball_x < goal_x) {
				nball_x = oball_x + 1;
				ballmove = 1;
			}

			if (oball_y == goal_y) { //못받아치면
				eraseball(nball_x, nball_y);
				eraseball(oball_x, oball_y);
				score1++;
				erasescore(105, 38);
				erasescore(105, 20);
				putscore1(105, 38, score1); //점수판
				putscore2(105, 20, score2);
				Sleep(3000);
				win == 1;
				if (score1 == 11 || score2 == 11) //11점 도달
					break;
				goto SET;
			}
			else if (p2y <= oball_y && oball_y <= p2y + 7) {
				if (p2x <= oball_x && oball_x <= p2x + 7) {// 받아치면
					spike = rand() % 11;
				    goal_x = 5 + rand() % TABLEWIDTH - 5; //랜덤으로 공이 향하는 좌표의 x값 정함
					goal_y = 0;
					sv = 2;
				}
			}
		}
		else if (sv == 2) {
			goal_y = 68;
			if (oball_y < goal_y) { //y축
				nball_y = oball_y + 1;
				ballmove = 1;
			}
			if (oball_x > goal_x) { //x축
				nball_x = oball_x - 1;
				ballmove = 1;
			}
			else if (oball_x < goal_x) {
				nball_x = oball_x + 1;
				ballmove = 1;
			}

			if (oball_y == goal_y) { //못받아치면
				eraseball(nball_x, nball_y);
				eraseball(oball_x, oball_y);
				score2++;
				erasescore(105, 38);
				erasescore(105, 20);
				putscore1(105, 38, score1); //점수판
				putscore2(105, 20, score2);
				Sleep(3000);
				win == 2;
				if (score1 == 11 || score2 == 11) //11점 도달
					break;
				goto SET;
			}
			else if (p1y <= oball_y && oball_y <= p1y + 7) {
				if (p1x <= oball_x && oball_x <= p1x + 7) {// 받아치면
					spike = rand() % 11;
				    goal_x = 5 + rand() % TABLEWIDTH - 5; //랜덤으로 공이 향하는 좌표의 x값 정함
					goal_y = 0;
					sv = 1;
				}
			}
		}
		if (spike == 0) speed = 0;
		else speed = 5;
		if (ballmove) {
			eraseball(oball_x, oball_y); // 마지막 위치의 # 를 지우고
			putball(nball_x, nball_y, speed); // 새로운 위치에서 # 를 표시한다.
			oball_x = nball_x; // 마지막 위치를 기억한다.
			oball_y = nball_y;
			ballmove = 1; // 1:계속 이동, 0:한칸씩 이동
			Sleep(speed); // 10%의 확률로 스파이크, 플레이어와 공의 속도가 빨라짐
		}


		if (_kbhit() == 1) {  // 키보드가 눌려져 있으면
			ch = _getch(); // key 값을 읽는다
			// ESC 누르면 프로그램 종료
			if (ch == ESC) {
				break;
			}
			if (ch == SPECIAL1 || ch == SPECIAL2) { // 만약 특수키
				// 예를 들어 UP key의 경우 0xe0 0x48 두개의 문자가 들어온다.
				ch = _getch();
				// Player1은 방향키로 움직인다.
				switch (ch) {
				case LEFT:
				case RIGHT:
					player1(ch, &p1x, &p1y);//player1만 방향 전환
					player2(0, &p2x, &p2y);
					break;
				default: // 방향 전환이 아니면
					player1(0, &p1x, &p1y);
					player2(0, &p2x, &p2y);
				}
			}
			else {
				// Player2은 AWSD 로 움직인다.
				switch (ch) {
				case LEFT2:
				case RIGHT2://player2만 방향 전환
					player2(ch, &p2x, &p2y);
					player1(0, &p1x, &p1y);
					break;
				default:// 방향 전환이 아니면
					player1(0, &p1x, &p1y);
					player2(0, &p2x, &p2y);
				}
			}
		}
		else {
			// keyboard 가 눌려지지 않으면 계속 움직인다.
			// 이동중이던 방향으로 계속 이동
			player1(0, &p1x, &p1y);
			player2(0, &p2x, &p2y);
		}
		Sleep(1);
	}

	while (1) {
		int c1, c2;
		do { // 색 변경
			c1 = rand() % 16;
			c2 = rand() % 16;
		} while (c1 == c2);
		textcolor(c1, c2);
		gotoxy(30, 9);
		printf("                                                                               ");
		gotoxy(30, 10);
		printf("       ■■■■    ■   ■■■■    ■     ■■■■■     ■■■■■■         ");
		gotoxy(30, 11);
		printf("             ■  ■■         ■    ■         ■                   ■         ");
		gotoxy(30, 12);
		printf("             ■    ■         ■    ■      ■    ■      ■■■■■■         ");
		gotoxy(30, 13);
		printf("             ■  ■■         ■    ■    ■   ■   ■    ■                   ");
		gotoxy(30, 14);
		printf("                   ■         ■    ■   ■■■■■■■   ■■■■■■         ");
		gotoxy(30, 15);
		printf("              ■■■          ■    ■                       ■   ■           ");
		gotoxy(30, 16);
		printf("             ■    ■               ■       ■■■          ■   ■           ");
		gotoxy(30, 17);
		printf("             ■    ■                      ■      ■        ■   ■           ");
		gotoxy(30, 18);
		printf("              ■■■                         ■■■      ■■■■■■■        ");
		gotoxy(30, 19);
		printf("                                                                               ");
		

		textcolor(WHITE, BLACK);
		gotoxy(27, 22);
		printf("                                                                                    ");
		gotoxy(27, 23);
		printf("    ■■■■  ■  ■       ■      ■    ■■■■   ■              ■■■■■      ");
		gotoxy(27, 24);
		printf("       ■     ■  ■     ■  ■    ■       ■      ■              ■        ■    ");
		gotoxy(27, 25); 
		printf("     ■  ■   ■  ■    ■    ■   ■     ■  ■    ■■     ■     ■        ■    ");
		gotoxy(27, 26);
		printf("    ■    ■  ■■■    ■    ■   ■    ■    ■   ■              ■■■■■      ");
		gotoxy(27, 27);
		printf("    ■    ■  ■  ■    ■    ■   ■               ■              ■       ■     ");
		gotoxy(27, 28);
		printf("              ■  ■               ■       ■■■■         ■     ■        ■    ");
		gotoxy(27, 29);
		printf("                                                  ■                ■        ■    ");
		gotoxy(27, 30);  
		printf("                                                  ■                ■        ■    ");
		gotoxy(27, 31); 
		printf("                                                                                    ");


		gotoxy(27, 34);
		printf("                                                                                    ");
		gotoxy(27, 35);
		printf("               ■■■■■         ■■■■■                         ■■■■■     ");
		gotoxy(27, 36);
		printf("                   ■                     ■                        ■        ■    ");
		gotoxy(27, 37);
		printf("                ■    ■          ■■■■■                 ■     ■        ■    ");
		gotoxy(27, 38);
		printf("              ■   ■   ■        ■                                ■        ■    ");
		gotoxy(27, 39);
		printf("             ■■■■■■■       ■■■■■                        ■        ■    ");
		gotoxy(27, 40);
		printf("                 ■■■             ■  ■                   ■     ■     ■ ■    ");
		gotoxy(27, 41);
		printf("               ■      ■           ■  ■                           ■■■■■     ");
		gotoxy(27, 42);
		printf("                 ■■■          ■■■■■■                                  ■   ");
		gotoxy(27, 43);
		printf("                                                                                    ");
		 

		Sleep(300);
		if (_kbhit()) {
			ch = _getch();
			if (ch == 'r' || ch == 'q')
				break;
		}
	}
	if (ch == 'r')
		goto START;
	gotoxy(0, HEIGHT - 1);
}
